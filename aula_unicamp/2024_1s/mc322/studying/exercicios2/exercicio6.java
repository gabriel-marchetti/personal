import java.util.Locale;
import java.util.Scanner;

public class exercicio6 {
    public static void main( String[] args ){
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        float glicose;

        System.out.printf("Digite a medida da glicose: ");
        glicose = sc.nextFloat();

        if( glicose <= 0 ){
            System.out.printf("Impossível...%n");
        }
        else if( glicose <= 100 ){
            System.out.printf("Classificação: normal%n");
        }
        else if( glicose <= 140 ){
            System.out.printf("Classificação: elevado%n");
        }
        else{
            System.out.printf("Classificação: diabetes%n");
        }



        sc.close();
    }
}
