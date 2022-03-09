package utils;

import framework.MyMapReduce;
import framework.PartitionTable;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.Queue;
import java.util.*;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.ExecutorService;

class map_thread implements Runnable{
    String tid;
    String reduce_thread_id;
    Queue<String> files_to_run;
    MyMapReduce m = new MyMapReduce();
    ThreadManager t;
    public void set_tid(String id){
        tid = id;
        m.map_thread_id = tid;
    }
    public void set_files(String[] TEXT){
        for(String t: TEXT){
            files_to_run.add(t);
        }
    }
    public void run() {
        try {
            int rtid = Integer.parseInt(reduce_thread_id.substring(1));
            t.barrier.await();
            while (files_to_run.isEmpty() == false){
                String file = files_to_run.remove();
                m.map(file);
            }
            t.barrier.await();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
class reduce_thread implements Runnable{
    String tid;
    MyMapReduce m = new MyMapReduce();
    ThreadManager t;
    public void set_tid(String id){
        tid = id;
        m.reduce_thread_id = tid;
    }
    public void run() {
        String sub = tid.substring(1,tid.length());
        int thread_number = Integer.parseInt(sub);
        BoundedBuffer b = t.ListOfBoundedBuffers.get(thread_number);
        m.file_num = 0;
        try {
            t.barrier.await();
            PartitionTable pt = t.ListOfBoundedBuffers.get(thread_number).fetch();
            while(pt != null){
                while (pt.head != null){
                    m.reduce(pt.head.key,pt.indexOf(pt.head.key));
                    pt.head = pt.head.next;
                }
                pt = t.ListOfBoundedBuffers.get(thread_number).fetch();
            }
            t.barrier.await();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

    }
}
public class ThreadManager {
    public static ArrayList<String> file_text = new ArrayList<String>();
    public int mapT, redT;
    public static ExecutorService pool;
    public CyclicBarrier barrier;
    public ArrayList<BoundedBuffer<PartitionTable>> ListOfBoundedBuffers = new ArrayList<BoundedBuffer<PartitionTable>>();
    public KVS output;
    public ArrayList<map_thread> MAP_THREADS = new ArrayList<map_thread>();
    public ArrayList<reduce_thread> REDUCE_THREADS = new ArrayList<reduce_thread>();
    public ThreadManager(int mapthreads, int reducethreads){
        mapT = mapthreads;
        redT = reducethreads;
        for(int i = 0; i < redT; i++){
            //One PartitionTable for file, BoundedBuffer will be size of total files
            BoundedBuffer<PartitionTable> P = new BoundedBuffer<PartitionTable>(MAP_THREADS.get(i).files_to_run.size());
            ListOfBoundedBuffers.add(P);
        }
    }
    public static void gather_files() {
        File f = new File("D:/res");
        String[] pathnames = f.list();
        try{
            for (String pathname : pathnames) {
                file_text.add(pathname);
            }
        } catch(Exception e) {}

    }
//    java -cp /Downloads.jar
    public void assign(){
        int n = file_text.size() / mapT;
        int startAt = 0;
        for(int i = 0; i < redT; i++){
            reduce_thread t = new reduce_thread();
            t.set_tid("R"+String.valueOf(i));
            REDUCE_THREADS.add(t);
        }
        if(mapT >= file_text.size()){
            n=1;
        }
        try {
            int incrementor = (mapT/redT)+1;
            for (int i = 0; i < mapT; i++) {
                map_thread t = new map_thread();
                t.set_tid("M"+String.valueOf(i));
                while (startAt < n){
                    t.files_to_run.add(file_text.get(startAt));
                    startAt++;
                }
                if(redT == 1){
                    t.reduce_thread_id = "R1";
                }else if(redT == mapT){
                    t.reduce_thread_id = "R"+String.valueOf(i);
                }else if(mapT > redT && redT > 1){
                    int inc = (i / incrementor)+1;
                    if(inc < redT){
                        t.reduce_thread_id = "R"+String.valueOf(inc);
                    }else{
                        t.reduce_thread_id = "R"+String.valueOf(redT);
                    }
                }
                MAP_THREADS.add(t);
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args){

    }
}
