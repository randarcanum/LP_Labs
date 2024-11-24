public class Main {
    public static void main(String[] args) {
        SavingsAccount saver1 = new SavingsAccount(2000);
        System.out.printf("Creating an account with balance $%.2f...\n", saver1.get_balance());
        SavingsAccount saver2 = new SavingsAccount(3000);
        System.out.printf("Creating an account with balance $%.2f...\n", saver2.get_balance());
        SavingsAccount.modifyInterestRate(0.04);
        System.out.println("\nSetting annual interest rate to 4%%...");
        System.out.println("\n        First    Second");
        System.out.println("Month  account  account");
        System.out.println("       balance  balance");
        for (int i = 0; i < 12; i++) {
            saver1.calculateMonthlyInterest();
            saver2.calculateMonthlyInterest();
            System.out.printf(" %2d   $%7.2f   $%7.2f\n", i+1, saver1.get_balance(), saver2.get_balance());
        }
        SavingsAccount.modifyInterestRate(0.05);
        System.out.println("Setting annual interest rate to 5%%...");
        saver1.calculateMonthlyInterest();
        saver2.calculateMonthlyInterest();
        System.out.printf(" %2d   $%7.2f   $%7.2f\n", 13, saver1.get_balance(), saver2.get_balance());
    }
}