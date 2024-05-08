package application;

import java.util.Locale;
import java.util.Scanner;
import entities.Calculator;

public class Main{
    public static final double PI = 3.14159;
    public static void main(String[] args){
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        Calculator calc = new Calculator();

        System.out.print("Enter radius: ");
        double radius = sc.nextDouble();

        // ! AGORA FAZ MAIS SENTIDO DA PALAVRA STATIC! 
        // ! Sempre que você não precisa instanciar objetos, então você deverá
        // ! utilizar métodos estáticos.
        double circumference = calc.computeCircumference(radius);
        double volumeSphere = calc.computeVolumeSphere(radius);

        System.out.printf("Circunferência: %.2f\n", circumference);
        System.out.printf("Volume: %.2f\n", volumeSphere);
        System.out.printf("Valor de PI: %.2f\n", PI);

        sc.close();
    }

    

    

}