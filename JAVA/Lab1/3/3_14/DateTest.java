import java.util.Scanner;
public class DateTest {
    public static void main(String[] args) {
        Date date1 = new Date(29, 2, 2024);
        Date date2 = new Date(4, 4, 2004);
        date1.display_date();
        date2.display_date();
        Scanner input = new Scanner(System.in);
        System.out.print("Enter new day for the first date: ");
        int day = input.nextInt();
        date1.set_day(day);
        date1.display_date();
        date2.display_date();
        System.out.print("Enter new month for the second date: ");
        int month = input.nextInt();
        date2.set_month(month);
        date1.display_date();
        date2.display_date();
        System.out.print("Enter new year for the second date: ");
        int year = input.nextInt();
        date2.set_year(year);
        date1.display_date();
        date2.display_date();
    }
}