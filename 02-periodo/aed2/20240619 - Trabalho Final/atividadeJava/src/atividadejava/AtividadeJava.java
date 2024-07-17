package atividadejava;

import classes.Banco;
import classes.ContaCorrente;

/*
III.No main, faça testes da seguinte maneira:
    i. Instancie três objetos do tipo ContaCorrente e um objeto Banco.
*/
public class AtividadeJava {

    public static void main(String[] args) {
    ContaCorrente conta1 = new ContaCorrente(1686585, "879.279.116-60", 5676.48);
    ContaCorrente conta2 = new ContaCorrente(431175244, "473.228.836-75", 1956.0);
    ContaCorrente conta3 = new ContaCorrente(230421, "741.520.806-47", 3609.64);
    
    Banco bank = new Banco(1,"Pacoca s Bank");
    
    /*
    ii. Adicione os três objetos ContaCorrente à lista de correntistas do banco através do método abrirConta().
    */
    
    bank.abrirConta(conta1);
    bank.abrirConta(conta2);
    bank.abrirConta(conta3); 
    
    /*
    iii. Altere o saldo dos correntistas invocando getCorrentista() e, logo em seguida,
    os métodos referentes a depositar ou sacar dinheiro na conta. 
    Por exemplo: banco1.getCorrentista(0).depositar(1000).
    */
    
    bank.exibeCorrentistas();
     
    System.out.println("Dados Correntista ANTES da Alteracao: ");
    bank.getCorrentistas("473.228.836-75").imprimir();
    System.out.println("----------------------- ");
    
    bank.getCorrentistas("473.228.836-75").depositar(1000);
    System.out.println("Dados Correntista DEPOIS da Alteracao: ");
    bank.getCorrentistas("473.228.836-75").imprimir();
    System.out.println("----------------------- ");
    
    /*
    iv. Feche a conta de um dos três correntistas.
    */
    bank.encerrarConta(2);
    System.out.println("Encerrando a conta do terceiro correntista: ");
    bank.exibeCorrentistas();
    
    /*
    v. Imprima o estado final do banco invocando o método exibeCorrentistas().
    */
     System.out.println("Imprimindo Estado final do banco: ");
     bank.exibeCorrentistas();

    }
}


