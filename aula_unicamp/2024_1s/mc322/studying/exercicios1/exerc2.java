package exercicios1;

import java.util.Locale;
import java.util.Scanner;

public class exerc2 {
    public static void main( String[] args ){
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(System.in);

        float base, altura;
        
        System.out.printf("Base do retângulo: ");
        base = scanner.nextFloat();
        System.out.printf("Altura do retângulo: ");
        altura = scanner.nextFloat();

        System.out.printf("AREA: %.4f\n", areaRectangle(base, altura));
        System.out.printf("PERIMETRO: %.4f\n", perimeterRectangle(base, altura));
        System.out.printf("DIAGONAL: %.4f\n", diagonalRectangle(base, altura));

        scanner.close();
    }

    public static float areaRectangle( float base, float altura ){
        return base * altura;
    }

    public static float perimeterRectangle( float base, float altura ){
        return ( 2 * ( base + altura ) );
    }

    public static float diagonalRectangle( float base, float altura ){
        return (float) Math.sqrt( base*base + altura*altura );
    }

}
