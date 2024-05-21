package Serializer;

import Assets.Student;

import java.beans.XMLEncoder;
import java.io.BufferedOutputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.List;

import Assets.College;

public class SerializerXML {
    public static void main(String[] args) {
        try{
            Student st1 = new Student();
            st1.setRollNumber(101);
            st1.setName("Carlos");

            Student st2 = new Student();
            st2.setRollNumber(102);
            st2.setName("Eduardo");

            List<Student> s = new ArrayList<>();
            s.add(st1);
            s.add(st2);

            College c = new College();
            c.setStudents(s);
            
            XMLEncoder xmlEncoder = new XMLEncoder(new BufferedOutputStream(new FileOutputStream("college.xml")));
            xmlEncoder.writeObject(c);
            xmlEncoder.close();

        }
        catch ( FileNotFoundException ex ){
            System.out.println("Problema em abrir serializador.");
        }
            
    }
}
