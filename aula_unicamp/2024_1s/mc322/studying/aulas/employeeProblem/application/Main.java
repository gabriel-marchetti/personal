package application;

import java.util.Locale;
import java.util.Scanner;

import entities.Employee;

public class Main{
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        Employee employee = new Employee();
        System.out.print("Nome: ");
        employee.name = sc.nextLine();
        System.out.print("Salário Bruto: ");
        employee.grossSalary = sc.nextDouble();
        System.out.print("Tax: ");
        employee.tax = sc.nextDouble();

        System.out.println(employee);
        double increasePercentage;
        System.out.print("Qual a porcentagem para aumentar o salário: ");
        increasePercentage = sc.nextDouble();
        employee.increaseSalary(increasePercentage);
        System.out.println(employee);

        sc.close();
    }
}