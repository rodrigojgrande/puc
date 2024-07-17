package primeiro;

import classes.Cao;

public class Primeiro {
 
    public static void main(String[] args) {
        /*int x = 2;
           
        System.out.println("Hello World " + x);
        
        if(x == 2){
            System.out.println("Igual a");
        }*/
        
        Cao c1 = new Cao(1, "Ze Trevoso", "Pincher", 2.5);
        Cao c2 = new Cao(2, "Batatao", "Pastor Alemao", 15.7);
        
        c1.exibeCao();
        c2.exibeCao();
        
        System.out.println("O cao de id " + c1.getID() + " tem o nome de " + c1.getNome());
        c1.setNome("Fofinho");
        System.out.println("O cao de id " + c1.getID() + " tem o novo nome de " + c1.getNome());

    }
}