import java.security.SecureRandom;
public class Craps {
    private static final SecureRandom roll = new SecureRandom();
    private enum Status {CONTINUE, WON, LOST};
    public static void main(String[] args) {
        final int N = 1000000;
        int wins[] = new int[21];
        int loses[] = new int[21];
        int win_sum = 0;
        double length = 0;
        for (int i = 0; i < N; i++) {
            Status game_status;
            int point = roll_dice();
            int k = 0;
            game_status = switch (point) {
                case 7, 11 -> Status.WON;
                case 2, 3, 12 -> Status.LOST;
                default -> Status.CONTINUE;
            };
            while (game_status == Status.CONTINUE) {
                int sum = roll_dice();
                game_status = (sum == point) ? Status.WON : (sum == 7) ? Status.LOST : Status.CONTINUE;
                k++;
            }
            k = (k > 20) ? 20 : k;
            if (game_status == Status.WON) wins[k]++;
            else loses[k]++;
        }
        System.out.println("  N    WIN   LOSE    W/L");
        for (int i = 0; i < 21; i++) {
            length += (double) (wins[i] + loses[i]) / N * (i+1);
            win_sum += wins[i];
            System.out.printf("%3d%c %6d %6d %5.2f\n",
                i+1, (i == 20) ? '+' : ' ',
                wins[i], loses[i],
                (double) wins[i] / loses[i]);
        }
        System.out.printf("\nOverall chance of winning: %.1f%%\n", (double) win_sum / N * 100);
        System.out.printf("Average length of a game:  %.2f rolls\n", length);
        if ((double) wins[1] / loses[1] < (double) wins[20] / loses[20]) {
            System.out.println("The chances of winning DO improve with the length of the game.");
        } else {
            System.out.println("The chances of winning DO NOT improve with the length of the game.");
        }
    }
    public static int roll_dice() {
        return roll.nextInt(6) + roll.nextInt(6) + 2;
    }
}