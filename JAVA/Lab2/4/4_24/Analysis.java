import java.util.Scanner;
public class Analysis {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int passes = 0, failures = 0, studentCounter = 1;
        while (studentCounter <= 10){
            System.out.print("Enter result (1 = pass, 2 = fail): ");
            int result = input.nextInt();
            switch (result) {
                case 1 -> passes++;
                case 2 -> failures++;
                default -> {
                    System.err.println("Invalid input!");
                    continue;
                }
            }
            studentCounter++;
        }
        System.out.printf("Passed: %d\nFailed: %d\n", passes, failures);
        if (passes > 8) System.out.println("Bonus to instructor!");
    }
}