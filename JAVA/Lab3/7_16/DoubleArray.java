public class DoubleArray {
    public static void main(String[] args) {
        double sum = 0;
        for (String i : args) sum += Double.parseDouble(i);
        System.out.printf("Sum of the arguments: %.3f\n", sum);
    }
}