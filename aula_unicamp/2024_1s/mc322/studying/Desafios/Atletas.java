import java.util.Locale;
import java.util.Scanner;

public class Atletas {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        
        int quantidadeAtletas;
        System.out.printf("Qual a quantidade de atletas? ");
        quantidadeAtletas = sc.nextInt();

        String nome, atleta_mais_alto = null;
        char sexo;
        double altura, peso, peso_medio = 0, num_homems = 0, num_mulheres = 0,
               altura_atleta_mais_alto = -1, altura_media_mulheres = 0;
        for( int atleta_i = 1; atleta_i <= quantidadeAtletas; atleta_i++)
        {
            System.out.printf("Digite os dados do atleta numero %d:\n", atleta_i);
            System.out.printf("Nome: ");
            sc.nextLine();
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
                System.out.printf("Valor Inválido! Favor digitar um valor positivo: ");
                altura = sc.nextDouble();
            }
            System.out.printf("Peso: ");
            peso = sc.nextDouble();
            while( peso <= 0 )
            {
                System.out.printf("Valor Inválido! Favor digitar um valor positivo: ");
                peso = sc.nextDouble();
            }

            // * Checagem do Exercício!
            if( sexo == 'F' )
            {
                num_mulheres++;
                altura_media_mulheres += altura;
            }
            else
            {
                num_homems++;
            }

            if( altura > altura_atleta_mais_alto )
            {
                atleta_mais_alto = nome;
                altura_atleta_mais_alto = altura;
            }
            peso_medio += peso;
        }

        double num_atletas = num_homems + num_mulheres;
        System.out.println("RELATÓRIO:");
        System.out.printf("Peso médio dos atletals: %.2f\n", peso_medio / num_atletas );
        System.out.printf("Atleta mais alto: %s\n", atleta_mais_alto);
        System.out.printf("Porcentagem de homens: %.1f%%\n", num_homems / num_atletas * 100 );
        if( num_mulheres == 0 ){
            System.out.println("Não há mulheres cadastradas");
        }
        else{
            System.out.printf("Altura média das mulheres: %.2f\n", altura_media_mulheres / num_mulheres );
        }


        sc.close();
    }
}