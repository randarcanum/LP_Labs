public class Main {
    public static void main(String[] args) {
        Time2 t1 = new Time2();
        Time2 t2 = new Time2(2);
        Time2 t3 = new Time2(21, 34);
        Time2 t4 = new Time2(12, 25, 42);
        Time2 t5 = new Time2(t4);
        System.out.println("Constructed with:");
        display_time("t1: all default arguments", t1);
        display_time("t2: hour specified; default minute and second", t2);
        display_time("t3: hour and minute specified; default second", t3);
        display_time("t4: hour, minute and second specified", t4);
        display_time("t5: Time2 object t4 specified", t5);
        try {
            Time2 t6 = new Time2(27, 74, 99);
            display_time("t6: illegal arguments specified", t6);
        } catch (IllegalArgumentException e) {
            System.out.printf("Exception while initializing t6: %s\n", e.getMessage());
        }
    }
    private static void display_time(String header, Time2 t) {
        System.out.printf("%s\n   %s\n   %s\n",
            header, t.toUniversalString(), t.toString());
    }
}