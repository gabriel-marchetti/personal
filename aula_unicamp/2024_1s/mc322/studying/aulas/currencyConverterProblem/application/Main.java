package application;

import java.util.Locale;
import java.util.Scanner;

import entities.CurrencyConverter;

public class Main{
    public static void main( String[] args ){
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        System.out.print("Quantos dolares serão comprados? $ ");
        double dolars = sc.nextDouble();
        System.out.printf("Você terá que pagar (em reais): R$ %.2f\n", CurrencyConverter.convertUSDToBRL(dolars));

        sc.close();
    }
}