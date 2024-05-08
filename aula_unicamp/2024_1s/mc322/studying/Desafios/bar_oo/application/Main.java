package application;

import java.util.Locale;

import entities.Bill;

public class Main{
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Bill bill = new Bill();
        bill.lerDados();
        bill.printReport();
    }
}