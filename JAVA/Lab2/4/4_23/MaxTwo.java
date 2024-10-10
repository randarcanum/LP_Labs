import java.util.Scanner;
public class MaxTwo {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int counter, number, largest, second;
        System.out.println("Enter 10 numbers:");
        largest = input.nextInt();
        number = input.nextInt();
        if (number > largest){
            second = largest;
            largest = number;
        } else second = number;
        for (counter = 0; counter < 8; counter++){
            number = input.nextInt();
            if (number > largest){
                second = largest;
                largest = number;
            } else if (number > second){
                second = number;
            }
        }
        System.out.printf("The largest number is %d\n", largest);
        System.out.printf("The second largest number is %d\n", second);
    }
}