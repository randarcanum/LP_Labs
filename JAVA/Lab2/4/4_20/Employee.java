public class Employee {
    private final String name;
    private final int hours;
    private final double rate;

    public Employee(String name, int hours, int rate){
        this.name = name;
        this.hours = hours;
        this.rate = rate;
    }
    public double calculate_pay(){
        if (hours <= 40) return hours*rate;
        else return (hours/2+20)*rate;
    }
    public String get_name(){
        return name;
    }
}