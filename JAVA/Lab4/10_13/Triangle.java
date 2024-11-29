public class Triangle extends TwoDimensionalShape {
    private final double side1, side2, side3;

    public Triangle(double side) {
        this.side1 = side;
        this.side2 = side;
        this.side3 = side;
    }
    public Triangle(double side, double base) {
        this.side1 = side;
        this.side2 = side;
        this.side3 = base;
    }
    public Triangle(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }
    @Override
    public double get_area() {
        double p = (side1+side2+side3)/2;
        return Math.sqrt(p*(p-side1)*(p-side2)*(p-side3));
    }
    @Override
    public String toString() {
        return String.format("%s is a %s", this.getClass().getName(), super.toString());
    }
}