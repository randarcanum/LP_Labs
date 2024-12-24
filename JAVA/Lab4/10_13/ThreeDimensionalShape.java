public abstract class ThreeDimensionalShape extends Shape {
    private static final String DESCRIPTION = "three-dimensional";
    public abstract double get_volume();
    @Override
    public String toString() {
        return String.format("%s %s", DESCRIPTION, super.toString());
    }
}