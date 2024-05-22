public class Consulta{
    private Integer idConsulta;
    private Animal animal;
    private Veterinario veterinario;
    private String data;
    private String hora;
    private String descricaoConsulta;

    public Consulta( Integer idConsulta, 
                     Animal animal, 
                     Veterinario veterinario,
                     String data,
                     String hora )
    {
        this.idConsulta = idConsulta;
        this.animal = animal;
        this.veterinario = veterinario;
        this.data = data;
        this.hora = hora;
        this.descricaoConsulta = "Ainda sem descrição.";
    }

    public Integer getIdConsulta()
    {
        return this.idConsulta;
    }

    public Animal getAnimal()
    {
        return this.animal;
    }

    public Veterinario getVeterinario()
    {
        return this.veterinario;
    }

    public String getData(){
        return this.data;
    }

    public String getHora(){
        return this.hora;
    }

    public void adicionaDescricao(String descricao)
    {
        this.descricaoConsulta = descricao;
    }
}