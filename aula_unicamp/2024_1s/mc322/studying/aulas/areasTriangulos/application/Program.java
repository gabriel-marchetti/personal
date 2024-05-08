package application;

import java.util.Locale;
import java.util.Scanner;

public class Program{
    public static void main(String[] args) {
        /*
         * Jeito sem OOP para resolver problema dos triângulos.
        */
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        Double xA, xB, xC, yA, yB, yC;
        System.out.println("Enter sides of the first Triangle.");
        xA = sc.nextDouble();
        xB = sc.nextDouble();
        xC = sc.nextDouble();

        System.out.println("Enter sides of the second Triangle.");
        yA = sc.nextDouble();
        yB = sc.nextDouble();
        yC = sc.nextDouble();

        Double frstArea = areaTriangle(xA, xB, xC),
               scndArea = areaTriangle(yA, yB, yC);
        
        System.out.printf("Area triangle X: %.2f\n", frstArea);
        System.out.printf("Area triangle Y: %.2f\n", scndArea);
        sc.close();
    }

    public static Double areaTriangle( double a, double b, double c ){
        // * Use the Heron formula for calculate the area of the triangle.
        Double p = (a + b + c) / 2.0;
        p = p * ( p - a ) * ( p - b ) * ( p - c );
        return Math.sqrt(p);
    }
}