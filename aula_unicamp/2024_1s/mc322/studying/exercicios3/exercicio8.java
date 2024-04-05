import java.util.Scanner;

public class exercicio8 {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in);
        int number;
        System.out.printf("Deseja a tabuada para qual valor? ");
        number = sc.nextInt();
        for( int i = 1; i <= 10; i++ ){
            System.out.printf("%d x %d = %d\n", number, i, number * i);
        }

        sc.close();
    }
}
