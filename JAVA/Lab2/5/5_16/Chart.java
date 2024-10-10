import java.util.Scanner;
public class Chart {
    public static void main(String[] args) {
        int[] arr = new int[5];
        Scanner input = new Scanner(System.in);
        System.out.println("Enter five numbers (1 <= n <= 30):");
        for (int i = 0; i < 5; i++) {
            arr[i] = input.nextInt();
            if (arr[i] < 1 || arr[i] > 30) {
                System.err.println("Invalid input!");
                i--;
            }
        }
        System.out.println("Processing the results...");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < arr[i]; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}