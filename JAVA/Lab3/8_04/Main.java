public class Main {
    public static void main(String[] args) {
        Rectangle rect1 = create_rect(4.0, 5.0);
        Rectangle rect2 = create_rect(-1.0, 21.0);
        rect2.set_length(12.5);
        rect2.set_width(7.0);
        System.out.printf("Changing second rectangle to %.1f by %.1f...\n", rect2.get_length(), rect2.get_width());
        System.out.printf("Perimeter of the first rectangle: %.1f\n", rect1.perimeter());
        System.out.printf("Area of the second rectangle: %.1f\n", rect2.area());
    }
    public static Rectangle create_rect(double length, double width) {
        System.out.printf("Trying to create a rectangle %.1f by %.1f...\n", length, width);
        Rectangle rect = new Rectangle(length, width);
        System.out.printf("Created a new rectangle %.1f by %.1f.\n", rect.get_length(), rect.get_width());
        return rect;
    }
}