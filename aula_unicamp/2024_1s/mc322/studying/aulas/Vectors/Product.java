import java.util.Locale;

public class Product {
    private String name;
    private Double price;

    public Product( String name, Double price ){
        Locale.setDefault(Locale.US);
        this.name = name;
        this.price = price;
    }

    public String getName(){
        return this.name;
    }

    public Double getPrice(){
        return this.price;
    }

}
