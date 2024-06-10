import java.util.List;

/**
 * Implementation of a class Player that is a dummy class for trying to implement
 * a serialization of a class with a List inside it.
 */

public class Player{
    private String name;
    private Integer power;
    private List<String> items;

    public Player( String name, Integer power, List<String> items ){
        this.name = name;
        this.power = power;
        this.items = items;
    }

    public void setName(String name){
        this.name = name;
    }

    public String getName(){
        return this.name;
    }

    public void setPower(Integer power){
        this.power = power;
    }

    public Integer getPower(){
        return this.power;
    }

    public List<String> getItens(){
        return this.items;
    }

    public void addItem(String item){
        items.add(item);
    }

}