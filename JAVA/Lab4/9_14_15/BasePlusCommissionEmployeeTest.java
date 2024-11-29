public class BasePlusCommissionEmployeeTest {
    public static void main(String[] args) {
        BasePlusCommissionEmployee employee = new BasePlusCommissionEmployee("Bob", "Lewis", "333-33-3333", 5000, .04, 300);
        System.out.println("Employee information obtained by get methods:");
        System.out.printf("%n%s %s%n", "First name is", employee.get_first_name());
        System.out.printf("%s %s%n", "Last name is", employee.get_last_name());
        System.out.printf("%s %s%n", "Social security number is", employee.get_social_security_number());
        System.out.printf("%s %.2f%n", "Gross sales is", employee.get_gross_sales());
        System.out.printf("%s %.2f%n", "Commission rate is", employee.get_commission_rate());
        System.out.printf("%s %.2f%n", "Base salary is", employee.get_base_salary());
        employee.set_base_salary(1000);
        System.out.printf("%n%s:%n%n%s%n", "Updated employee information obtained by toString", employee);
    }
}