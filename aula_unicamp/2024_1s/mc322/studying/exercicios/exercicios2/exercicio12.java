import java.util.Scanner;

public class exercicio12 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int horaInicial, horaFinal, total;
        System.out.printf("Hora inicial: "); horaInicial = sc.nextInt();
        System.out.printf("Hora final: "); horaFinal = sc.nextInt();

        total = ( horaInicial < horaFinal ) ?
                horaFinal - horaInicial :
                (24 - horaInicial) + horaFinal;

        System.out.printf("O JOGO DUROU %d HORA(S)%n", total);

        sc.close();
    }
}
