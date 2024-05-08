package application;

import java.util.Locale;
import java.util.Scanner;

import entities.Student;

public class Main{
    public static void main(String[] args){
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        Student student = new Student();
        readStudentInfo(student, sc);
        System.out.printf("Nota final = %.2f\n", student.finalGrande());
        if( student.approved() ){
            System.out.println("PASS");
        }
        else{
            System.out.println("FAILED");
            System.out.printf("FALTARAM %.2f PONTOS\n", student.necessaryPoints());
        }

        sc.close();
    }
    
    public static void readStudentInfo(Student student, Scanner sc){
        System.out.print("Nome: ");
        student.name = sc.nextLine();
        System.out.print("Primeira Nota: ");
        student.frstGrade = sc.nextDouble();
        System.out.print("Segunda Nota: ");        
        student.scndGrade = sc.nextDouble();
        System.out.print("Terceira Nota: ");
        student.thrdGrade = sc.nextDouble();
    }
}