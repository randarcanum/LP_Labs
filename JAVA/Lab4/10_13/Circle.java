public class Circle extends TwoDimensionalShape {
    private final double radius;

    public Circle(double radius) {
        this.radius = radius;
    }
    @Override
    public double get_area() {
        return radius*radius*Math.PI;
    }
    @Override
    public String toString() {
        return String.format("%s is a %s", this.getClass().getName(), super.toString());
    }
}