public class Main {
    public static void main(String[] args) {
        for (TrafficLight color: TrafficLight.values()) {
            color.tell_duration();
        }
    }
}