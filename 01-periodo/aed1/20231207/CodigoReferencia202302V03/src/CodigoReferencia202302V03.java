
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import static javax.swing.WindowConstants.EXIT_ON_CLOSE;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author joao
 */
public class CodigoReferencia202302V03 extends JFrame
        implements ActionListener {

    JButton brasil, inglaterra, italia, argentina;
    ImageIcon imagemNoArquivo;
    JLabel imagemNaTela;

    public CodigoReferencia202302V03() {
        System.out.println("Iniciando...");

        this.setLayout(null);
        this.setBounds(0, 0, 640, 480);
        this.setTitle("Primeiro Programa Java");
        this.getContentPane().setBackground(Color.CYAN);

        brasil = new JButton("Brasil");
        brasil.setBounds(50, 50, 200, 50);
        brasil.setBackground(Color.YELLOW);
        brasil.addActionListener(this);

        argentina = new JButton("Argentina");
        argentina.setBounds(50, 120, 200, 50);
        argentina.setBackground(Color.BLUE);
        argentina.setForeground(Color.WHITE);
        argentina.addActionListener(this);

        inglaterra = new JButton("Inglaterra");
        inglaterra.setBounds(50, 190, 200, 50);
        inglaterra.setBackground(Color.RED);
        inglaterra.addActionListener(this);

        italia = new JButton("Itália");
        italia.setBounds(50, 260, 200, 50);
        italia.setBackground(Color.GREEN);
        italia.addActionListener(this);

        this.getContentPane().add(brasil);
        this.getContentPane().add(argentina);
        this.getContentPane().add(inglaterra);
        this.getContentPane().add(italia);

        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] argumentos) {
        JFrame janela = new CodigoReferencia202302V03();
        janela.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent evento) {
        if (evento.getSource() == brasil) {
            System.out.println("Clicou no Brasil...");
            if (imagemNaTela != null) {
                this.getContentPane().remove(imagemNaTela);
            }
            imagemNoArquivo = new ImageIcon("brasil.jpg");
            imagemNaTela = new JLabel(imagemNoArquivo);
            imagemNaTela.setBounds(300, 100, 275, 183);
            this.getContentPane().add(imagemNaTela);
            this.repaint();
        }

        if (evento.getSource() == argentina) {
            System.out.println("Clicou na Argentina...");
            if (imagemNaTela != null) {
                this.getContentPane().remove(imagemNaTela);
            }
            imagemNoArquivo = new ImageIcon("argentina.jpg");
            imagemNaTela = new JLabel(imagemNoArquivo);
            imagemNaTela.setBounds(300, 100, 275, 183);
            this.getContentPane().add(imagemNaTela);
            this.repaint();

        }

        if (evento.getSource() == inglaterra) {
            System.out.println("Clicou na Inglaterra...");
            if (imagemNaTela != null) {
                this.getContentPane().remove(imagemNaTela);
            }
            imagemNoArquivo = new ImageIcon("inglaterra.jpg");
            imagemNaTela = new JLabel(imagemNoArquivo);
            imagemNaTela.setBounds(300, 100, 275, 183);
            this.getContentPane().add(imagemNaTela);
            this.repaint();

        }

        if (evento.getSource() == italia) {
            System.out.println("Clicou na Italia...");
            if (imagemNaTela != null) {
                this.getContentPane().remove(imagemNaTela);
            }
            imagemNoArquivo = new ImageIcon("italia.jpg");
            imagemNaTela = new JLabel(imagemNoArquivo);
            imagemNaTela.setBounds(300, 100, 275, 183);
            this.getContentPane().add(imagemNaTela);
            this.repaint();
        }
    }
}
