import java.util.Locale;
import java.util.Scanner;

public class productVector {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in).useLocale(Locale.US);
        Locale.setDefault(Locale.US);
        
        System.out.print("Digite o número de produtos: ");
        Integer n = scanner.nextInt();
        scanner.nextLine();
        Product[] products = new Product[n];

        //System.out.println("Looping for: " + products.length + " Products");
        String nameProduct;
        double priceProduct;
        for( int i = 0; i < products.length; ++i ){
            nameProduct = scanner.next();
            priceProduct = scanner.nextDouble();
            scanner.nextLine();
            // System.out.println(nameProduct + ' ' + priceProduct);

            products[i] = new Product(nameProduct, priceProduct);
        }

        Double avgPrice = 0.0;
        for( int i = 0; i < products.length; ++i){
            avgPrice += products[i].getPrice();
        }
        avgPrice /= products.length;
        System.out.printf("Average Price: R$%.2f\n", avgPrice);

        scanner.close();
    }    
}
