import java.util.Scanner;
public class Sales {
    public static void main(String[] args) {
        double[] price = {2.98, 4.50, 9.98, 4.49, 6.87};
        double sum = 0;
        int number, quantity;
        Scanner input = new Scanner(System.in);
        System.out.println("(Enter 0 to exit)");
        while (true) {
            System.out.print("Enter product number (1-5): ");
            number = input.nextInt();
            switch (number) {
                case 0 -> {
                    System.out.printf("Total value: %.2f\n", sum);
                    System.exit(0);
                }
                case 1, 2, 3, 4, 5 -> {
                    System.out.print("Enter quantity sold: ");
                    quantity = input.nextInt();
                    sum += quantity*price[number-1];
                }
                default -> System.err.println("Invalid product number!");
            }
        }
    }
}