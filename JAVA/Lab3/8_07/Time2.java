public class Time2 {
    private int time;
    public Time2() {
        this(0, 0, 0);
    }
    public Time2(int hour) {
        this(hour, 0, 0);
    }
    public Time2(int hour, int minute) {
        this(hour, minute, 0);
    }
    public Time2(int hour, int minute, int second) {
        if (hour < 0 || hour >= 24)
            throw new IllegalArgumentException("hour must be 0-23");
        if (minute < 0 || minute >= 60)
            throw new IllegalArgumentException("minute must be 0-59");
        if (second < 0 || second >= 60)
            throw new IllegalArgumentException("second must be 0-59");
        this.time = hour*3600 + minute*60 + second;
    }
    public Time2(Time2 time) {
        this(time.get_hour(), time.get_minute(), time.get_second());
    }
    public void set_time(int hour, int minute, int second) {
        if (hour < 0 || hour >= 24)
            throw new IllegalArgumentException("hour must be 0-23");
        if (minute < 0 || minute >= 60)
            throw new IllegalArgumentException("minute must be 0-59");
        if (second < 0 || second >= 60)
            throw new IllegalArgumentException("second must be 0-59");
        this.time = hour*3600 + minute*60 + second;
    }
    public void set_hour(int hour) {
        if (hour < 0 || hour >= 24)
            throw new IllegalArgumentException("hour must be 0-23");
        this.time += (hour - get_hour())*3600;
    }
    public void set_minute(int minute) {
        if (minute < 0 || minute >= 60)
            throw new IllegalArgumentException("minute must be 0-59");
        this.time += (minute - get_minute())*60;
    }
    public void set_second(int second) {
        if (second < 0 || second >= 60)
            throw new IllegalArgumentException("second must be 0-59");
        this.time += second - get_second();
    }
    public int get_hour() {
        return time / 3600 % 24;
    }
    public int get_minute() {
        return time / 60 % 60;
    }
    public int get_second() {
        return time % 60;
    }
    public void tick() {
        time++;
    }
    public void incrementMinute() {
        time += 60;
    }
    public void incrementHour() {
        time += 3600;
    }
    public String toUniversalString() {
        return String.format("%02d:%02d:%02d", get_hour(), get_minute(), get_second());
    }
    @Override
    public String toString() {
        return String.format("%d:%02d:%02d %s",
            ((get_hour() == 0 || get_hour() == 12) ? 12 : get_hour() % 12),
            get_minute(), get_second(), (get_hour() < 12 ? "AM" : "PM"));
    }
}