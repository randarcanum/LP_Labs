import java.util.Scanner;
public class Hypotenuse {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double side1, side2;
        System.out.println("(Enter 0 to exit)");
        while (true){
            System.out.print("Enter first side: ");
            side1 = input.nextDouble();
            if (side1 == 0) break;
            System.out.print("Enter second side: ");
            side2 = input.nextDouble();
            if (side2 == 0) break;
            System.out.printf("Hypotenuse equals to %.2f\n", hypotenuse(side1, side2));
        }
        System.out.println("Exiting...");
    }
    public static double hypotenuse(double x, double y){
        return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
    }
}