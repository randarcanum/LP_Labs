import java.util.Scanner;
public class N2_17 {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int x = in.nextInt();
        System.out.print("Enter another number: ");
        int y = in.nextInt();
        System.out.print("Enter one more number: ");
        int z = in.nextInt();
        int r = x+y+z;
        System.out.printf("Sum is %d\n", r);
        System.out.printf("Average is %d\n", r/3);
        System.out.printf("Product is %d\n", x*y*z);
        int max = x;
        int min = x;
        if (y > max)
            max = y;
        else min = y;
        if (z > max)
            max = z;
        else if (z < min)
            min = z;
        if (min == max)
            System.out.println("All three numbers are equal");
        else {
            System.out.printf("%d is the largest\n", max);
            System.out.printf("%d is the smallest\n", min);
        }
    }
}