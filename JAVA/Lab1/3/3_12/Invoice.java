public class Invoice {
    private String number, description;
    private int quantity;
    private double price;

    public Invoice(String num, String desc, int quant, double price){
        number = num;
        description = desc;
        if (quant > 0) quantity = quant;
        if (price > 0.0) this.price = price;
    }
    public void set_number(String num){
        number = num;
    }
    public String get_number(){
        return number;
    }
    public void set_description(String desc){
        description = desc;
    }
    public String get_description(){
        return description;
    }
    public void set_quantity(int quant){
        if (quant > 0) quantity = quant;
    }
    public int get_quantity(){
        return quantity;
    }
    public void set_price(double price){
        if (price > 0.0) this.price = price;
    }
    public double get_price(){
        return price;
    }
    public double get_invoice_amount(){
        return quantity*price;
    }
}