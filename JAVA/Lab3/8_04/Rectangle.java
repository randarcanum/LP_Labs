public class Rectangle {
    private double length = 1.0;
    private double width = 1.0;
    public Rectangle(double length, double width) {
        if (length >= 0 && length <= 20) this.length = length;
        if (width >= 0 && width <= 20) this.width = width;
    }
    public double get_length() {
        return length;
    }
    public void set_length(double length) {
        if (length >= 0 && length <= 20) this.length = length;
    }
    public double get_width() {
        return width;
    }
    public void set_width(double width) {
        if (width >= 0 && width <= 20) this.width = width;
    }
    public double perimeter() {
        return 2 * (length + width);
    }
    public double area() {
        return length * width;
    }
}