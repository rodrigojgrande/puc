package primeiro;


/*
    imports são o equivalente ao #include<> do C
    o formato é pacote.classe
 */
import classes.Cao;
import classes.Pessoa;
import java.util.Scanner;

/**
 * Classe principal do projeto.
 *
 * Eh nela que colocamos o metodo main(), que sera usado para executar o
 * programa.
 */
public class Primeiro {

    /**
     * O metodo main eh encarregado de executar toda a logica do programa. Ele
     * eh um metodo estatico, ou seja, nao necessita de um objeto da classe
     * Primeiro para ser executado. Como o main nao retorna nada, eh void.
     *
     * @param args parametros de execucao que podem ser recebidos por linha de
     * comando (similar ao argc/argv de C)
     */
    public static void main(String[] args) {
        
        /*
            Instanciando dois objetos da classe Cao. Objetos podem ser vistos 
             como variaveis, enquanto Classes podem ser vistas como tipos de dados.
            Cada instancia de um objeto eh por si so uma variavel diferente.
            Aqui temos que o objeto c1 eh um Cao que tem o nome Mussarela,
             enquanto o objeto c2 eh outro Cao que tem o nome Magda.
        
             Para instanciar objetos, usamos seu metodo construtor, precedido pela
              palavra "new". O construtor eh responsavel, por baixo dos panos, de
              alocar espaco na memoria para o novo objeto, devolver uma referencia
              (ponteiro, que Java oculta do programador) para a variavel e, apos isso,
              inicializar os atributos do objeto com os valores passados por parametro.
        */
        Cao c1 = new Cao(1, "Mussarela", "Golden Retriever", 18.7);
        Cao c2 = new Cao(2, "Magda", "Poodle", 4.9);

        /*
            Cada objeto possui seu conjunto de atributos e metodos de modo separado.
            Aqui chamamos o metodo exibeCao, que, para cada um dos dois objetos, ira
             exibir os valores de seus atributos, ou seja, c1.exibecao() ira mostrar
             as informacoes do Mussarela, enquanto c2.exibeCao() ira mostras as 
             informacoes da Magda. 
        */
        c1.exibeCao();
        c2.exibeCao();

        /*
            Exemplificando o uso de getters e setters. 
            Tais metodos contribuem com o encapsulamento dos dados de cada objeto 
             instanciado. Em Orientacao a Objetos, nos devemos proteger o acesso 
             aos atributos colocando eles como privados, e permitir o acesso atraves 
             de metodos get e set, quando apropriado.
        
            No exemplo abaixo, nos visualizamos o id de c1 atraves de c1.getId() e
             visualizamos o nome atraves de c1.getNome(). Nos tambem atualizamos o 
             nome atraves do metodo c1.setNome().
        */
        System.out.println("O id de c1 eh " + c1.getId());
        System.out.println("O nome antigo de c1 era: " + c1.getNome());
        c1.setNome("Rex");
        System.out.println("O novo nome de c1 eh: " + c1.getNome());

        /*
            Leitura de teclado pode ser feita de varios modos. A classe Scanner 
             pode ser usada para leitura de arquivos e da entrada padrao.
            Crio um objeto sc da classe Scanner, e construo ele usando como 
             stream (buffer) o System.in (o teclado, equivalente ao stdin em C). 
         */
        Scanner sc = new Scanner(System.in);

        System.out.println("Digite quantos metros o 1o cao andou: ");
        int andar1 = sc.nextInt(); // le o proximo inteiro digitado no teclado
        System.out.println("Digite quantos metros o 2o cao andou: ");
        int andar2 = sc.nextInt();

        sc.close(); // fecha o acesso ao buffer

        // atualizamos o valor de metrosPercorridos de cada um dos caes com o metodo andar()
        c1.andar(andar1);
        c2.andar(andar2);

        // recupero quantos metros cada um dos caes andaram com getMetrosPercorridos() e comparo
        if (c1.getMetrosPercorridos() > c2.getMetrosPercorridos()) {
            System.out.println("O cao que andou mais eh: " + c1.getNome());
        } else {
            System.out.println("O cao que andou mais eh: " + c2.getNome());
        }

        /*
            Vamos instanciar um objeto Pessoa. Essa pessoa tem o nome "Bilbo".
            Bilbo adota os dois caes, c1 e c2. Isso faz com que a lista caes, interna
            ao objeto Pessoa p, tenha dois objetos do tipo Cao alocados a ela.
        
            Com p.exibe(), eu mostro as informacoes de bilbo: o seu nome e as 
             informacoes dos caes que ele adotou.
        */
        Pessoa p = new Pessoa("Bilbo");
        p.adota(c1);
        p.adota(c2);
        p.exibe();

        /*
            O metodo p.doa() ira remover os caes da lista de caes do bilbo. A remocao 
             aqui foi pela posicao do elemento na lista. Primeiro removemos a Magda, 
             que era a posicao 1 da minha lista, e depois o Rex, que era posicao 0 da
             minha lista. Quando exibo as informacoes de Bilbo, agora consta que ele 
             nao tem nenhum cao.
             
        */
        System.out.println("Removendo os caes...");
        p.doa(1);
        p.doa(0);
        p.exibe();

    }
}
