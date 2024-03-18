package exercicios1;

import java.util.Locale;
import java.util.Scanner;

public class exerc5 {
    public static void main( String[] args ){
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(System.in);
        float precoUnitario, dinheiroRecebido, troco;
        int qtdComprada;

        System.out.printf("Preço unitário do produto: ");
        precoUnitario = scanner.nextFloat();
        System.out.printf("Quantidade Comprada: ");
        qtdComprada = scanner.nextInt();
        System.out.printf("Dinheiro recebido: ");
        dinheiroRecebido = scanner.nextFloat();

        troco = dinheiroRecebido - qtdComprada * precoUnitario;
        if( troco < 0 ){
            System.out.println("Não há dinheiro suficiente!");
        }
        else{
            System.out.printf("TROCO = %.2f%n", troco);
        }
        
        scanner.close();
    }
}
