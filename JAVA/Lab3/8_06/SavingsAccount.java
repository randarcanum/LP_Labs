import java.math.BigDecimal;
public class SavingsAccount {
    private static double annualInterestRate;
    private BigDecimal savingsBalance;
    public SavingsAccount(double balance) {
        savingsBalance = BigDecimal.valueOf(balance);
    }
    public void calculateMonthlyInterest() {
        savingsBalance = savingsBalance.add(savingsBalance.multiply(BigDecimal.valueOf(annualInterestRate/12)));
    }
    public static void modifyInterestRate(double rate) {
        annualInterestRate = rate;
    }
    public BigDecimal get_balance() {
        return savingsBalance;
    }
}