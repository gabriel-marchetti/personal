import java.util.*;

public class src{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in).useLocale(Locale.US);
        Locale.setDefault(Locale.US);
        Double d = sc.nextDouble();

        System.out.printf("%7.3f\n", d);

        sc.close();
    }
}