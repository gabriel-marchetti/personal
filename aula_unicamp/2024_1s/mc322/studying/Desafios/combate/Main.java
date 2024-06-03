import java.util.Scanner;

import assets.Champion;

public class Main {
    public static void main( String args[] ){
        Champion champ1, champ2;
        Scanner scanner = new Scanner(System.in);
        String tmp_string;
        Integer tmp_health, tmp_atack, tmp_armor;

        /* Scanning information of the first champion */        
        System.out.println("Digite os dados do primeiro campeão:");
        System.out.print("Nome: ");
        tmp_string = scanner.next();
        System.out.print("Vida Inicial: ");
        tmp_health = scanner.nextInt();
        System.out.print("Ataque: ");
        tmp_atack = scanner.nextInt();
        System.out.print("Armadura: ");
        tmp_armor = scanner.nextInt();
        champ1 = new Champion(tmp_string, tmp_health, tmp_atack, tmp_armor);
        System.out.println();

        /* Scanning information of the second champion */
        System.out.println("Digite os dados do segundo campeão:");
        System.out.print("Nome: ");
        tmp_string = scanner.next();
        System.out.print("Vida Inicial: ");
        tmp_health = scanner.nextInt();
        System.out.print("Ataque: ");
        tmp_atack = scanner.nextInt();
        System.out.print("Armadura: ");
        tmp_armor = scanner.nextInt();
        champ2 = new Champion(tmp_string, tmp_health, tmp_atack, tmp_armor);
        System.out.println();

        /* Turns */
        Integer numTurns;
        System.out.print("Quantos turnos você deseja executar? ");
        numTurns = scanner.nextInt();
        System.out.println();

        for( int i = 1; i <= numTurns; i++ ){
            if( champ1.getVida() == 0 || champ2.getVida() == 0 )
                break;
            champ1.takeDamage(champ2);
            champ2.takeDamage(champ1);

            System.out.println("Resultado do turno " + i + ":");
            System.out.println(champ1.status());
            System.out.println(champ2.status());
            System.out.println();
        }

        System.out.println("FIM DO COMBATE");
        scanner.close();
    }
}
