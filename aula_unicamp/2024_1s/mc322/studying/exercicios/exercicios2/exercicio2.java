package exercicios2;

import java.util.Locale;
import java.util.Scanner;

public class exercicio2 {
    public static void main( String[] args ){
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        float a, b, c, delta, x1, x2;
        System.out.printf("Coeficiente a: ");
        a = sc.nextFloat();
        System.out.printf("Coeficiente b: ");
        b = sc.nextFloat();
        System.out.printf("Coeficiente c: ");
        c = sc.nextFloat();

        delta = b * b - 4 * a * c;
        if( delta < 0 )
            System.out.println("nao possui raizes reais");
        else if( approx( (double) delta , 0 ) ){
            x1 = ( -b ) / ( 2*a );
            System.out.printf("Unica raiz: %.4f%n", x1);
        }
        else{
            delta = (float) Math.sqrt(delta);
            x1 = ( -b + delta ) / ( 2*a );
            x2 = ( -b - delta ) / ( 2*a );
            System.out.printf("Raiz 1: %.4f%n", x1);
            System.out.printf("Raiz 2: %.4f%n", x2);
        }


        sc.close();
    }

    public static final double error = Math.pow(10, -8);
    public static boolean approx( double val1, double val2 ){
        boolean sentence = ( val1 > val2 - error ) && ( val1 < val2 + error );
        return sentence;
    }
}
