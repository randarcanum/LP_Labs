public class InitArray {
    public static void main(String[] args) {
        int N = 10;
        if (args.length != 0) N = Integer.parseInt(args[0]);
        int[] array = new int[N];
        System.out.printf("%s%8s\n", "Index", "Value");
        for (int counter = 0; counter < array.length; counter++) {
            System.out.printf("%5d%8d\n", counter, array[counter]);
        }
    }
}