import java.io.IOException;
import java.util.Scanner;

public class exercicio7 {
    public static void main( String[] args ) throws IOException{
        Scanner sc = new Scanner(System.in);
        int number = -1;
        number = sc.nextInt();
        while( number != 0 ){
            System.out.printf("%d\n", sumFiveConsecutivesEvens(number));
            number = sc.nextInt();
        }

        sc.close();
    }

    /**
     * Uma forma mais otimizada de fazer isso é através da fórmula:
     * f(x) = 5*x + 20
     * 
     * @param x
     * @return
     */
    public static int sumFiveConsecutivesEvens( int x ){
        if( Math.abs(x) % 2 == 1 )
            x++;
        int soma = 0;
        for(int i = 0; i < 5; i++){
            soma += x + 2*i;
        }
        return soma;
    }
}
