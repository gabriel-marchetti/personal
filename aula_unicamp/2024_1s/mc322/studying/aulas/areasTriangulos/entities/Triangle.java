package entities;

public class Triangle{
    public Double a;
    public Double b;
    public Double c;

    public Double computeArea(){
        Double p = (a + b + c) / 2.0;
        p = p * ( p - a ) * ( p - b ) * ( p - c );
        return Math.sqrt(p);
    }
}