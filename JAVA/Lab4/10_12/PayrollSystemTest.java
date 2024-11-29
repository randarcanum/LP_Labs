public class PayrollSystemTest {
    public static void main(String[] args) {
        SalariedEmployee salariedEmployee = 
            new SalariedEmployee("John", "Smith", "111-11-1111", new Date(14, 3, 1987), 800.00); 
        HourlyEmployee hourlyEmployee = 
            new HourlyEmployee("Karen", "Price", "222-22-2222", new Date(21, 8, 1992), 16.75, 40);
        CommissionEmployee commissionEmployee = 
            new CommissionEmployee("Sue", "Jones", "333-33-3333", new Date(3, 11, 1990), 10000, .06);
        BasePlusCommissionEmployee basePlusCommissionEmployee = 
            new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", new Date(1, 9, 1975), 5000, .04, 300);
        
        Employee[] employees = {salariedEmployee, hourlyEmployee, commissionEmployee, basePlusCommissionEmployee};
        System.out.printf("Employees processed polymorphically:%n%n");
        for (int current_month = 1; current_month <= 12; current_month++) {
            System.out.printf("Month %d%n%n", current_month);
            for (Employee current_employee : employees) {
                System.out.println(current_employee);
                double bonus = 0;
                if (current_employee.get_birth_date().get_month() == current_month) {
                    bonus = 100;
                    System.out.printf("Happy birthday, %s! +%.2f$%n", current_employee.get_first_name(), bonus);
                }
                System.out.printf("earned $%,.2f%n%n", current_employee.earnings() + bonus);
            }
        }
    }
}