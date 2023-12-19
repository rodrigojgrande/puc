
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
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
public class CodigoReferencia202302V02 extends JFrame
        implements WindowListener, ActionListener {

    JButton brasil, argentina, inglaterra, italia;

    public CodigoReferencia202302V02() {
        System.out.println("Iniciando...");

        this.setLayout(null);
        this.setBounds(0, 0, 640, 480);
        this.setTitle("Primeiro Programa Java");
        this.getContentPane().setBackground(Color.MAGENTA);

        brasil = new JButton("Bandeira do Brasil");
        brasil.setBounds(10, 50, 200, 70);
        brasil.setBackground(Color.yellow);
        argentina = new JButton("Bandeira da Argentina");
        argentina.setBounds(10, 130, 200, 70);
        argentina.setBackground(Color.blue);

        inglaterra = new JButton("Bandeira da Inglaterra");
        inglaterra.setBounds(10, 210, 200, 70);
        inglaterra.setBackground(Color.red);

        italia = new JButton("Bandeira da Itália");
        italia.setBounds(10, 290, 200, 70);
        italia.setBackground(Color.green);

        getContentPane().add(brasil);
        getContentPane().add(argentina);
        getContentPane().add(inglaterra);
        getContentPane().add(italia);

        addWindowListener(this);
        brasil.addActionListener(this);
        argentina.addActionListener(this);
        inglaterra.addActionListener(this);
        italia.addActionListener(this);

    }

    public static void main(String[] argumentos) {
        JFrame janela = new CodigoReferencia202302V02();
        janela.setVisible(true);
    }

    @Override
    public void windowOpened(WindowEvent we) {
    }

    @Override
    public void windowClosing(WindowEvent we) {
        this.dispose();
        System.exit(1);
    }

    @Override
    public void windowClosed(WindowEvent we) {
        this.dispose();
        System.exit(1);
    }

    @Override
    public void windowIconified(WindowEvent we) {
    }

    @Override
    public void windowDeiconified(WindowEvent we) {
    }

    @Override
    public void windowActivated(WindowEvent we) {
    }

    @Override
    public void windowDeactivated(WindowEvent we) {
    }

    @Override
    public void actionPerformed(ActionEvent evento) {
        if (evento.getSource() == brasil) {
            System.out.println("Clicou no Brasil");
        }
        if (evento.getSource() == argentina) {
            System.out.println("Clicou na Argentina");

        }
        if (evento.getSource() == inglaterra) {
            System.out.println("Clicou na Inglaterra");

        }
        if (evento.getSource() == italia) {
            System.out.println("Clicou na Italia");

        }
    }
}
