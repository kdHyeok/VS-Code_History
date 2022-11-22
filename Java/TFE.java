//예제 25
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class TFE extends JFrame 
{
    private JTextField TF = new JTextField(20);
    private JLabel LB = new JLabel("");

    public TFE()
    {
        setTitle("title");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new FlowLayout(FlowLayout.CENTER,50,0));

        c.add(new JLabel("입력 후 Enter"));
        c.add(TF);
        c.add(LB);  

        TF.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent e) 
            {
            JTextField t = (JTextField)e.getSource();
            LB.setText("<html>"+LB.getText()+"<br>"+t.getText()+"<html>");

            t.setText("");
            }
        });
        

        setSize(300,300);
        setVisible(true);
    }

    public static void main(String[] args) {
        new TFE();     
    }
}




