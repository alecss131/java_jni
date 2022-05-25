public class HelloWorld {
    static {
        System.loadLibrary("HelloWorld");
    }
    public static void main(String[] args) {
        new HelloWorld().run();
    }

    private void run() {
        print();
        int a = 2, b = 3;
        System.out.printf("%d + %d = %d\n", a, b, sum(a, b));
        System.out.println(getLine("Print string: "));
    }

    private native void print();
    private native int sum(int a, int b);
    private native String getLine(String promt);
}