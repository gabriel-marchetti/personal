package exercicios1;

import java.util.Scanner;

public class exerc10 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int segundosTotal, segundos, minutos, horas;
        
        System.out.printf("Digite o tempo total em segundos: ");
        segundosTotal = scanner.nextInt();

        segundos = segundosTotal % 60;
        minutos = segundosTotal / 60;
        horas = minutos / 60;
        minutos = minutos % 60;

        System.out.printf("%02d:%02d:%02d%n", horas, minutos, segundos);

        scanner.close();
    }
}
