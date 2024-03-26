import java.util.Locale;
import java.util.Scanner;

public class exercicio7 {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        double dist1, dist2, dist3, greater;

        System.out.println("Digite as tres distancias: ");
        dist1 = sc.nextDouble();
        dist2 = sc.nextDouble();
        greater = ( dist2 > dist1 ) ? dist2 : dist1;
        dist3 = sc.nextDouble();
        greater = ( dist3 > greater ) ? dist3 : greater;

        System.out.printf("MAIOR DISTANCIA = %.2f%n", greater);

        sc.close();
    }
}
