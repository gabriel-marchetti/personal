package Desafios;

import java.util.Locale;
import java.util.Scanner;

public class Desafio_imposto {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        double renda, rendaServicos, ganhoCapital,
               gastosMedico, gastosEducacionais;

        System.out.printf("Renda anual com salário: ");
        renda = sc.nextDouble();
        System.out.printf("Renda anual com prestação de serviço: ");
        rendaServicos = sc.nextDouble();
        System.out.printf("Renda anual com ganho de capital: ");
        ganhoCapital = sc.nextDouble();
        System.out.printf("Gastos médicos: ");
        gastosMedico = sc.nextDouble();
        System.out.printf("Gastos educacionais: ");
        gastosEducacionais = sc.nextDouble();

        System.out.printf("\n");
        System.out.println("RELATÓRIO DE IMPOSTO DE RENDA");
        System.out.printf("\n");

        System.out.println("CONSOLIDADO DE RENDA:");
        double impostoRenda = calculaImpostoDeRenda( renda ),
               impostoServicos = calculaImpostoServicos( rendaServicos ),
               impostoCapital = calculaImpostoCapital( ganhoCapital );
        System.out.printf("Imposto sobre salário: %.2f%n", impostoRenda);
        System.out.printf("Imposto sobre serviços: %.2f%n", impostoServicos);
        System.out.printf("Imposto sobre ganho de capital: %.2f%n", impostoCapital);
        System.out.printf("\n");

        System.out.println("DEDUÇÕES:");
        double gastosRedutiveis = gastosEducacionais + gastosMedico,
               totalImposto = impostoRenda + impostoServicos + impostoCapital,
               maximoRedutivel = totalImposto * 0.3;
        System.out.printf("Máximo dedutível: %.2f%n", maximoRedutivel);
        System.out.printf("Gastos dedutíveis: %.2f%n", gastosRedutiveis);
        System.out.printf("\n");

        double abatimento = ( maximoRedutivel < gastosRedutiveis ) ?
                            maximoRedutivel : gastosRedutiveis;
        System.out.println("RESUMO:");
        System.out.printf("Imposto bruto total: %.2f%n", totalImposto);
        System.out.printf("Abatimento: %.2f%n", abatimento);
        System.out.printf("Imposto devido: %.2f%n", totalImposto - abatimento);

        sc.close();
    }

    private static double calculaImpostoDeRenda( double renda ){
        double rendaMensal = renda / 12.0;
        if( rendaMensal < 3000.0 )
            return 0.0;
        else if( rendaMensal <= 5000.0 )
            return renda * 0.1;
        else
            return renda * 0.2;
    }

    private static double calculaImpostoServicos( double rendaServicos ){
        return rendaServicos * 0.15;
    }

    private static double calculaImpostoCapital( double rendaCapital ){
        return rendaCapital * 0.20;
    }
}
