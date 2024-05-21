package Assets;

public class Student{
    private Integer rollNumber;
    private String name;

    public void setRollNumber(Integer rollNumber){
        this.rollNumber = rollNumber;
    }

    public Integer getRollNumber(){
        return this.rollNumber;
    }

    public void setName(String name){
        this.name = name;
    }

    public String getName(){
        return this.name;
    }

    public String toString(){
        String tmp = new String();
        tmp += "-------Student-------\n";
        tmp += "Nome: " + this.name + '\n';
        tmp += "Roll Number: " + this.rollNumber + '\n';

        return tmp;
    }

}