import java.util.Scanner;

public class exercicio6 {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in);
        int option = -1,
            alcool = 0,
            gasolina = 0,
            diesel = 0;
        
        while( option != 4 ){
            printMessage();
            option = sc.nextInt();
            switch (option) {
                case 1:
                    alcool++;
                    break;
                case 2:
                    gasolina++;
                    break;
                case 3:
                    diesel++;
                    break;
                default:
                    break;
            }
        }

        System.out.println("Muito Obrigado!");
        System.out.printf("Alcool: %d\n", alcool);
        System.out.printf("Gasolina: %d\n", gasolina);
        System.out.printf("Diesel: %d\n", diesel);

        sc.close();
    }

    private static void printMessage(){
        System.out.printf("Informe um código (1, 2, 3) ou 4 para parar: ");
    }
}
