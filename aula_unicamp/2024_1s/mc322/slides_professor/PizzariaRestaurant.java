import java.util.ArrayList;
import java.util.Queue;

public class PizzariaRestaurant{
    enum Flavour{
        pepperoni, cheese, brocolis, pineapple
    }
    enum Size{
        small, medium, large, extralarge
    }

    /**
     * Mainframe of the Pizzaria, this should Compose all the objects that
     * are needed for the pizzaria to work.
     */
    public class Pizzaria{
        private final String namePizzaria;
        Client clients;
        Integer MAX_CAPACITY;
        Integer CURRENT_CAPACITY;
        Kitchen kitchen;
        ArrayList<Waiter> waiters;

        public Pizzaria( String name, int MAX_CAPACITY ){
            this.namePizzaria = name;
            this.MAX_CAPACITY = MAX_CAPACITY;
            this.CURRENT_CAPACITY = 0;
        }

        public void hireWaiters( String ... names ){
            for( String name : names ){
                Waiter hiringWaiter = new Waiter(name);
                waiters.add( hiringWaiter );
            }
        }

        public void hireKitchen(  ){

        }
    }

    public class Waiter{
        private final String nameWaiter;
        private boolean isFree;
        private Order carrying_order; 

        public Waiter( String name ){
            this.nameWaiter = name;
            this.isFree = true;
            this.carrying_order = null;
        }
    }

    public class Client{
        private Integer num_of_people;
        private Integer current_table;
        private Order order;
        
    }

    public class Kitchen{
        private Integer num_of_ovens;
        private Integer num_using_ovens;
        private Queue<Order> orders_to_deliver;
        private ArrayList<Order> making_orders;
        
    }

    public class Order{
        Integer costumer_id;
        Size order_size;
        Flavour order_flavour;

    }

    public static void main( String[] args ){
        // Main routine for the restaurant.
    }
}