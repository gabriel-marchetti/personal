import java.util.Locale;
import java.util.Scanner;

public class Main{
    public static void main( String[] args ){
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        int x;
        String s;
        x = sc.nextInt();
        s = sc.next();
        System.out.println(2*x);
        System.out.println(s);
        
        sc.close();
    }
}