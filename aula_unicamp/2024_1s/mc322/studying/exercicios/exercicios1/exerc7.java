package exercicios1;

import java.util.Locale;
import java.util.Scanner;

public class exerc7 {
    public static void main( String[] args ){
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(System.in);

        String nome;
        int horasTrabalhadas;
        double valorHora;

        System.out.printf("Nome: ");
        nome = scanner.nextLine();
        System.out.printf("Valor por hora: ");
        valorHora = scanner.nextDouble();
        System.out.printf("Horas Trabalhadas: ");
        horasTrabalhadas = scanner.nextInt();

        System.out.printf("O pagamento de %s deve ser %.2f\n", nome, valorHora * horasTrabalhadas);

        scanner.close();
    }
}
