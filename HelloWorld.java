import java.util.Random;
import java.util.Arrays;

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
        int arr[] = new int[10];
        Random rnd = new Random();
        for (int i = 0; i < 10; i++) {
            arr[i] = rnd.nextInt(100);
        }
        System.out.println(Arrays.toString(arr));
        arr = sort(arr);
        System.out.println(Arrays.toString(arr));
    }

    private native void print();
    private native int sum(int a, int b);
    private native String getLine(String promt);
    private native int[] sort(int[] arr);
}