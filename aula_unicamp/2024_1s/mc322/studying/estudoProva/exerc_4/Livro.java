import java.util.Scanner;

public class Livro{
    private String nome;
    private Integer id;

    public String getNome(){
        return this.nome;
    }

    public void setNome( String nome ){
        this.nome = nome;
    }

    public Integer getId(){
        return this.id;
    }

    public void setId(Integer id){
        Scanner sc = new Scanner(System.in);
        Character decisao = 'A';
        while( (!decisao.equals('S')) && (!decisao.equals('N')) ){
            decisao = sc.next().charAt(0);
        }
        if( decisao.equals('N') ) return;
        this.id = id;
    }

}