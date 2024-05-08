class Main{
    public static void main(String[] args) {
        String original = "ABCDEFGhiJklmnopqRS";
        System.out.println(original.toLowerCase());
        System.out.println(original.toUpperCase());
        System.out.println(original);

        String spacedString = "   A B C d E f G H i j   ";
        System.out.println(spacedString.trim());

        System.out.println(original.substring(2));

        String asterisks = "********";
        drawSkateArena(asterisks);
        String plus = asterisks.replace('*', '+');
        drawSkateArena(plus);

        String longString = "abc abc ab ac abc bc";
        System.out.println(longString.replace("abc", "xy"));

        Integer i = longString.lastIndexOf("abc");
        Integer j = longString.indexOf("abc");
        System.out.println(i + " " + j);

        //! Parece importante!
        String vegetables = "potato carrot tomato hugeVegetable";
        String[] each_vegetable = vegetables.split(" ");
        for( String vegetable : each_vegetable )
        {
            System.out.println(vegetable);
        }
    }

    public static void drawSkateArena( String drawReference )
    {
        for(int i = 0; i < drawReference.length(); ++i)
        {
            System.out.println(drawReference.substring(i));
        }

        for(int i = 2; i <= drawReference.length(); ++i)
        {
            System.out.println(drawReference.substring(0, i));
        }
    }
}