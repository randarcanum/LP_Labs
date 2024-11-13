import java.security.SecureRandom;
import java.util.Scanner;
public class Coin {
    private static final SecureRandom toss = new SecureRandom();
    public enum coin {HEADS, TAILS};
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String x;
        int heads = 0, tails = 0;
        System.out.println("(Enter 0 to exit)");
        while (true) {
            System.out.println("Press Enter to toss the coin!");
            x = input.nextLine();
            if (x.equals("0")) break;
            switch (flip()) {
                case HEADS -> {
                    System.out.println("Heads!");
                    heads++;
                }
                case TAILS -> {
                    System.out.println("Tails!");
                    tails++;
                }
            }
            System.out.println("Current score:");
            System.out.printf("H: %d\n", heads);
            System.out.printf("T: %d\n\n", tails);
        }
        System.out.println("Exiting...");
    }
    public static coin flip() {
        return toss.nextInt(2) == 0 ? coin.HEADS : coin.TAILS;
    }
}