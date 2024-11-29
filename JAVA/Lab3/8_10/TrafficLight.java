public enum TrafficLight {
    RED(40),
    YELLOW(3),
    GREEN(20);
    private final int duration;
    TrafficLight(int duration) {
        this.duration = duration;
    }
    public void tell_duration() {
        System.out.printf("%s traffic light is on for %d seconds\n", this, duration);
    }
}