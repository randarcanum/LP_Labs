import java.util.Scanner;
public class Max {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int counter, number, largest;
        System.out.println("Enter 10 numbers:");
        largest = input.nextInt();
        for (counter = 0; counter < 9; counter++){
            number = input.nextInt();
            if (number > largest) largest = number;
        }
        System.out.printf("The largest number is %d\n", largest);
    }
}