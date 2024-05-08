package application;

import java.util.Locale;
import java.util.Scanner;

import entities.Triangle;

public class Program1{
    public static void main(String[] args) {
        /*
         * Jeito sem OOP para resolver problema dos triângulos.
        */
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        Triangle x = new Triangle(), y = new Triangle();
        System.out.println("Enter sides of the first Triangle.");
        x.a = sc.nextDouble();
        x.b = sc.nextDouble();
        x.c = sc.nextDouble();

        System.out.println("Enter sides of the second Triangle.");
        y.a = sc.nextDouble();
        y.b = sc.nextDouble();
        y.c = sc.nextDouble();
        
        System.out.printf("Area triangle X: %.2f\n", x.computeArea());
        System.out.printf("Area triangle Y: %.2f\n", y.computeArea());
        sc.close();
    }
}