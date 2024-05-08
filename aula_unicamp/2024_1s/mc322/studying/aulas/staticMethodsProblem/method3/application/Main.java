package application;

import java.util.Locale;
import java.util.Scanner;
import entities.Calculator;

public class Main{
    public static final double PI = 3.14159;
    public static void main(String[] args){
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter radius: ");
        double radius = sc.nextDouble();

        double circumference = Calculator.computeCircumference(radius);
        double volumeSphere = Calculator.computeVolumeSphere(radius);

        System.out.printf("Circunferência: %.2f\n", circumference);
        System.out.printf("Volume: %.2f\n", volumeSphere);
        System.out.printf("Valor de PI: %.2f\n", PI);

        sc.close();
    }

}