import java.util.Scanner;
public class AccountTest{
    public static void main(String[] args) {
        Account account1 = new Account("Jane Green", 50.00);
        Account account2 = new Account("John Blue", -7.53);
        show_balance(account1);
        show_balance(account2);
        Scanner input = new Scanner(System.in);
        System.out.print("Enter deposit amount for account2: ");
        double dep_amount = input.nextDouble();
        System.out.printf("Adding %.2f to %s balance\n", dep_amount, account2.get_name());
        account2.deposit(dep_amount);
        show_balance(account1);
        show_balance(account2);
        System.out.print("Enter withdraw amount for account1: ");
        double with_amount = input.nextDouble();
        System.out.printf("Withdrawing %.2f from %s balance\n", with_amount, account1.get_name());
        account1.withdraw(with_amount);
        show_balance(account1);
        show_balance(account2);
    }
    public static void  show_balance(Account account){
        System.out.printf("%s balance: $%.2f\n", account.get_name(), account.get_balance());
    }
}