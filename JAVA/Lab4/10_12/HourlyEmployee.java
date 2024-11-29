public class HourlyEmployee extends Employee {
    private double hours, wage;

    public HourlyEmployee(String first_name, String last_name, String social_security_number, Date birth_date, double wage, double hours) {
        super(first_name, last_name, social_security_number, birth_date);
        if (wage <= 0)
            throw new IllegalArgumentException("Wage must be > 0.0");
        if (hours < 0 || hours > 168)
            throw new IllegalArgumentException("Hours must be between 0 and 168");
        this.wage = wage;
        this.hours = hours;
    }
    public void set_wage(double wage) {
        if (wage <= 0)
            throw new IllegalArgumentException("Wage must be > 0.0");
        this.wage = wage;
    }
    public double get_wage() {
        return wage;
    }
    public void set_hours(double hours) {
        if (hours < 0 || hours > 168)
            throw new IllegalArgumentException("Hours must be between 0 and 168");
        this.hours = hours;
    }
    public double get_hours() {
        return hours;
    }
    @Override
    public double earnings() {
        return (Math.max(get_hours(), 40) + Math.max(get_hours()-40, 0)*1.5) * get_wage();
    }
    @Override
    public String toString() {
        return String.format("%s %s%n%s: $%.2f%n%s: %.2f", 
            "hourly", super.toString(), 
            "wage per hour", get_wage(), 
            "hours worked", get_hours());
    }
}