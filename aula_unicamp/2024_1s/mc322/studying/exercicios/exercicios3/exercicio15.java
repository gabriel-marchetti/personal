import java.util.Scanner;

public class exercicio15 {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in);
        int numExperiments,
            model_rats = 0,
            model_rabbits = 0,
            model_frog = 0;
        
        System.out.printf("Quantos experimentos foram feitos durante o ano: ");
        numExperiments = sc.nextInt();
        for( int i = 0; i < numExperiments; ++i ){
            char typeExperiment;
            int num_models;
            num_models = sc.nextInt();
            typeExperiment = sc.nextLine().charAt(1);
            switch (typeExperiment) {
                case 'C':
                    model_rabbits += num_models;
                    break;
                case 'S':
                    model_frog += num_models;
                    break;
                case 'R':
                    model_rats += num_models;
                    break;
                default:
                    break;
            }
        }

        int total = model_frog + model_rabbits + model_rats;
        System.out.println("RELATORIO FINAL");
        System.out.printf("Total de cobaias: %d\n", total);
        System.out.printf("Total de coelhos: %d\n", model_rabbits);
        System.out.printf("Total de ratos: %d\n", model_rats);
        System.out.printf("Total de sapos: %d\n", model_frog);
        System.out.printf("Porcentual de coelhos: %.2f\n", 
                          100.0 * (double) model_rabbits / total);
        System.out.printf("Percentual de ratos: %.2f\n", 
                          100.0 * (double) model_rats / total);
        System.out.printf("Percentual de sapos: %.2f\n",
                          100.0 *(double) model_frog / total);

        sc.close();
    }
}
