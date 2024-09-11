public class Date {
    private int day, month, year;

    public Date(int day, int month, int year){
        this.day = day;
        this.month = month;
        this.year = year;
    }
    public void set_day(int day){
        this.day = day;
    }
    public int get_day(){
        return day;
    }
    public void set_month(int month){
        this.month = month;
    }
    public int get_month(){
        return month;
    }
    public void set_year(int year){
        this.year = year;
    }
    public int get_year(){
        return year;
    }
    public void display_date(){
        System.out.printf("%d/%d/%d\n", day, month, year);
    }
}