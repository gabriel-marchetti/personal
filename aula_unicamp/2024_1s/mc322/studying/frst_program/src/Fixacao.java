import java.util.Locale;

public class Fixacao{
    public static void main( String[] args ){
        Locale.setDefault(Locale.US);

        String product1 = "Computer",
               product2 = "Office Desk";
        double price1 = 4020.0,
               price2 = 2500.0,
               measure = 53.243235237;
        int age = 30,
            code = 5290;
        char gender = 'F';

        System.out.println("Products:");
        System.out.printf(product1 + ": $" + price1 + "\n");
        System.out.printf(product2 + ": $" + price2 + "\n");

        System.out.println("Record: " + age + " years old, code " + code +
                            " and gender: " + gender);
        
        System.out.printf("Measure: %.4f cm\n", measure);
        

    }
}
