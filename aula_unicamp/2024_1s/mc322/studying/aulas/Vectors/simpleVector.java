import java.util.Locale;
import java.util.Scanner;

public class simpleVector{
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(System.in);

        System.out.print("Number of people: ");
        Integer n = scanner.nextInt();
        Double[] heightVect = new Double[n];

        for( int i = 0; i < n; ++i ){
            heightVect[i] = scanner.nextDouble();
        }
        
        Double totalHeight = 0.0;
        for( int i = 0; i < n; ++i ){
            totalHeight += heightVect[i];
        }
        Double avgHeight = totalHeight / n;

        System.out.println("Average height: " + avgHeight);

        scanner.close();
    }
}