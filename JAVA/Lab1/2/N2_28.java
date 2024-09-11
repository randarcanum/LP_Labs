import java.util.Scanner;
public class N2_28 {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the radius: ");
        int r = in.nextInt();
        System.out.printf("Diameter is %d\n", 2*r);
        System.out.printf("Circumference is %.3f\n", 2*Math.PI*r);
        System.out.printf("Area is %.3f\n", Math.PI*r*r);
    }
}