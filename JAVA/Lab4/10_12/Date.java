public class Date {
    private int month, day, year;
    private static final int[] days_per_month =
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    public Date(int day, int month, int year) {
        if (month < 1 || month > 12)
            throw new IllegalArgumentException("month (" + month + ") must be 1-12");
        if (day <= 0 || (day > days_per_month[month-1] && !(month == 2 && day == 29))) 
            throw new IllegalArgumentException("day (" + day + ") out of range for the specified month and year");
        if (month == 2 && day == 29 && !(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
            throw new IllegalArgumentException("day (" + day + ") out of range for the specified month and year");
        if (year < 1970 || year > 2038)
            throw new IllegalArgumentException("year (" + year + ") must be 1970-2038");
        this.month = month;
        this.day = day;
        this.year = year;
    }
    public int get_month() {
        return month;
    }
    public int get_day() {
        return day;
    }
    public int get_year() {
        return year;
    }
    @Override
    public String toString() { 
        return String.format("%02d/%02d/%d", day, month, year);
    }
    public void next_day() {
        if (++day > days_per_month[month-1]+(month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 1 : 0)) {
            day = 1;
            if (++month > 12) {
                month = 1;
                year++;
            }
        }
    }
}