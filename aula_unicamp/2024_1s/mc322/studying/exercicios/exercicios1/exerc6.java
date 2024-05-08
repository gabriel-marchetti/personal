package exercicios1;

import java.util.Locale;
import java.util.Scanner;

public class exerc6 {
    public static void main( String[] args ){
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(System.in);
        double raio;

        System.out.printf("Digite o raio do círculo: ");
        raio = scanner.nextDouble();
        System.out.printf("AREA: %.3f\n", areaCircle(raio));

        scanner.close();
    }

    public static double areaCircle( double raio ){
        return Math.PI * raio * raio;
    }
}
