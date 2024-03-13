import java.util.Locale;

public class Main {
    public static void main(String[] args) {
        /*
         * Every Java program must have a class
         * Every Java program must have one public static void...
         * println basicamente coloca um '\n' no final da string. (*)
         */
        System.out.print("Hello World!");
        /*
         * Printing without breakline
         */
        System.out.println("Hello World!");
        /*
         * Printing format 
         * %n: funciona para quebrar linha
         * \n: funciona para quebrar linha
         */
        double pi = 3.14159;
        System.out.printf("%.2f\n", pi);
        System.out.printf("%.4f%n", pi);
        /*
         * Colocando comando para substituir ',' por '.'
         * O Java utiliza o padrão do seu computador para numéricos.
         */
        Locale.setDefault(Locale.US);
        System.out.printf("%.2f\n", pi);
        System.out.printf("%.4f%n", pi);
        /*
         * Juntando valores
         */
        System.out.println("Valor de pi: " + pi);
        /*
         * Usando printf
         */
        double sqrt2 = 1.414,
               sqrt5 = 2.236;
        System.out.printf("Raiz de 2: %.2f   Raiz de 5: %.2f%n", sqrt2, sqrt5);
        /*
         * Printando uma mensagem mais completa.
         */
        String nome = "Maria";
        int idade = 30;
        double salario = 5000.0;
        System.out.printf("%s tem %d anos e ganha %.2f reais por mês!\n", nome, idade, salario);
    }
}
