public class Product {
    public static void main(String[] args) {
        int x = 3,
            y = 28,
            z = 12,
            t = 71;
        System.out.printf("%d * %d * %d * %d = %d\n", x, y, z, t, product(x, y, z, t));
        System.out.printf("7 * 6 * (-1) = %d\n", product(7, 5, -1));
        System.out.printf("Product of %d equals to %d\n", x, product(x));
    }
    public static int product(int... num) {
        int prod = 1;
        for (int i : num) prod *= i;
        return prod;
    } 
}