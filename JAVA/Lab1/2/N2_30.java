import java.util.Scanner;
public class N2_30 {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a five-digit number: ");
        int x = in.nextInt();
        System.out.printf("%d %d %d %d %d\n", x%100000/10000, x%10000/1000, x%1000/100, x%100/10, x%10);
    }
}