package entities;

public class Student{
    public String name;
    public double frstGrade;
    public double scndGrade;
    public double thrdGrade;

    public double finalGrande(){
        return frstGrade + scndGrade + thrdGrade;
    }

    public boolean approved(){
        if( finalGrande() >= 60.0 )
            return true;
        return false;
    }

    public double necessaryPoints(){
        if( approved() )
            return 0.0;
        return 60.0 - finalGrande();
    }

}