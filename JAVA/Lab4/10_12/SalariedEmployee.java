public class SalariedEmployee extends Employee {
    private double weekly_salary;

    public SalariedEmployee(String first_name, String last_name, String social_security_number, Date birth_date, double weekly_salary) {
        super(first_name, last_name, social_security_number, birth_date);
        if (weekly_salary <= 0)
            throw new IllegalArgumentException("Weekly salary must be > 0.0");
        this.weekly_salary = weekly_salary;
    }
    public void set_weekly_salary(double weekly_salary) {
        if (weekly_salary <= 0)
            throw new IllegalArgumentException("Weekly salary must be > 0.0");
        this.weekly_salary = weekly_salary;
    }
    public double get_weekly_salary() {
        return weekly_salary;
    }
    @Override
    public double earnings() {
        return get_weekly_salary();
    }
    @Override
    public String toString() {
        return String.format("%s %s%n%s: $%.2f", 
            "salaried", super.toString(), 
            "weekly salary", get_weekly_salary());
    }
}