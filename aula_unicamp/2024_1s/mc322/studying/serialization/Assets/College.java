package Assets;

import java.util.List;

public class College{
    private List<Student> students;

    public void setStudents(List<Student> students){
        this.students = students;
    }

    public List<Student> getStudents(){
        return this.students;
    }

}