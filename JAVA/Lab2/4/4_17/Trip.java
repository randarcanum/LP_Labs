public class Trip {
    private final int miles, gallons;

    public Trip(int miles, int gallons){
        this.miles = miles;
        this.gallons = gallons;
    }
    public double gpm(){
        return (double) gallons / miles;
    }
    public int get_miles(){
        return miles;
    }
    public int get_gallons(){
        return gallons;
    }
}