import java.util.Scanner;
public class N2_16 {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("Comparing ");
        int x = in.nextInt();
        System.out.print("to ");
        int y = in.nextInt();
        if (x > y)    
            System.out.printf("%d is larger\n", x);
        else if (x < y)
            System.out.printf("%d is larger\n", y);
        else System.out.println("These numbers are equal");
    }
}