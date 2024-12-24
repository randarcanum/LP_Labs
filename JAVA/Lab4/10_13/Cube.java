public class Cube extends ThreeDimensionalShape {
    private final double side;

    public Cube(double side) {
        this.side = side;
    }
    @Override
    public double get_area() {
        return 6*side*side;
    }
    @Override
    public double get_volume() {
        return side*side*side;
    }
    @Override
    public String toString() {
        return String.format("%s is a %s", this.getClass().getName(), super.toString());
    }
}