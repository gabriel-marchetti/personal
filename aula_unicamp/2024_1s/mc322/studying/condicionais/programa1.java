package condicionais;

import java.util.Scanner;

public class programa1 {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in);
        int horas;

        System.out.printf("Que horas são? ");
        horas = sc.nextInt();

        if( horas > 24 ){
            System.out.println("Invalid input");
            sc.close();
            return;
        }

        if( horas < 12 ){
            System.out.println("Bom dia!");
        }
        else if( horas < 18 ){
            System.out.println("Boa tarde!");
        }
        else{
            System.out.println("Boa noite!");
        }

        sc.close();
    }
}
