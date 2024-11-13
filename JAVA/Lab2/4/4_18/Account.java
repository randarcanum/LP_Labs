public class Account {
    private int balance;
    private final int number, items, credits, limit;

    public Account(int number, int balance, int items, int credits, int limit){
        this.number = number;
        this.balance = balance;
        this.items = items;
        this.credits = credits;
        this.limit = limit;
    }
    public void update_balance(){
        balance += items;
        balance -= credits;
        System.out.printf("New %d balance: %d\n", number, balance);
        if (balance < limit)
            System.err.print("Credit limit exceeded.\n");
    }
}