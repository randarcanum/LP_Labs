import java.util.Scanner;
public class Min {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num;
        System.out.println("Enter number count:");
        int n = input.nextInt();
        if (n > 0) {
            System.out.printf("Enter %d integers:\n", n);
            int min = input.nextInt();
            for (int i = 0; i < n-1; i++){
                num = input.nextInt();
                if (num < min) min = num;
            }
            System.out.printf("The smallest number is %d\n", min);
        }
    }
}