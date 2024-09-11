import java.util.Scanner;
public class EmployeeTest {
    public static void main(String[] args) {
        Employee employee1 = new Employee("Jack", "Hammer", 1200.50);
        Employee employee2 = new Employee("Hazel", "Nut", -300.0);
        display_employee(employee1);
        display_employee(employee2);
        Scanner input = new Scanner(System.in);
        System.out.print("Enter new last name for the first employee: ");
        String l_name = input.nextLine();
        employee1.set_last_name(l_name);
        display_employee(employee1);
        display_employee(employee2);
        System.out.print("Enter new first name for the second employee: ");
        String f_name = input.nextLine();
        employee2.set_first_name(f_name);
        display_employee(employee1);
        display_employee(employee2);
        System.out.print("Enter new monthly salary for the second employee: $");
        double sal = input.nextDouble();
        employee2.set_salary(sal);
        display_employee(employee1);
        display_employee(employee2);
    }
    private static void display_employee(Employee employee){
        System.out.printf("Name:          %s %s\n", employee.get_first_name(), employee.get_last_name());
        System.out.printf("Yearly salary: $%.2f\n\n", employee.get_yearly_salary());
    }
}