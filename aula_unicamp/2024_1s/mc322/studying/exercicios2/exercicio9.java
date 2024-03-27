import java.util.Locale;
import java.util.Scanner;

public class exercicio9 {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        float[] prices = {5f, 3.5f, 4.8f, 8.9f, 7.32f};
        float total, partial;
        int numProducts, codeProduct, qtProduct;
        
        System.out.printf("Quantos produtos vocês comprou? ");
        numProducts = sc.nextInt();
        total = 0f;
        for( int i = 0; i < numProducts; i++ ){
            partial = 0f;
            System.out.printf("Código do produto: ");
            codeProduct = sc.nextInt();
            System.out.printf("Quantidade Comprada: ");
            qtProduct = sc.nextInt();

            codeProduct--; // 0-index prices.
            partial = qtProduct * prices[codeProduct];
            codeProduct++; // For printing.
            System.out.printf("Produto %d: R$%.2f\n", codeProduct, partial);

            total += partial;
        }
        System.err.printf("Total: R$%.2f%n", total);

        sc.close();
    }
}
