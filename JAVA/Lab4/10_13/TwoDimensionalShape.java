public abstract class TwoDimensionalShape extends Shape {
    private static final String DESCRIPTION = "two-dimensional";
    @Override
    public abstract double get_area();
    @Override
    public String toString() {
        return String.format("%s %s", DESCRIPTION, super.toString());
    }
}