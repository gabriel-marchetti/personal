import java.util.Locale;
import java.util.Scanner;

public class exercicio5 {
    public static void main( String[] args ){
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        float precoUnitario, qtdComprada, dinheiroRecebido, discriminante;
        System.out.printf("Preço Unitário do produto: ");
        precoUnitario = sc.nextFloat();
        System.out.printf("Quantidade comprada: ");
        qtdComprada = sc.nextFloat();
        System.out.printf("Dinheiro Recebido: ");
        dinheiroRecebido = sc.nextFloat();

        discriminante = dinheiroRecebido - qtdComprada * precoUnitario;
        if( discriminante < 0 ){
            System.out.printf("DINHEIRO INSUFICIENTE. FALTAM $%.2f reais %n", Math.abs(discriminante));
        }
        else{
            System.out.printf("TROCO: %.2f%n", Math.abs(discriminante));
        }

        sc.close();
    }
}
