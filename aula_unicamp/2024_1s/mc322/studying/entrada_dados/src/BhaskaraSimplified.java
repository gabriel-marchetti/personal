import java.util.Locale;
import java.util.Scanner;

public class BhaskaraSimplified {
    public static void main( String[] args ){
        /*
         * It must have real solution for this code...
         */
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        double a, b, c, delta, x1, x2;
        
        System.out.println("Entre valor de a, b, c: ");
        a = sc.nextDouble();
        b = sc.nextDouble();
        c = sc.nextDouble();
        delta = Math.pow(b, 2) - 4 * a * c;
        delta = Math.sqrt(delta);
        x1 = ( -b + delta ) / ( 2 * a );
        x2 = ( -b - delta ) / ( 2 * a );

        System.out.println("Raízes: " + x1 + " " + x2);
        sc.close();
    }
}
