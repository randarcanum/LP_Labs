public class Employee {
    private String first_name, last_name;
    private double salary;

    public Employee(String f_name, String l_name, double sal){
        first_name = f_name;
        last_name = l_name;
        if (sal > 0.0) salary = sal;
    }
    public void set_first_name(String f_name){
        first_name = f_name;
    }
    public String get_first_name(){
        return first_name;
    }
    public void set_last_name(String l_name){
        last_name = l_name;
    }
    public String get_last_name(){
        return last_name;
    }
    public void set_salary(double sal){
        if (sal > 0.0) salary = sal;
    }
    public double get_salary(){
        return salary;
    }
    public double get_yearly_salary(){
        return salary*12;
    }
}