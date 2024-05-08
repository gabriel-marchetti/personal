package entities;

public class Calculator{

    private static final double PI = 3.14159;

    public double computeCircumference(double radius){
        return 2.0 * PI * radius;
    }

    public double computeVolumeSphere(double radius){
        return 4.0 * PI * radius * radius * radius / 3.0;
    }

}