/*
II. Escreva a classe Banco que possui os atributos: 
a) codigo identificador, 
b) nome e 
c) correntistas.
*/

package classes;

import java.util.ArrayList;

public class Banco {
    private final int id;
    private String nome;
    private ArrayList<Banco> correntistas;
    
    /*
    i. O atributo "correntistas" deve ser implementado como uma lista de objetos da classe ContaCorrente. 
    Lembre-se de inicializar essa lista dentro do construtor.
    
    ii.Implemente os métodos get e set apropriados. 
    Lembre-se que a o atributo "correntistas" não pode ser alterado, senão perde-se toda a lista! 
    */

    public Banco(int id, String nome) {
        this.id = id;
        this.nome = nome;
        this.correntistas = new ArrayList<>();
    }
    
    public int getId() {
        return id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public ArrayList<Banco> getCorrentistas() {
        return correntistas;
    }
    
    /*
    A manipulação dos elementos da lista deverá ser feita através dos seguintes métodos:
    abrirConta(): esse metodo deve receber como parametro um objeto da classe ContaCorrente, e adicioná-lo na lista.
    
    encerrarConta(): esse metodo deve receber como parametro o índice do correntista na lista, e remover o elemento dessa posição.
    
    getCorrentista(): esse método deve receber como parametro o cpf do correntista, encontrá-lo na lista e retornar as suas informações. 
    DICA: utilize o método .equalsLinks to an external site. de String para comparar os cpfs, caso tenha definido cpf como String.
    
    exibeCorrentistas(): esse metodo deve percorrer a lista de correntistas e invocar o método responsável por imprimir as informações do correntista, definido na classe ContaCorrente.
    */
    
    
}
