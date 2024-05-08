package application;

import java.util.Locale;
import java.util.Scanner;

import entities.Product;

public class Main {
    public static void main(String[] args) {
        System.out.println("Bem-vindo ao controle de estoque!");
        Scanner sc = new Scanner(System.in);
        Locale.setDefault(Locale.US);
        Product p = new Product();

        int option = 1;
        while( option != 6 ){
            System.out.println("1. Criar produto.");
            System.out.println("2. Valor total de estoque.");
            System.out.println("3. Adicionar Produtos Estoque.");
            System.out.println("4. Retirar Produtos Estoque.");
            System.out.println("5. Consultar dados do produto.");
            System.out.println("6. Sair do sistema.");
            System.out.printf("Escolha: ");
            option = sc.nextInt();
            
            switch (option) {
                case 1:
                    System.out.println("Nome produto: ");
                    sc.nextLine();
                    p.name = sc.nextLine();
                    System.out.println("Quantidade inicial: ");
                    p.quantity = sc.nextInt();
                    System.out.println("Preço: ");
                    p.price = sc.nextDouble();
                    break;
                case 2:
                    System.out.printf("Preço do estoque: %.2f\n", p.totalStockValue());
                    break;
                case 3:
                    int addQuantity;
                    System.out.println("Quantos itens você quer adicionar?");
                    addQuantity = sc.nextInt();
                    p.addProducts(addQuantity);
                    break;
                case 4:
                    int rmvQuantity;
                    System.out.println("Quantos itens você quer retirar?");
                    rmvQuantity = sc.nextInt();
                    p.removeProducts(rmvQuantity);
                    break;
                case 5:
                    System.out.println(p);
                    break;
                default:
                    break;
            }
        }

        sc.close();
    }
}
