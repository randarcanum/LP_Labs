public class Tetrahedron extends ThreeDimensionalShape {
    private final double side;

    public Tetrahedron(double side) {
        this.side = side;
    }
    @Override
    public double get_area() {
        return Math.sqrt(3)*side*side;
    }
    @Override
    public double get_volume() {
        return Math.sqrt(2)*side*side*side/12.0;
    }
    @Override
    public String toString() {
        return String.format("%s is a %s", this.getClass().getName(), super.toString());
    }
}