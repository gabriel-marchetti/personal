package exercicios1;

import java.util.Scanner;

public class exerc4 {
    public static void main( String[] args ){
        Scanner scanner = new Scanner(System.in);
        int x, y;

        System.out.printf("Digite o valor de X: ");
        x = scanner.nextInt();
        System.out.printf("Digite o valor de Y: ");
        y = scanner.nextInt();

        System.out.printf("SOMA: %d\n", x + y);

        scanner.close();
    }
}
