import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Employee[] employees = new Employee[3];
        String name;
        int hours, rate;
        for (int i = 0; i < 3; i++) {
            switch (i) {
                case 0 -> System.out.println("=First employee=");
                case 1 -> System.out.println("=Second employee=");
                case 2 -> System.out.println("=Third employee=");
            }
            System.out.print("Employee name:   ");
            name = input.nextLine();
            System.out.print("Number of hours: ");
            hours = input.nextInt();
            System.out.print("Hourly rate:     ");
            rate = input.nextInt();
            input.nextLine();
            employees[i] = new Employee(name, hours, rate);
        }
        System.out.println("\nName             Payment");
        for (Employee i : employees) {
            System.out.printf("%-16s %5.2f\n", i.get_name(), i.calculate_pay());
        }
    }
}