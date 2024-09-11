import java.util.Scanner;
public class N2_32 {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int pos = 0, neg = 0, zer = 0;
        System.out.print("Enter five numbers: ");
        int x = in.nextInt();
        if (x > 0) pos++;
        else if (x < 0) neg++;
        else zer++;
        int y = in.nextInt();
        if (y > 0) pos++;
        else if (y < 0) neg++;
        else zer++;
        int z = in.nextInt();
        if (z > 0) pos++;
        else if (z < 0) neg++;
        else zer++;
        int i = in.nextInt();
        if (i > 0) pos++;
        else if (i < 0) neg++;
        else zer++;
        int j = in.nextInt();
        if (j > 0) pos++;
        else if (j < 0) neg++;
        else zer++;
        System.out.printf("Positives: %d\n", pos);
        System.out.printf("Negatives: %d\n", neg);
        System.out.printf("Zeroes: %d\n", zer);
    }
}