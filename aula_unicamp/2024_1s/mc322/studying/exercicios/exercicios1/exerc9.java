package exercicios1;

import java.util.Locale;
import java.util.Scanner;

public class exerc9 {
    public static void main( String[] args ){
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(System.in);
        float A, B, C;

        System.out.printf("Medida A: ");
        A = scanner.nextFloat();
        System.out.printf("Medida B: ");
        B = scanner.nextFloat();
        System.out.printf("Medida C: ");
        C = scanner.nextFloat();

        System.out.printf("AREA QUADRADO: %.4f\n",
                           squareArea(A));
        System.out.printf("AREA TRIANGULO: %.4f\n",
                           triangleArea(A, B));
        System.out.printf("AREA TRAPEZIO: %.4f\n",
                            trapeziusArea(A, B, C));

        scanner.close();
    }

    public static float squareArea( float lado ){
        return lado * lado;
    }

    public static float triangleArea( float base, float altura ){
        return ( base * altura ) / 2;
    }

    public static float trapeziusArea( float baseMenor,
                                       float baseMaior,
                                       float altura
    ){
        return ( baseMaior + baseMenor ) / 2 * altura;
    }
}
