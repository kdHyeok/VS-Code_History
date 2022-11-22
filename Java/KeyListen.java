import java.awt.List;
import java.awt.Panel;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
 
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.text.AttributeSet.ColorAttribute;
 
public class KeyListen extends JFrame {
    private JLabel [] KeyMessage; 
 
    public KeyListen() {
 
        setTitle("���� Ű Ȯ��");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(200, 200);
        setVisible(true);
        Container c = getContentPane();
        c.setLayout(new FlowLayout());
        

        KeyMessage = new JLabel [3];
        KeyMessage[0] = new JLabel("code");
        KeyMessage[1] = new JLabel("char");
        KeyMessage[2] = new JLabel("text");

        for(int i=0; i<KeyMessage.length; i++){
            c.add(KeyMessage[i]);
            KeyMessage[i].setOpaque(true);
            KeyMessage[i].setBackground(Color.YELLOW);
        }

        c.setFocusable(true);
        c.requestFocus();
 
        c.addKeyListener(new KeyListener() { // List�� �׼Ǹ����ʸ� ����.
 
            public void keyTyped(KeyEvent e) {
                System.out.println(e.getKeyChar()+" keyTyped key");
                
                //shift�� ���� ���ȴ��� Ȯ���ϴ� ���
                if((e.getModifiers() & 1) != 0){ // 1�� shift, 2�� CtrlŰ �Դϴ�.
                    //�̸� & �������Ͽ� ������ 0�̾ƴ� ���ڸ� ��ȯ������  �ش� Ű�� ������ Ȯ�� �� �� �ֽ��ϴ�.
                    System.out.printf("shift�� �������ϴ�.\n");
                }else
                {
                    System.out.printf("shift�� ������ �ʾҽ��ϴ�.\n");
                }
            }
 
            @Override
            public void keyReleased(KeyEvent e) {
                //System.out.println(e.getKeyCode()+" keyReleased key2");
                System.out.println(e.getKeyChar()+" keyReleased key");
            }
 
            // ��� Ű�� ���������� ��ҹ��� ������ ���Ѵ�.
            public void keyPressed(KeyEvent e) {
                //System.out.println(e.getKeyCode()+" preesed key2");
                System.out.println(e.getKeyChar()+" preesed key");
            }
        });
 
    }
 
    public static void main(String[] args) {
        new KeyListen();
    }
 
}

/*abstract
import javax.swing.*;
import java.awt.*;
import java.awt.event.*; 

public class test extends JFrame{

    private JLabel [] KeyMessage; 
    
    public test(){

        setTitle("title");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container c = getContentPane();
        c.setLayout(new FlowLayout());
        c.addKeyListener(new MyKeyListener());
    
        KeyMessage = new JLabel [3];
        KeyMessage[0] = new JLabel("code");
        KeyMessage[1] = new JLabel("char");
        KeyMessage[2] = new JLabel("text");
        
        for(int i=0; i<KeyMessage.length; i++){
            c.add(KeyMessage[i]);
            KeyMessage[i].setOpaque(true);
            KeyMessage[i].setBackground(Color.YELLOW);
        }
        setSize(300, 150);
        setVisible(true);

        c.setFocusable(true);
        c.requestFocus();
    }

    class MyKeyListener implements KeyListener{
        
        public void KeyPressed(KeyEvent e) {
            int code = e.getKeyCode();
            char cca= e.getKeyChar();
            KeyMessage[0].setText(Integer.toString(code));
            KeyMessage[1].setText(Character.toString(cca));
            KeyMessage[2].setText(KeyEvent.getKeyText(code));

            System.out.println((e.getKeyChar());
        }
        
        public void KeyReleased(KeyEvent e) {
            System.out.println(e.getKeyChar());
        }
        public void KeyTyped(KeyEvent e) {
            System.out.println(e.getKeyChar());
        }
    }
    public static void main(String[] args){
        new test();
    }
}
*/