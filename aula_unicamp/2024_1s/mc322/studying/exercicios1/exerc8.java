package exercicios1;

import java.util.Locale;
import java.util.Scanner;

public class exerc8 {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(System.in);

        float distanciaPercorrida, combustivelGasto;
        System.out.printf("Distancia percorrida: ");
        distanciaPercorrida = scanner.nextFloat();
        System.out.printf("Combustivel gasto: ");
        combustivelGasto = scanner.nextFloat();

        System.out.printf("Consumo médio: %.3f\n",
                           consumoMedio(distanciaPercorrida, combustivelGasto));

        scanner.close();
    }

    public static float consumoMedio( float distanciaPercorrida,
                                      float combustivelGasto)
    {
        return distanciaPercorrida / combustivelGasto;
    }
}
