package vm;

public class MainTest {
    public static void main(String[] args){
        Memory m = new VirtMemory();
        m.startup();
        m.write(0x8000, Byte.parseByte("-1")); //write it to somewhere way beyond 16K
        m.shutdown();
        m = new VirtMemory();
        m.startup();
        byte data = m.read(0x8000);
        m.shutdown();
        System.out.println(data);
    }
}