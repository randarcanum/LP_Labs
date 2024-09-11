public class Account {
    private String name;
    private double balance;

    public Account(String name, double balance){
        this.name = name;
        if (balance > 0.0) this.balance = balance;
    }
    public void deposit(double amount){
        if (amount > 0.0) balance += amount;
    }
    public void withdraw(double amount){
        if (amount < balance) balance -= amount;
        else System.out.println("Withdrawal amount exceeded account balance.");
    }
    public double get_balance(){
        return balance;
    }
    public void set_name(String name){
        this.name = name;
    }
    public String get_name(){
        return name;
    }
}