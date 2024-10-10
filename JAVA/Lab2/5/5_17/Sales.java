import java.util.Scanner;
public class Sales {
    public static void main(String[] args) {
        double sum = 0;
        int number;
        Scanner input = new Scanner(System.in);
        System.out.println("(Enter 0 to exit)");
        while (true) {
            System.out.print("Enter product number (1-5): ");
            number = input.nextInt();
            if (number == 0) break;
            if (number < 1 || number > 5) System.err.println("Invalid product number!");
            else {
                System.out.print("Enter quantity sold: ");
                switch (number) {
                    case 1 -> sum += input.nextInt()*2.98;
                    case 2 -> sum += input.nextInt()*4.50;
                    case 3 -> sum += input.nextInt()*9.98;
                    case 4 -> sum += input.nextInt()*4.49;
                    case 5 -> sum += input.nextInt()*6.87;
                }
            }
        }
        System.out.printf("Total value: %.2f\n", sum);
    }
}