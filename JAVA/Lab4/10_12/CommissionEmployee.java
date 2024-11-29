public class CommissionEmployee extends Employee {
    private double gross_sales, commission_rate;

    public CommissionEmployee(String first_name, String last_name, String social_security_number, Date birth_date, double gross_sales, double commission_rate) {
        super(first_name, last_name, social_security_number, birth_date);
        if (gross_sales < 0.0)
            throw new IllegalArgumentException("Gross sales must be >= 0.0");
        if (commission_rate <= 0.0 || commission_rate >= 1.0)
            throw new IllegalArgumentException("Commission rate must be > 0.0 and < 1.0");
        this.commission_rate = commission_rate;
        this.gross_sales = gross_sales;
    }
    public void set_gross_sales(double gross_sales) {
        if (gross_sales < 0.0)
            throw new IllegalArgumentException("Gross sales must be >= 0.0");
        this.gross_sales = gross_sales;
    }
    public double get_gross_sales() {
        return gross_sales;
    }
    public void set_commission_rate(double commission_rate) {
        if (commission_rate <= 0.0 || commission_rate >= 1.0)
            throw new IllegalArgumentException("Commission rate must be > 0.0 and < 1.0");
        this.commission_rate = commission_rate;
    }
    public double get_commission_rate() {
        return commission_rate;
    }
    @Override
    public double earnings() {
        return get_commission_rate() * get_gross_sales();
    }
    @Override
    public String toString() {
        return String.format("%s %s%n%s: $%.2f%n%s: %.2f", 
            "commission", super.toString(), 
            "gross sales", get_gross_sales(), 
            "commission rate", get_commission_rate());
    }
}