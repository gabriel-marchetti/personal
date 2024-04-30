import java.util.Locale;
import java.util.Scanner;

public class Atletas {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner();
        
        int quantidadeAtletas;
        System.out.printf("Qual a quantidade de atletas? ");
        quantidadeAtletas = sc.nextInt();

        String nome;
        char sexo;
        double altura, peso;
        for( int atleta_i = 1; atleta_i <= quantidadeAtletas; atleta_i++)
        {
            System.out.printf("Nome: ");
            nome = sc.nextLine();
            System.out.printf("Sexo: ");
            sexo = sc.nextLine().charAt(0);
            while( sexo != 'F' && sexo != 'M' )
            {
                System.err.printf("Valor Inválido! Favor digitar F ou M: ");
                sexo = sc.nextLine().charAt(0);
            }
            System.out.printf("Altura: ");
            altura = sc.nextDouble();
            while( altura <= 0 )
            {
                System.out.printf("Valor Inválido! Favor digitar um valor positivo!");
                altura = sc.nextDouble();
            }
            // TODO: Preciso fazer a checagem do peso e fazer as partes
            // TODO: pedidas pelo exercício!

        }


        sc.close();
    }
}