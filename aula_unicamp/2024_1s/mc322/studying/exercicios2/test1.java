import java.util.Scanner;

public class test1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int entrada;
        String diaSemana;
        entrada = sc.nextInt();

        switch (entrada) {
            case 1:
                diaSemana = "domingo";
                break;
            case 2:
                diaSemana = "segunda";
                break;
            case 3:
                diaSemana = "terça";
                break;
            case 4:
                diaSemana = "quarta";
                break;
            case 5:
                diaSemana = "quinta";
                break;
            case 6:
                diaSemana = "sexta";
                break;
            case 7:
                diaSemana = "sabado";
                break;
            default:
                diaSemana = "undef";
                break;
        }
        System.out.println("Dia da semana: " + diaSemana);

        sc.close();
    }
}
