import java.util.PriorityQueue;
import java.util.Queue;

public class learning_enum2 {
    enum size{
        small, medium, large, extralarge
    }

    enum flavour{
        pepperoni, cheese, brocolis, pineapple
    }

    enum isMaking{
        no, yes
    }

    public class pizzaOrder{
        String id_costumer;
        size pizzaSize;
        flavour pizzaFlavour;
        isMaking making;

        public pizzaOrder( String id_costumer, size pizzaSize, flavour pizzaFlavour ){
            this.id_costumer = id_costumer;
            this.pizzaFlavour = pizzaFlavour;
            this.pizzaSize = pizzaSize;
            this.making = isMaking.no;
        }

        public void setPizzaSize( size pizzaSize ){
            this.pizzaSize = pizzaSize;
        }

        public size getPizzaSize( ){
            return this.pizzaSize;
        }

        // If costumer want to change its flavour if it's not making.
        public void setPizzaFlavour( flavour pizzaFlavour ){
            this.pizzaFlavour = pizzaFlavour;
        }

        public flavour getPizzaFlavour( ){
            return this.pizzaFlavour;
        }

        // Does what it need to do...
        public void startedMaking(){
            this.making = isMaking.yes;
        }

    }

    public class pizzaMaker{
        int MAX_PIZZAS;
        int currentSize;
        Queue<pizzaOrder> orders;

        public pizzaMaker( int MAX_PIZZAS ){
            this.MAX_PIZZAS = MAX_PIZZAS;
            this.currentSize = 0;
            orders = new PriorityQueue<pizzaOrder>();
        }

        public void nextOrder( pizzaOrder nextOrder ){
            orders.add(nextOrder);
        }

        public void deliverOrder(  ){

        }
    }

    public static void main( String[] args ){
        // Routine of the restaurant!

    }
}
