import java.util.Scanner;
public class Parking {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double hours, charge, total = 0;
        System.out.println("(Enter 0 to exit)");
        while (true){
            System.out.print("Enter parking hours: ");
            hours = input.nextDouble();
            if (hours == 0) break;
            charge = calculateCharges(hours);
            System.out.printf("To be charged: %.2f$\n", charge);
            total += charge;
            System.out.printf("Total charges: %.2f$\n", total);
        }
        System.out.println("Exiting...");
    }
    public static double calculateCharges(double hours){
        return Math.min(10.0, Math.max(2.0, 0.5*(1+Math.ceil(hours))));
    }
}