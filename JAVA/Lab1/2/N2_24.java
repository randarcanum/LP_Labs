import java.util.Scanner;
public class N2_24 {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("Enter five numbers: ");
        int x = in.nextInt();
        int y = in.nextInt();
        int z = in.nextInt();
        int i = in.nextInt();
        int j = in.nextInt();
        int max = x;
        int min = x;
        if (y > max)
            max = y;
        else min = y;
        if (z > max)
            max = z;
        else if (z < min)
            min = z;
        if (i > max)
            max = i;
        else if (i < min)
            min = i;
        if (j > max)
            max = j;
        else if (j < min)
            min = j;
        if (min == max)
            System.out.println("All five numbers are equal");
        else {
            System.out.printf("%d is the largest\n", max);
            System.out.printf("%d is the smallest\n", min);
        }
    }
}