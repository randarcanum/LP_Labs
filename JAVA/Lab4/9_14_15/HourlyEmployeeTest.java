public class HourlyEmployeeTest {
    public static void main(String[] args) {
        HourlyEmployee employee = new HourlyEmployee("Matt", "Higgs", "444-44-4444", 100, 36);
        System.out.println("Employee information obtained by get methods:");
        System.out.printf("%n%s %s%n", "First name is", employee.get_first_name());
        System.out.printf("%s %s%n", "Last name is", employee.get_last_name());
        System.out.printf("%s %s%n", "Social security number is", employee.get_social_security_number());
        System.out.printf("%s %.2f%n", "Wage is", employee.get_wage());
        System.out.printf("%s %.2f%n", "Hours is", employee.get_hours());
        employee.set_wage(80);
        employee.set_hours(52);
        System.out.printf("%n%s:%n%n%s%n", "Updated employee information obtained by toString", employee);
    }
}