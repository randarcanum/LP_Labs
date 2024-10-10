import java.util.ArrayList;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        ArrayList<Trip> trips = new ArrayList<>();
        Scanner input = new Scanner(System.in);
        int miles, gallons;
        System.out.println("(Enter 0 to display final result)");
        while (true) {
            System.out.print("Enter miles: ");
            miles = input.nextInt();
            if (miles == 0) break;
            System.out.print("Enter gallons: ");
            gallons = input.nextInt();
            trips.add(new Trip(miles, gallons));
            System.out.printf("Gallons/mile: %.2f\n", trips.get(trips.size()-1).gpm());
        }
        miles = 0;
        gallons = 0;
        for (Trip trip : trips) {
            miles += trip.get_miles();
            gallons += trip.get_gallons();
        }
        System.out.printf("Total gallons/mile for %d trips: %.2f\n", trips.size(), (double) gallons/miles);
    }
}