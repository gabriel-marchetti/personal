package exercicios1;

import java.util.Locale;
import java.util.Scanner;

public class exerc3 {
    public static void main( String[] args ){
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(System.in);

        String firstName, secondName;
        int firstAge, secondAge;

        System.out.println("Dados da primeira pessoa:");
        System.out.printf("Nome: ");
        firstName = scanner.nextLine();
        System.out.printf("Idade: ");
        firstAge = scanner.nextInt();
        scanner.nextLine();

        System.out.println("Dados da segunda pessoa:");
        System.out.printf("Nome: ");
        secondName = scanner.nextLine();
        System.out.printf("Idade: ");
        secondAge = scanner.nextInt();
        scanner.nextLine();
        
        System.out.printf("Idade média de " + firstName + " e " + secondName
                           + " é %.1f anos\n", mean(firstAge, secondAge));

        scanner.close();
    }

    public static float mean( float value1, float value2 ){
        return (value1 + value2) / 2 ;
    }
}
