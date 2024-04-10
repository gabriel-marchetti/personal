import java.util.Scanner;

public class exercicio11 {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in);
        int N, num, in = 0, out = 0;
        N = sc.nextInt();
        for( int i = 0; i < N; ++i ){
            num = sc.nextInt();
            if( 10 <= num && num <= 20 )
                in++;
            else
                out++;
        }

        System.out.println( in + " Dentro");
        System.out.println( out + " Fora");

        sc.close();
    }
}
