package modules;

public class Product {
    private Integer numProducts;
    private String nome;
    
    public Product(Integer numProducts, String nome) {
        this.numProducts = numProducts;
        this.nome = nome;
    }

    public Product(String nome){
        this.nome = nome;
        this.numProducts = 0;
    }

    public Integer getNumProducts() {
        return numProducts;
    }
    public void setNumProducts(Integer numProducts) {
        this.numProducts = numProducts;
    }
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }

    public void increaseQuantity(Integer qtd){
        this.numProducts += qtd;
    }
}
