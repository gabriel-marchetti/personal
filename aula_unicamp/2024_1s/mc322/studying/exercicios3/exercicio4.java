import java.util.Scanner;

public class exercicio4 {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in);
        int x = 1, y = 1;
        while( true ){
            System.out.printf("Digite os valores das coordenadas de X e Y: ");
            x = sc.nextInt();
            y = sc.nextInt();
            if( x == 0 || y == 0 )
                break;
            System.out.printf("QUADRANTE %s\n", identifyQuadrant(x, y));
        }

        sc.close();
    }

    public static String identifyQuadrant( int x, int y ){
        if( x > 0 && y > 0 ){
            return "Q1";
        }
        else if( x < 0 && y > 0 ){
            return "Q2";
        }
        else if( x < 0 && y < 0 ){
            return "Q3";
        }
        else if( x > 0 && y < 0 ){
            return "Q4";
        }
        return " ";
    }
}
