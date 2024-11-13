import java.util.Scanner;
public class Square {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter square size: ");
        int n = input.nextInt();
        if (n <= 0) System.exit(0);
        System.out.print("Enter fill character: ");
        char fill = input.next().charAt(0);
        squareOfCharacters(n, fill);
    }
    public static void squareOfCharacters(int side, char fillCharacter) {
        for (int i = 0; i < side; i++) {
            for (int j = 0; j < side; j++) {
                System.out.print(fillCharacter);
            }
            System.out.println();
        }
    }
}