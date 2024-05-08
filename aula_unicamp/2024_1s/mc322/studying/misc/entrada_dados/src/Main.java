import java.util.Locale;
import java.util.Scanner;
import java.lang.Math;

public class Main{
    public static void main(String[] args){
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        char firstLetter;
        firstLetter = sc.next().charAt(0);
        System.out.println("First Char: " + firstLetter);

        double cateto1, cateto2, hipotenusa;
        cateto1 = sc.nextDouble();
        cateto2 = sc.nextDouble();
        hipotenusa = calculaHipotenusa(cateto1, cateto2);
        System.out.printf("Hipotenusa: %.2f%n", hipotenusa);

        sc.close();
    }

    private static double calculaHipotenusa( double cateto1, double cateto2 ){
        double hipotenusa = cateto1*cateto1 + cateto2*cateto2;
        
        return Math.sqrt(hipotenusa);
    }
}