import java.security.SecureRandom;
public class Dice {
    private static final SecureRandom roll = new SecureRandom();
    public static void main(String[] args) {
        final int N = 36000000;
        int first, second;
        int dist[] = new int[11];
        for (int i = 0; i < N; i++) {
            first = roll.nextInt(6);
            second = roll.nextInt(6);
            dist[first + second]++;
        }
        System.out.println("Distribution:");
        String head = "Value  Times    Freq  |  ";
        for (int i = 5; i <= 20; i += 5) {
            head += "    " + i;
        }
        System.out.println(head);
        System.out.println("=".repeat(head.length()));
        for (int i = 0; i < 11; i++) {
            double freq = (double) dist[i] / N * 100;
            System.out.printf("%4d %8d %5.1f%%  |  ", i+2, dist[i], freq);
            System.out.println("*".repeat((int) Math.round(freq)));
        }
    }
}