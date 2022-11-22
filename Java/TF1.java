import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.GridLayout;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

class TF1 extends JFrame {
    JPanel p_north = new JPanel();
    JPanel p_center = new JPanel();
    JLabel la1 = new JLabel("금액");
    JTextField TX1 = new JTextField(10);
    JButton btn = new JButton("계산");
    JLabel[] la = new JLabel[8];
    JTextField[] TF = new JTextField[8];
    String[] str = { "오만원", "만원", "천원", "500원", "100원", "50원", "10원", "1원" };
    int[] Don = { 50000, 10000, 1000, 500, 100, 50, 10, 1 };
    JCheckBox[] cb = new JCheckBox[8];

    TF1()
    {
        this.setTitle("202068024 이성환");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(new BorderLayout());
        p_north.add(la1);
        p_north.add(TX1);
        p_north.add(btn);
        btn.addMouseListener(new MyMouseListener());
        p_center.setLayout(new GridLayout(8, 2));
        
        for (int i = 0; i < str.length; i++)
        {
            la[i] = new JLabel(str[i]);
            TF[i] = new JTextField(5);
            cb[i] = new JCheckBox();
            cb[i].setSelected(true);
            cb[i].setBackground(Color.PINK);
            p_center.add(la[i]);
            p_center.add(TF[i]);
            p_center.add(cb[i]);
        }

        cb[7].setVisible(false);
        p_north.setBackground(Color.PINK);
        p_center.setBackground(Color.PINK);
        this.add(p_north, BorderLayout.NORTH);
        this.add(p_center, BorderLayout.CENTER);
        this.setSize(300, 300);
        this.setVisible(true);
    }

    public static void main(String[] args) {
		new TF1(); 
	}

    class MyMouseListener extends MouseAdapter
    {
        public void mouseClicked(MouseEvent e)
        {
            int Money = Integer.parseInt(TX1.getText());
            int m = 0;
            if (e.getSource() == btn)
            {
                for (int i = 0; i < Don.length; i++)
                {
                    if(cb[i].isSelected() == false)
                    {
                        TF[i].setText("0");
                        continue; 
                    }
                    m = Money / Don[i];
                    TF[i].setText(Integer.toString(m));
                    if (m > 0){
                        Money = Money % Don[i];
                    }
                } 
            }
        }
    }
}