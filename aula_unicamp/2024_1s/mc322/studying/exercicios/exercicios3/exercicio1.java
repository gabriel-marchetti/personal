import java.util.Scanner;

public class exercicio1{
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in);
        int x = 0, y = 1;
        while( true ){
            x = sc.nextInt();
            y = sc.nextInt();
            if( x == y ){
                break;
            }
            else if( x < y ){
                System.out.println("Crescente!");
            }
            else{
                System.out.println("Decrescente!");
            }
        }

        sc.close();
    }
}