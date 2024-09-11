import java.util.Scanner;
public class N2_26 {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int x = in.nextInt();
        System.out.print("Enter another number: ");
        int y = in.nextInt();
        if (x%y == 0)
            System.out.printf("%d is a multiple of %d\n", x, y);
        else System.out.printf("%d is not a multiple of %d\n", x, y);
    }
}