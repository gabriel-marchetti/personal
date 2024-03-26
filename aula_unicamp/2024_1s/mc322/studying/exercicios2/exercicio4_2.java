import java.util.Locale;
import java.util.Scanner;

public class exercicio4_2 {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        double conta = 50.0;
        int minutos;
        minutos = sc.nextInt();
        conta += ( minutos > 100 ) ? (minutos - 100)*2.0 : 0;
        System.out.printf("R$%.2f%n", conta);

        sc.close();
    }
}
