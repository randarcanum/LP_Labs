import java.util.Scanner;
public class Reverse {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int number;
        while (true) {
            System.out.println("(Enter 0 to exit)");
            System.out.print("Enter your number: ");
            number = input.nextInt();
            if (number == 0) break;
            System.out.printf("Reversed number:   %d\n", reverse(number));
        }
        System.out.println("Exiting...");
    }
    public static int reverse(int number) {
        int rebmun = 0;
        while (number > 0) {
            rebmun += number % 10;
            rebmun *= 10;
            number /= 10;
        }
        return rebmun / 10;
    }
}