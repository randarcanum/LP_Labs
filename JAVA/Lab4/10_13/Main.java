public class Main {
    public static void main(String[] args) {
        Shape[] shapes = {
            new Circle(1),
            new Square(2),
            new Triangle(3)
        };
        for (Shape shape : shapes) {
            System.out.println(shape);
            System.out.printf("Area: %.2f%n", shape.get_area());
        }
    }
}