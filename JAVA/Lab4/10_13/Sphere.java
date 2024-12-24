public class Sphere extends ThreeDimensionalShape {
    private final double radius;

    public Sphere(double radius) {
        this.radius = radius;
    }
    @Override
    public double get_area() {
        return 4*Math.PI*radius*radius;
    }
    @Override
    public double get_volume() {
        return 4/3.0*Math.PI*radius*radius*radius;
    }
    @Override
    public String toString() {
        return String.format("%s is a %s", this.getClass().getName(), super.toString());
    }
}