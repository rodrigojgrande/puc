
import javax.swing.JButton;
import javax.swing.JFrame;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author joao
 */
public class CodigoReferencia202302V01 extends JFrame {

    JButton botao1;

    public CodigoReferencia202302V01() {
        System.out.println("Iniciando...");

        setLayout(null);
        setBounds(0, 0, 640, 480);
        setTitle("Primeiro Programa Java");

        botao1 = new JButton("Clique Aqui");
        botao1.setBounds(50, 50, 200, 25);
        getContentPane().add(botao1);
    }

    public static void main(String[] argumentos) {
        JFrame janela = new CodigoReferencia202302V01();
        janela.setVisible(true);
    }
}
