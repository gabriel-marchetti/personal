import java.util.Scanner;

public class exercicio10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int firstNum, secondNum;

        System.out.println("Digite dois números inteiros:");
        firstNum = sc.nextInt();
        secondNum = sc.nextInt();
        if( firstNum % secondNum == 0 || secondNum % firstNum == 0 ){
            System.out.println("Múltiplos!");
        }
        else{
            System.out.println("Não são múltiplos!");
        }

        sc.close();
    }
}
