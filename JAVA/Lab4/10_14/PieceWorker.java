public class PieceWorker extends Employee {
    private double wage;
    private int pieces;

    public PieceWorker(String first_name, String last_name, String social_security_number, double wage, int pieces) {
        super(first_name, last_name, social_security_number);
        if (wage <= 0)
            throw new IllegalArgumentException("Wage must be > 0.0");
        if (pieces < 0)
            throw new IllegalArgumentException("Pieces must be >= 0");
        this.wage = wage;
        this.pieces = pieces;
    }
    public void set_wage(double wage) {
        if (wage <= 0)
            throw new IllegalArgumentException("Wage must be > 0.0");
        this.wage = wage;
    }
    public double get_wage() {
        return wage;
    }
    public void set_pieces(int pieces) {
        if (pieces < 0)
            throw new IllegalArgumentException("Pieces must be >= 0");
        this.pieces = pieces;
    }
    public double get_pieces() {
        return pieces;
    }
    @Override
    public double earnings() {
        return get_pieces() * get_wage();
    }
    @Override
    public String toString() {
        return String.format("%s %s%n%s: $%.2f%n%s: %.2f", 
            "hourly", super.toString(), 
            "wage per hour", get_wage(), 
            "hours worked", get_pieces());
    }
}