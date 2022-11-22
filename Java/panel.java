import javax.swing.*;
import java.awt.*;

public class panel extends JFrame{
    private MyPanel panel = new MyPanel();

    public panel() {
        setTitle("title");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setContentPane(panel);
//
        setSize(350, 250);
        setVisible(true);
    }
//
    class MyPanel extends JPanel{
        public void paintComponent(Graphics g){
            super.paintComponent(g);
//17
            /*g.setColor(Color.RED);
            g.drawOval(10, 15, 20, 10);
            */
//24
            g.setFont(new Font("Times New Roman", Font.PLAIN, 30));
            g.drawString("good luck!!", 100, 50);
        }
    }

    public static void main(String[] args) {
        new panel();
    }
}