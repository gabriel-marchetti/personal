import java.util.Scanner;

public class exercicio14 {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in);
        int N;
        System.out.printf("Digite N: ");
        N = sc.nextInt();
        if( N < 0 ){
            System.out.println("Fatorial não pode ser negativo.");
            sc.close();
            return;
        }
        if( N > 15 ){
            System.out.println("N não deve ser maior que 15.");
            sc.close();
            return;
        }

        System.out.printf("FATORIAL = %d\n", fatorial(N));

        sc.close();
    }

    public static int fatorial( int n ){
        if( n == 0 )
            return 1;
        return n * fatorial( n-1 );
    }
}
