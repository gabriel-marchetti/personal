package application;

import entities.Product;

public class test {
    public static void main( String[] args ){
        Product product = new Product();
        product.name = "Copo";
        product.price = 5.70;
        product.quantity = 5;

        Product product2 = new Product();
        product2.name = "Copo";
        product2.price = 5.70;
        product2.quantity = 5;

        System.out.println(product);
        System.out.println(product.equals(product2));
        System.out.println(product.equals(product));
    }
}
