package Serializer;

import java.beans.XMLDecoder;
import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;

import Assets.*;

public class DeserializerXML{
    public static void main(String[] args) {
        try{
            XMLDecoder xmlDecoder = new XMLDecoder(new BufferedInputStream(new FileInputStream("college.xml")));
            College c = (College)xmlDecoder.readObject();
        
            List<Student> s = c.getStudents();
            
            for( Student student : s ){
                System.out.println(student);
            }

            xmlDecoder.close();
        }
        catch( FileNotFoundException ex ){
            System.out.println("File not Found.");
        }

    }
}