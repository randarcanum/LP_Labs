import java.util.Scanner;
public class Temperature {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int x;
        double temp;
        while (true) {
            System.out.println("// 1: Celsius -> Fahrenheit");
            System.out.println("// 2: Fahrenheit -> Celsius");
            System.out.println("// 0: Exit");
            System.out.print("Choose an option: ");
            do x = input.nextInt();
            while (x != 1 && x != 2);
            if (x == 0) break;
            System.out.print("Enter temperature value: ");
            temp = input.nextDouble();
            temp = x == 1 ? fahrenheit(temp) : celsius(temp);
            System.out.printf("New value: %.1f\n", temp);
        }
        System.out.println("Exiting...");
    }
    public static double celsius(double fahrenheit) {
        return 5.0 / 9.0 * (fahrenheit - 32);
    }
    public static double fahrenheit(double celsius) {
        return 9.0 / 5.0 * celsius + 32;
    }
}