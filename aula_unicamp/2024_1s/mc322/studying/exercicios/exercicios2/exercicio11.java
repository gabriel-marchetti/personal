import java.util.Locale;
import java.util.Scanner;

public class exercicio11 {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        float salario, newSalario;
        int perc;
        System.out.printf("Salario atual: ");
        salario = sc.nextFloat();
        
        if( salario <= 1000f ){
            perc = 20;
            newSalario = salario * 1.20f;
        }
        else if( salario <= 3000f ){
            perc = 15;
            newSalario = salario * 1.15f;
        }
        else if( salario <= 8000f ){
            perc = 10;
            newSalario = salario * 1.10f;
        }
        else{
            perc = 5;
            newSalario = salario * 1.05f;
        }

        System.out.printf("Novo salário: R$%.2f%n", newSalario);
        System.out.printf("Aumento: R$%.2f%n", newSalario - salario);
        System.out.printf("Porcentagem: %d%%%n", perc);

        sc.close();
    }
}
