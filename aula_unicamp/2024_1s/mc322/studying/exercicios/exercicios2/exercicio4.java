import java.util.Locale;
import java.util.Scanner;

public class exercicio4 {
    public static void main( String[] args ){
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        int totalMinutes;
        float totalToPay;

        System.out.printf("Digite a quantidade de minutos: ");
        totalMinutes = sc.nextInt();
        if( totalMinutes < 0 ){
            totalToPay = 0f;
        }
        else if ( totalMinutes <= 100 ){
            totalToPay = 50f;
        } else{
            totalToPay = (float) 50 + (totalMinutes - 100)*2;
        }

        System.out.printf("Valor a paga: $%.2f%n", totalToPay);

        sc.close();
    }
}
