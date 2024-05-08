package entities;

public class Product{
    public String name;
    public double price;
    public int quantity;

    public double totalStockValue(){
        return ((double) quantity) * price;
    }

    public void addProducts( int quantity ){
        this.quantity += quantity;
    }

    public void removeProducts( int quantity ){
        if( this.quantity - quantity < 0 ){
            this.quantity = 0;
            return;
        }
        this.quantity -= quantity;
    }

    public String toString(){
        return "Name: "
            + name
            + ", $ "
            + String.format("%.2f", price)
            + ", quantity: "
            + quantity
            + ", totalValueStock: $ "
            + String.format("%.2f", totalStockValue());
    }
}