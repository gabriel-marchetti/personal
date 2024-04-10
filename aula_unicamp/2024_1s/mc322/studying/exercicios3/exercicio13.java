import java.util.Locale;
import java.util.Scanner;

public class exercicio13 {
    public static void main( String[] args ){
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        int cases;
        System.out.printf("Quantos casos você vai digitar? ");
        cases = sc.nextInt();
        for( int i = 0; i < cases; ++i){
            double grade1, grade2, grade3;
            grade1 = sc.nextDouble(); grade2 = sc.nextDouble();
            grade3 = sc.nextDouble();

            System.out.printf("MEDIA = %.1f\n",
                               weightedAverage(grade1, grade2, grade3));
        }

        sc.close();
    }

    public static double weightedAverage( double grade1, double grade2,
                                          double grade3 )
    {
        double weightedAvg = 0;
        weightedAvg += 2.0 * grade1;
        weightedAvg += 3.0 * grade2;
        weightedAvg += 5.0 * grade3;
        weightedAvg /= (2.0 + 3.0 + 5.0);

        return weightedAvg;
    }
}
