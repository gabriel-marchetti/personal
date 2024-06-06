package Exercises;

import java.util.Locale;
import java.util.Scanner;

public class Exercise1{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in).useLocale(Locale.US);
        
        System.out.print("Quantos numeros voce ira digitar: ");
        Integer n = scanner.nextInt();
        Integer[] vect = new Integer[n];

        for( int i = 0; i < vect.length; ++i ){
            vect[i] = scanner.nextInt();
        }

        System.out.println("NUMEROS NEGATIVOS");
        for( int i = 0; i < vect.length; ++i ){
            if( vect[i] < 0 )
                System.out.println(vect[i]);
        }

        scanner.close();
    }
}