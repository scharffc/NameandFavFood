package framework;
import java.util.concurrent.locks.AbstractQueuedSynchronizer;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class BoundedNode <T>{

    boolean dirty;
    T data;
    boolean isDirty(){
        return dirty;
    }
}