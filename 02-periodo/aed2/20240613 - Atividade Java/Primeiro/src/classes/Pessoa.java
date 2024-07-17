package classes;

import java.util.ArrayList;

/**
 * Classe que representa uma pessoa.
 *  
 */
public class Pessoa {
    
    /*
        Uma pessoa aqui eh definida somente pelo seu nome.
        Uma pessoa pode adotar caes, cujas referencias serao guardadas dentro de 
         uma lista. Nos usamos aqui um objeto da classe ArrayList. Ela implementa 
         uma lista usando um Array (ou seja, um vetor) dinamico. A medida que eh 
         necessario, o ArrayList aloca mais posicoes na memoria.
        
    */
    private String nome;
    private ArrayList<Cao> caes;
    
    /**
     *  Método construtor.
     * Atribui o parametro nome para o nome de Pessoa.
     * Inicializa a lista como um objeto lista vazio.
     * 
     * @param nome 
     */
    public Pessoa(String nome){
        this.nome = nome;
        this.caes = new ArrayList<>();
    }
    
    public String getNome(){
        return nome;
    }
    
    public void setNome(String nome){
        this.nome = nome;
    }
    
    /**
     * Adota um cao.
     * Adiciona o cao passado como parametro na lista caes.
     * 
     * @param c 
     */
    public void adota(Cao c){
        caes.add(c);
    }
    
    /**
     * Doa um cao.
     * Remove o cao que esta na posicao i da lista.
     * 
     * @param i 
     */
    public void doa(int i){
        caes.remove(i);
    }
    
    
    public void exibe(){
        System.out.println("Nome: " + nome);
        
        // se a pessoa tiver adotado algum cao, ou seja, a lista nao for vazia
        if(!caes.isEmpty()){
            System.out.println("Caes adotados: ");
            
            // percorro a lista
            for(int i = 0; i < caes.size(); i++){
                
                // recupero o cao da posicao i e invoco o seu metodo exibeCao()
                caes.get(i).exibeCao();
                
                /*
                    A instrucao acima eh o mesmo que eu fazer:
                        Cao c = caes.get(i);
                        c.exibeCao();               
                */
            }             
            /* 
                BONUS: Modo alternativo de iterar na lista de caes:
                for(Cao c : caes){
                    c.exibeCao();                
                }
            */
            
        } else {
            System.out.println("Nao possui caes adotados...");
        }
    }
    
}
