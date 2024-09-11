import java.util.Scanner;
public class InvoiceTest{
    public static void main(String[] args) {
        Invoice inv1 = new Invoice("C-1", "Circle, the angle-free shape.", 42, 10.0);
        Invoice inv2 = new Invoice("T-1", "Triangle, the extra sharp shape.", 4, -60.0);
        Invoice inv3 = new Invoice("S-1", "Square, the unrollable shape.", -12, 10.0);
        display_invoice(inv1);
        display_invoice(inv2);
        display_invoice(inv3);
        Scanner input = new Scanner(System.in);
        System.out.print("Enter new number for the first invoice: ");
        String num = input.nextLine();
        inv1.set_number(num);
        display_invoice(inv1);
        display_invoice(inv2);
        display_invoice(inv3);
        System.out.print("Enter new description for the first invoice: ");
        String desc = input.nextLine();
        inv1.set_description(desc);
        display_invoice(inv1);
        display_invoice(inv2);
        display_invoice(inv3);
        System.out.print("Enter new quantity for the third invoice: ");
        int quant = input.nextInt();
        inv3.set_quantity(quant);
        display_invoice(inv1);
        display_invoice(inv2);
        display_invoice(inv3);
        System.out.print("Enter new price for the second invoice: $");
        double price = input.nextDouble();
        inv2.set_price(price);
        display_invoice(inv1);
        display_invoice(inv2);
        display_invoice(inv3);
    }
    private static void display_invoice(Invoice invoice){
        System.out.printf("Number:         %s\n", invoice.get_number());
        System.out.printf("Description:    %s\n", invoice.get_description());
        System.out.printf("Quantity:       %d\n", invoice.get_quantity());
        System.out.printf("Price:          $%.2f\n", invoice.get_price());
        System.out.printf("Invoice Amount: $%.2f\n\n", invoice.get_invoice_amount());
    }
}