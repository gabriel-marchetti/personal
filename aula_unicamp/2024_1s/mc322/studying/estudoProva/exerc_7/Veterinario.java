public class Veterinario
{
    private Integer id;
    private String nome;
    private String especialidade;

    public Veterinario(Integer id, String nome, String especialidade)
    {
        this.id = id;
        this.nome = nome;
        this.especialidade = especialidade;
    }

    public Integer getId()
    {
        return this.id;
    }

    public String getNome()
    {
        return this.nome;
    }

    public String getEspecialidade()
    {
        return this.especialidade;
    }

    public String toString()
    {
        String tmp = new String();
        tmp += "{ ";
        tmp += "Nome: " + this.nome + ", ";
        tmp += "Id: " + this.id + ", ";
        tmp += "Especialidade: " + this.especialidade + "}";

        return tmp;
    }

}