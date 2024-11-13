import java.util.Scanner;
public class NoDup {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] num = new int[5];
        int newnum, n = 0, j;
        for (int i = 0; i < 5; i++) {
            System.out.print("Enter a number from 10 to 100: ");
            do newnum = input.nextInt();
            while (newnum < 10 || newnum > 100);
            for (j = 0; j < n; j++) {
                if (newnum == num[j]) break;
            }
            if (j == n) {
                num[n] = newnum;
                n++;
            }
            System.out.println("Current array:");
            for (j = 0; j < n; j++) System.out.println(num[j]);
        }
    }
}