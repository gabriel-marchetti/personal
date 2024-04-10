import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;

public class learning_enum2 {
    enum Size{
        small, medium, large, extralarge
    }

    enum Flavour{
        pepperoni, cheese, brocolis, pineapple
    }

    enum IsMaking{
        no, yes
    }

    public class pizzaOrder{
        String id_costumer;
        Size pizzaSize;
        Flavour pizzaFlavour;
        IsMaking making;

        public pizzaOrder( String id_costumer, Size pizzaSize, Flavour pizzaFlavour ){
            this.id_costumer = id_costumer;
            this.pizzaFlavour = pizzaFlavour;
            this.pizzaSize = pizzaSize;
            this.making = IsMaking.no;
        }

        public void setPizzaSize( Size pizzaSize ){
            this.pizzaSize = pizzaSize;
        }

        public Size getPizzaSize( ){
            return this.pizzaSize;
        }

        // If costumer want to change its flavour if it's not making.
        public void setPizzaFlavour( Flavour pizzaFlavour ){
            this.pizzaFlavour = pizzaFlavour;
        }

        public Flavour getPizzaFlavour( ){
            return this.pizzaFlavour;
        }

        // Does what it need to do...
        public void startedMaking(){
            this.making = IsMaking.yes;
        }

    }

    
    public class Oven{
        private int tick;
        private int id_costumer;
        private Flavour flavour;
        public Oven( Flavour flavour, int id_costumer ){
            this.flavour = flavour;
            this.id_costumer = id_costumer;
            this.tick = 0;
        }

        public int getTick( ){
            return this.tick;
        }
    }

    public class pizzaMaker{
        private int MAX_PIZZAS;
        private int currentSize;
        private Queue<pizzaOrder> orders;
        private ArrayList<Oven> ovens;
        private Map<Flavour, Integer> timeToFinish = new HashMap<Flavour, Integer>();

        pizzaMaker( int MAX_PIZZAS ){
            this.MAX_PIZZAS = MAX_PIZZAS;
            this.currentSize = 0;
            orders = new PriorityQueue<pizzaOrder>();
            ovens = new ArrayList<Oven>();
            timeToFinish.put(Flavour.pepperoni, 5);
            timeToFinish.put(Flavour.brocolis, 2);
            timeToFinish.put(Flavour.cheese, 3);
            timeToFinish.put(Flavour.pineapple, 1);
        }

        public void nextOrder( pizzaOrder nextOrder ){
            if( this.currentSize >= MAX_PIZZAS ){
                return;
            }
            orders.add(nextOrder);
            this.currentSize++;
        }

        public ArrayList<pizzaOrder> deliverOrder(  ){
            // scan for finished orders
            for( Oven oven : ovens ){
                
            }
        }
    }

    public static void main( String[] args ){
        // Routine of the restaurant!

    }
}
