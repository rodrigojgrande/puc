/*
I. Escreva a classe ContaCorrente que tenha os atributos: 
a) numero da conta, 
b) cpf do titular e 
c) saldo.
*/

package classes;

public class ContaCorrente {
    private final int numeroDaConta;
    private final String cpf;
    private double saldo;
    
    public ContaCorrente(String cpf, int numeroDaConta, double saldo) {
    this.cpf = cpf;
    this.numeroDaConta = numeroDaConta;
    this.saldo = saldo;
   }
    
/*
i. Esta classe deverá ter métodos get e set para cada atributo relevante.
Quais destes atributos podem ser exibidos? E quais podem ser modificados?
*/

    public int getNumeroDaConta() {
        return numeroDaConta;
    }

    public String getCpf() {
        return cpf;
    }

    public double getSaldo() {
        return saldo;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }
    
    /*
    ii. Defina métodos para: 
    depositar uma quantia na conta, 
    sacar uma quantia da conta e imprimir todos os dados referentes a uma conta. 
    Para cada saque será debitada também uma taxa de operação equivalente à 0.5% do valor sacado. 
    Os valores a serem sacados e depositados deverão ser passados como parâmetros para os respectivos métodos.    
    */
    
    public void depositar(double deposito){
        saldo += deposito;
    }
    
    public void sacar(double saque){
        saldo -= (1.05*saque);
    }
    
    public void imprimir(){
        System.out.println("CPF: " + cpf);
        System.out.println("Saldo: " + saldo);
        System.out.println("Saldo: " + saldo);
    }
}

