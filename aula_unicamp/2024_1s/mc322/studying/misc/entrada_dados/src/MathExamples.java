import java.util.Locale;
import java.util.Scanner;

public class MathExamples {
    public static void main( String[] args ){
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        
        double b, h, area;
        System.out.println("Calcular Area Triangulo");
        System.out.printf("Qual altura: ");
        h = sc.nextDouble();
        System.out.printf("Qual base: ");
        b = sc.nextDouble();

        area = ( b * h ) / 2.0;
        System.out.println("Area: " + area);

        double base, expoente, resultado;
        System.out.println("Calcular exponenciacao: ");
        System.out.printf("Qual base: ");
        base = sc.nextDouble();
        System.out.printf("Qual expoente: ");
        expoente = sc.nextDouble();
        resultado = Math.pow(base, expoente);
        System.out.println("Exponenciacao: " + resultado);

        sc.close();
    }
}
