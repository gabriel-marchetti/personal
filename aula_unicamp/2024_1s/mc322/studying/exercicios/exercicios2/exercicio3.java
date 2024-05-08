import java.util.Scanner;

public class exercicio3 {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in);
        int a, b, c, menor;

        System.out.printf("Primeiro valor: ");
        a = sc.nextInt();
        System.out.printf("Segundo valor: ");
        b = sc.nextInt();
        System.out.printf("Terceiro valor: ");
        c = sc.nextInt();

        menor = Math.min(a, Math.min(b, c));
        System.out.printf("MENOR = %d%n", menor);

        sc.close();
    }
}
