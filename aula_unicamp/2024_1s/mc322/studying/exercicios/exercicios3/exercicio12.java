import java.util.Scanner;

public class exercicio12 {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in);
        int N, num;
        System.out.printf("Quantos números você vai digitar? ");
        N = sc.nextInt();
        String cardinality, sign;
        for( int i = 0; i < N; ++i ){
            System.out.printf("Digite um número: ");
            num = sc.nextInt();
            if( num == 0 ){
                System.out.println("NULO");
                continue;
            }
            if( num < 0 ) sign = "NEGATIVO";
            else sign = "POSITIV0";

            if( num % 2 == 1 ) cardinality = "IMPAR";
            else cardinality = "PAR";

            System.out.println(cardinality + ' ' + sign);
        }

        sc.close();
    }
}
