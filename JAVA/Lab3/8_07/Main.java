public class Main {
    public static void main(String[] args) {
        System.out.println("Incrementing by one second into the next minute");
        Time2 test_time1 = new Time2(15, 24, 58);
        System.out.printf("%s\n", test_time1);
        for (int i = 0; i < 4; i++) {
            test_time1.tick();
            System.out.printf("%s\n", test_time1);
        }
        System.out.println("\nIncrementing by one second into the next hour");
        Time2 test_time2 = new Time2(7, 59, 58);
        System.out.printf("%s\n", test_time2);
        for (int i = 0; i < 4; i++) {
            test_time2.tick();
            System.out.printf("%s\n", test_time2);
        }
        System.out.println("\nIncrementing by one second into the next day");
        Time2 test_time3 = new Time2(23, 59, 58);
        System.out.printf("%s\n", test_time3);
        for (int i = 0; i < 4; i++) {
            test_time3.tick();
            System.out.printf("%s\n", test_time3);
        }
        System.out.println("\nIncrementing by one minute into the next hour");
        Time2 test_time4 = new Time2(21, 58, 18);
        System.out.printf("%s\n", test_time4);
        for (int i = 0; i < 4; i++) {
            test_time4.incrementMinute();
            System.out.printf("%s\n", test_time4);
        }
        System.out.println("\nIncrementing by one minute into the next day");
        Time2 test_time5 = new Time2(23, 58, 5);
        System.out.printf("%s\n", test_time5);
        for (int i = 0; i < 4; i++) {
            test_time5.incrementMinute();
            System.out.printf("%s\n", test_time5);
        }
        System.out.println("\nIncrementing by one hour into the next day");
        Time2 test_time6 = new Time2(22, 17, 45);
        System.out.printf("%s\n", test_time6);
        for (int i = 0; i < 4; i++) {
            test_time6.incrementHour();
            System.out.printf("%s\n", test_time6);
        }
    }
}