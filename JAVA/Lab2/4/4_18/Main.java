import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (true) {
            System.out.print("Account name:     ");
            int number = input.nextInt();
            System.out.print("Current balance:  ");
            int balance = input.nextInt();
            System.out.print("Total of items:   ");
            int items = input.nextInt();
            System.out.print("Total of credits: ");
            int credits = input.nextInt();
            System.out.print("Credit limit:     ");
            int limit = input.nextInt();
            Account acc = new Account(number, balance, items, credits, limit);
            System.out.println("\nUpdating balance...");
            acc.update_balance();
            System.out.println("\nProcess another account? (Y/n)");
            char resp;
            boolean flag = true;
            while (flag) { 
                resp = input.next().charAt(0);
                switch (resp) {
                    case 'Y', 'y' -> flag = false;
                    case 'N', 'n' -> {
                        System.out.println("Exiting...");
                        System.exit(0);
                    }
                }
            }
        }
    }
}