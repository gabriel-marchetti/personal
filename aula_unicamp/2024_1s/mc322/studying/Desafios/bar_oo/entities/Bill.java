package entities;

import java.util.Scanner;

public class Bill{
    private static final double PRECO_CERVEJA = 5.0;
    private static final double PRECO_REFRIGERANTE = 3.0;
    private static final double PRECO_ESPETINHO = 7.0;
    private static final double PRECO_COUVERT = 4.0;
    private static final double PRECO_INGRESSO_HOMEM = 10.0;
    private static final double PRECO_INGRESSO_MULHER = 8.0;
    public char gender;
    public int numBeers;
    public int numBarbecue;
    public int numSoftDrink;

    public void lerDados(){
        Scanner sc = new Scanner(System.in);
        char gender = 'A';
        System.out.print("Sexo (F ou M): ");
        while( gender != 'F' && gender != 'M' ){
            gender = sc.nextLine().charAt(0);
        }
        this.gender = gender;
        
        int tmp = -1;
        System.out.print("Quantidade de cervejas: ");
        while( !validNumber(tmp) ){
            tmp = sc.nextInt();
        }
        this.numBeers = tmp;

        tmp = -1; // Validar novo produto
        System.out.print("Quantidade de refrigerantes: ");
        while( !validNumber(tmp) ){
            tmp = sc.nextInt();
        }
        this.numSoftDrink = tmp;

        tmp = -1; // Validar novo produto
        System.out.print("Quantidade de espetinhos: ");
        while( !validNumber(tmp) ){
            tmp = sc.nextInt();
        }
        this.numBarbecue = tmp;

        sc.close();
    }

    private double computeConsumo(){
        return this.numBeers * PRECO_CERVEJA
               + this.numSoftDrink * PRECO_REFRIGERANTE
               + this.numBarbecue * PRECO_ESPETINHO;
    }

    private double ticketPrice(){
        if( this.gender == 'F' )
            return PRECO_INGRESSO_MULHER;
        return PRECO_INGRESSO_HOMEM;
    }

    public void printReport(){
        boolean couvertAdded = true;

        double ingresso = ticketPrice();
        double consumo = computeConsumo();
        double finalBill = 0;
        if( consumo > 30 ) couvertAdded = false;

        System.out.println("\nRELATÓRIO:");
        System.out.printf("Consumo = R$ %.2f\n", consumo);
        finalBill += consumo;
        if( couvertAdded ){
            System.out.printf("Couvert = R$ %.2f\n", PRECO_COUVERT);
            finalBill += PRECO_COUVERT;
        }
        else
            System.out.println("Isento de Couvert.");
        System.out.printf("Ingresso = R$ %.2f\n", ingresso);
        finalBill += ingresso;
        System.out.println();
        
        System.out.printf("Valor a pagar = R$ %.2f\n", finalBill);
    }

    private boolean validNumber( int number ){
        if( number < 0 )
            return false;
        return true;
    }
}
