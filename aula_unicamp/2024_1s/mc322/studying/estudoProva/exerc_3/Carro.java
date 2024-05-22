/*
 * Todos os atributos devem ser privadas! Isso ocorre por conta do encapsulamento
 * que a programação orientada à objetos tem por princípio. No geral, estamos mais
 * interessados em expor uma interfaces e, portanto, métodos para o usuário do que
 * atributos. Uma justificativa para modificador dos atributos.
 * 
 * Modelo: Veja que aqui podemos ter uma verificação do modelo do carro dada
 * uma lista de carros fornecidas pelo fabricante. Por exemplo, suponhamos que
 * temos um Honda Civic Rebaixado. Veja que aqui podemos fazer uma verificaçãa
 * dada uma tabela de carros da produtora Honda. Assim, se dentro dessa tabela
 * houver o Honda Civic Rebaixado e o carro atender as especificações desse carro
 * então podemos alterar. Desse modo, temos um critério relevante para tornar
 * o modelo do carro como uma variável privada! 
 * 
 * Ano: Aqui há também a questão da verificação, por exemplo, verificar se o ano
 * do carro é superior ou igual ao ano de construção da linha do carro. Por exemplo,
 * vamos supor que o carro Fiat Uno tenha começado a ser produzido em 1998, então só 
 * poderemos ter modelos superiores ou iguais a esse ano. 
 * 
 * quilometragem: Aqui podemos criar a variável como privada e não criar um método
 * setter, uma vez que o dono do carro pode querer alterar isso e vender o carro
 * com especificações fraudulentas. Desse modo, podemos criar aqui um método privado
 * do próprio carro que dada uma quantidade de rotações da roda contibiliza quantos
 * quilômetros foram rodados. Entretanto, é razoável que tenhamos algum método que 
 * nos possibilite visualizar isso, então podemos criar um método getter.
 * 
 * chassi: Análoga à questão do modelo.
 * 
 * cor: Aqui vamos colocar essa variável unicamente devido ao principio do encapsulamento.
 * 
 */

public class Carro{
    private Integer modelo;
    private Integer ano;
    private Double quilometragem;
    private String chassi;
    private String cor;

}