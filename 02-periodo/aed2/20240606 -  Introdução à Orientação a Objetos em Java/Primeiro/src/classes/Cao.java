package classes;

public class Cao {
    private int id;
    private String nome;
    private String raca;
    private double peso;
    private double metrosAndados;

    public Cao(int id, String nome, String raca, double peso){ // Cria Objetos - Inicializa Variáveis
        this.id = id;
        this.nome = nome;
        this.raca = raca;
        this.peso = peso;
        this.metrosAndados = 0;
    }
    
    public int getID(){
        return id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getRaca() {
        return raca;
    }

    public void setRaca(String raca) {
        this.raca = raca;
    }

    public double getPeso() {
        return peso;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }

    public double getMetrosAndados() {
        return metrosAndados;
    }

    public void setMetrosAndados(double metrosAndados) {
        this.metrosAndados = metrosAndados;
    }
    
    
    
    public void exibeCao(){
        System.out.println("ID: "+id);
        System.out.println("Nome: "+nome);
        System.out.println("Raca: "+raca);
        System.out.println("Peso: "+peso);
        System.out.println("Metros Andados: "+metrosAndados);
    }
}
