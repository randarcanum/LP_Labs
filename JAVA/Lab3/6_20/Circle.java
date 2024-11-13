import java.util.Scanner;
public class Circle {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double radius;
        System.out.println("(Enter 0 to exit)");
        while (true){
            System.out.print("Enter circle radius: ");
            radius = input.nextDouble();
            if (radius == 0) break;
            System.out.printf("Circle area equals to %.2f\n", circleArea(radius));
        }
        System.out.println("Exiting...");
    }
    public static double circleArea(double r){
        return Math.PI * Math.pow(r, 2);
    }
}