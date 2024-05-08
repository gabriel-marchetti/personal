package application;

import java.util.Locale;
import java.util.Scanner;

public class Main{
    public static final double PI = 3.14159;
    public static void main(String[] args){
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter radius: ");
        double radius = sc.nextDouble();

        double circumference = computeCircumference(radius);
        double volumeSphere = computeVolumeSphere(radius);

        System.out.printf("Circunferência: %.2f\n", circumference);
        System.out.printf("Volume: %.2f\n", volumeSphere);
        System.out.printf("Valor de PI: %.2f\n", PI);

        sc.close();
    }

    public static double computeCircumference(double radius){
        return 2.0 * PI * radius;
    }

    public static double computeVolumeSphere(double radius){
        return 4.0 * PI * radius * radius * radius / 3.0;
    }

}