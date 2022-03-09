package framework;

import java.util.ArrayList;

public class BoundedNodeList {
    ArrayList<BoundedNode> BB = new ArrayList<BoundedNode>();
    int size(){
        return BB.size();
    }
    BoundedNode get(int index){
        return BB.get(index);
    }
    void set(BoundedNode b, int index){
        BB.set(index,b);
    }
    int used(){
        int c = 0;
        for(int i = 0; i < BB.size(); i++){
            if(BB.get(i).dirty){
                c++;
            }
        }
        return c;
    }
    int first_free(){
        int c = 0;
        for(BoundedNode B : BB){
            if(B.dirty == false){
                return c;
            }
            c++;
        }
        return -1;
    }
    void add(BoundedNode bn){
        BB.add(bn);
    }
    void insert(BoundedNode bn, int i){
        BB.add(i,bn);
    }
}
