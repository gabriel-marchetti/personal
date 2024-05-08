package entities;

public class CurrencyConverter{
   private static double USD_TO_BRL = 5.3;

   public static double getUSDToBRL(){
        return USD_TO_BRL;
   }

   public static double convertUSDToBRL( double valueUSD ){
        return valueUSD * USD_TO_BRL;
   }

}