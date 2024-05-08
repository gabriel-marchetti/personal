package exercicios2;

import java.util.Locale;
import java.util.Scanner;

public class exercicio1 {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(System.in);

        float firstGrade, secondGrade, finalGrade;
        System.out.printf("Digite a primeira nota: ");
        firstGrade = scanner.nextFloat();
        System.out.printf("Digite a segunda nota: ");
        secondGrade = scanner.nextFloat();
        
        finalGrade = (firstGrade + secondGrade) / 2;
        System.out.printf("NOTA FINAL: %.1f%n", finalGrade);
        if( finalGrade < 60.0 )
            System.out.println("REPROVADO");
        scanner.close();
    }
}
