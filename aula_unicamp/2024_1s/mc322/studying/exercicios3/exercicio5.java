import java.util.Scanner;

public class exercicio5 {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in);
        boolean validationGrade1 = false, validationGrade2 = false;
        float grade1 = 0, grade2 = 0;

        while( !validationGrade1 || !validationGrade2 ){
            if( !validationGrade1 ){
                System.out.printf("Digite a primeira nota: ");
                grade1 = sc.nextFloat();
                validationGrade1 = validateGrade(grade1);
            }
            else{
                System.out.printf("Digite a segunda nota: ");
                grade2 = sc.nextFloat();
                validationGrade2 = validateGrade(grade2);
            }
        }

        System.out.printf("MEDIA = %.2f\n", gradeMean(grade1, grade2));

        sc.close();
    }

    public static boolean validateGrade( float grade ){
        return grade >= 0 && grade <= 10; 
    }

    public static float gradeMean( float... grades ){
        float sum = 0, size = 0;
        for( float grade : grades ){
            sum += grade;
            size++;
        }
        return sum / size;
    }
}
