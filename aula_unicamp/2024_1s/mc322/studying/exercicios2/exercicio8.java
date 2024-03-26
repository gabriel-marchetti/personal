import java.util.Locale;
import java.util.Scanner;

public class exercicio8 {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        char decision;
        double temperature;
        
        System.out.printf("Qual escala você vai usar (C/F)? ");
        decision = sc.next().charAt(0);
        switch (decision) {
            case 'F':
                System.out.printf("Digite a temperatura em Fahrenheit: ");
                temperature = sc.nextDouble();
                temperature = FahnToCelsius( temperature );
                System.out.printf("Temperatura equivalente em Celsius %.2f%n",
                                  temperature);
                break;
            case 'C':
                System.out.printf("Digite a temperatura em Celsius: ");
                temperature = sc.nextDouble();
                temperature = CelsiusToFahn( temperature );
                System.out.printf("Temperatura equivalente em Fahn %.2f%n",
                                  temperature);
                break;
            default:
                System.out.println("Invalid Option.");
                break;
        }

        sc.close();
    }

    private static double FahnToCelsius( double Fahn ){
        return 5.0 / 9.0 * ( Fahn - 32.0 );
    }

    private static double CelsiusToFahn( double Celsius ){
        return 9.0 / 5.0 * Celsius + 32.0;
    }
}
