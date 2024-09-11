import java.util.Scanner;
public class N2_15 {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int x = in.nextInt();
        System.out.print("Enter another number: ");
        int y = in.nextInt();
        System.out.printf("%d + %d = %d\n", x, y, x+y);
        System.out.printf("%d * %d = %d\n", x, y, x*y);
        System.out.printf("%d - %d = %d\n", x, y, x-y);
        System.out.printf("%d / %d = %d\n", x, y, x/y);
    }
}