import java.util.Scanner;

public class exercicio9 {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in);
        int X, Y, greater, smaller;
        System.out.println("Digite dois números ");
        X = sc.nextInt();
        Y = sc.nextInt();
        greater = Math.max( X, Y );
        smaller = Math.min( X, Y);

        int sum = 0;
        for(int i = smaller+1; i < greater; ++i){
            if( i % 2 == 1 || i % 2 == -1 ){
                sum += i;
            }
        }

        System.out.printf("SOMA DOS IMPARES: %d\n", sum);

        sc.close();
    }
}
