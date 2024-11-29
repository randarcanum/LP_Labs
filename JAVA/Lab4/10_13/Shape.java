public abstract class Shape {
    private static final String DESCRIPTION = "shape";
    public abstract double get_area();
    @Override
    public String toString() {
        return DESCRIPTION;
    }
}