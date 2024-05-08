import java.util.Scanner;

public class exercicio3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int senhaCorreta = 2002, senhaTentativa = 0;

        System.out.println("Digite a senha: ");
        while( senhaCorreta != senhaTentativa ){
            senhaTentativa = sc.nextInt();
            if( senhaCorreta == senhaTentativa ){
                System.out.println("Acesso Permitido!");
            }
            else{
                System.out.println("Senha Inválida! Tente Novamente: ");
            }
        }

        sc.close();
    }
}
