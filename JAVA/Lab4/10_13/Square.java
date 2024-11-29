public class Square extends TwoDimensionalShape {
    private final double side;

    public Square(double side) {
        this.side = side;
    }
    @Override
    public double get_area() {
        return side*side;
    }
    @Override
    public String toString() {
        return String.format("%s is a %s", this.getClass().getName(), super.toString());
    }
}