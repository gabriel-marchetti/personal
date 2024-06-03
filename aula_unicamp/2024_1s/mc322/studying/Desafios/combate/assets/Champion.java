package assets;

public class Champion{
    private String nome;
    private Integer vida;
    private Integer ataque;
    private Integer armadura;

    public Champion( String nome, Integer vida, Integer ataque, Integer armadura ){
        this.nome = nome;
        this.vida = vida;
        this.ataque = ataque;
        this.armadura = armadura;
    }

    public String getNome(){
        return this.nome;
    }

    public Integer getVida(){
        return this.vida;
    }

    public Integer getAtaque(){
        return this.ataque;
    }

    public Integer getArmadura(){
        return this.armadura;
    }

    public void takeDamage( Champion otherChampion ){
        Integer damageTaken = otherChampion.getAtaque();
        this.vida -= Math.max(damageTaken - this.armadura, 1) ;
        if( this.vida < 0 ) this.vida = 0;
    }

    public String status(){
        String str = new String();
        str += this.nome + ": ";
        str += this.vida + " de vida ";
        str += ( this.vida == 0 ) ? "(morreu)" : "";

        return str;
    }

}