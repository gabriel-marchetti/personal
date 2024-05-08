import java.util.Locale;
import java.util.Scanner;

public class exercicio2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Locale.setDefault(Locale.US);

        int age = 0, people = 0;
        float meanAge = 0;

        while( true ){
            age = sc.nextInt();
            if( age < 0 )
                break;

            meanAge += (float) age; 
            people++;
        }

        if( people == 0 ){
            System.out.println("IMPOSSIVEL CALCULAR");
        }
        else{
            meanAge /= people;
            System.out.printf("MEDIA = %.2f\n", meanAge);
        }

        sc.close();
    }
}
