import java.util.Scanner;
public class Sales {
    public static void main(String[] args) {
        int i = 1;
        double item, sum = 0;
        Scanner input = new Scanner(System.in);
        System.out.println("(Enter 0 to quit)");
        System.out.println("Item\tValue\t");
        while (true) {
            System.out.print(i++ + "\t");
            item = input.nextDouble();
            if (item == 0) break;
            sum += item;
        }
        System.out.printf("Total sales: %.2f\n", sum);
        System.out.printf("Earnings:    %.2f\n", 200+sum*0.09);
    }
}