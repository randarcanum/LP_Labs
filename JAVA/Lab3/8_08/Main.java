public class Main {
    public static void main(String[] args) {
        System.out.println("Incrementing into the next month and year");
        Date test_date = new Date(28, 11, 2024);
        System.out.println(test_date);
        for (int i = 0; i < 40; i++) {
            test_date.next_day();
            System.out.println(test_date);
        }
        System.out.println("\nIncrementing into the next month (no leap year)");
        Date test_date2 = new Date(28, 2, 2025);
        System.out.println(test_date2);
        test_date2.next_day();
        System.out.println(test_date2);
        System.out.println("\nIncrementing into the next month (leap year)");
        Date test_date3 = new Date(28, 2, 2024);
        System.out.println(test_date3);
        test_date3.next_day();
        System.out.println(test_date3);
        test_date3.next_day();
        System.out.println(test_date3);
    }
}