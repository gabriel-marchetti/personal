package exercicios1;

import java.util.Locale;
import java.util.Scanner;

public class exerc1 {
    public static void main( String[] args ){
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(System.in);
        float largura, comprimento, valorMetroQuadrado;

        System.out.printf("Qual a largura do terreno: ");
        largura = scanner.nextFloat();
        System.out.printf("Qual o comprimento do terreno: ");
        comprimento = scanner.nextFloat();
        System.out.printf("Qual o valor do metro quadrado: ");
        valorMetroQuadrado = scanner.nextFloat();

        System.out.printf("Area do terreno: %.2f\n", areaTerreno(comprimento, largura));
        System.out.printf("Preco do terreno: %.2f\n", valorTerreno(comprimento, 
                                                                   largura,
                                                                   valorMetroQuadrado));

        scanner.close();
    }

    public static float areaTerreno( float comprimento, float largura ){
        return comprimento * largura;
    }

    public static float valorTerreno( float comprimento,
                               float largura,
                               float valorMetroQuadrado)
    {
        return valorMetroQuadrado * areaTerreno(comprimento, largura);                        
    }
}
