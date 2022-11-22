import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter; 
import java.awt.event.WindowEvent;

import javax.swing.*;
import java.util.*;
import java.io.*;
import java.io.IOException;

class user{
	static boolean runig = true;
	static int point = 0;
	static int ppp = 1;
    static int rich = 0;
	
	static float time = 0.000f;
	static int RUNspeed = 10;
	static boolean jump = false;
	static boolean kleft = false;
	static boolean kright = false;
	static boolean kspace = false;
	
	static int ux = 0 ;
	static int uy = 400;
	static int HP = 5000;
	static int maxHP = 5000;
	static int damage = 15;
	static int motion = 0;
	static int attack = 0;
	static int heal = 0;
	static int healing = 10;
	static int Slash = 0;
}
class Dragon{
	static int ux = 600;
	static int uy = 360;
	static int HP = 0;
	static int maxHP = 10000;
	static int damage = 30;
	static int motion = 0;
	static int fire = 60;
	static int skil = 200;
	static int heal = 0;
	static boolean dspown = false;
}

class mini_logic{
	static int MaxMini = 10;
	static int HP = 800;
	static int speed = 150;
	static int px[] = new int[MaxMini];
	static int py[] = new int[MaxMini];
	static int minian[] = new int[MaxMini];
	static int spownCheck[] = new int[MaxMini];
	static int motion[] = new int[MaxMini];
	
	static int battleLine = 0;
	static int spownLine = 0;
	static int attackLine = 31;
	static int castle = 10000;
	static int damage = 15;
}

class ene_logic{
	static int MaxMini = 30;
	static int HP = 3000;
	static int speed = 100;
	static int px[] = new int[MaxMini];
	static int py[] = new int[MaxMini];
	static int minian[] = new int[MaxMini];
	static int spownCheck[] = new int[MaxMini];
	static int motion[] = new int[MaxMini];
	
	static int battleLine = 730;
	static int spownLine = 730;
	static int attackLine = 700;
	static int castle = 10000;
	static int damage = 30;
}

public class Defense_Game extends JFrame{
    
	private static final long serialVersionUID = 1L;
	
	MyPanel mpanel = new MyPanel();
    public Defense_Game() {
        setTitle("GAME");
        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) { 
                try {
                    File_W(true);
                } catch (IOException e1) {
                    e1.printStackTrace();
                }
                System.exit(0); 
            } 
        }); 
        //setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setContentPane(mpanel);

        getContentPane().setLayout(null);

        JLabel name = new JLabel("Defence Game!");
        name.setBounds(160,50,600,100);
        name.setFont(new Font("Enchanted Land", Font.BOLD, 100));
        name.setForeground(Color.WHITE);
        JLabel name2 = new JLabel("Defence Game!");
        name2.setBounds(165,55,600,100);
        name2.setFont(new Font("Enchanted Land", Font.BOLD, 100));
        

       JButton sta = new JButton("Game Start! >>");
        sta.setBounds(520,300,230,30);
        sta.setFont(new Font("바탕", Font.BOLD, 25));
        sta.setBackground(Color.white);
        sta.setOpaque(false);
        sta.setBorderPainted(false);
        sta.setFocusPainted(false);
        
        
        sta.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	dispose();
            	user.runig = true;
                Play_Game pGame = new Play_Game();
                Thread t = new Thread(pGame);
            	t.setDaemon(true);
                t.start();
                
            }
        });
        JButton richbt = new JButton("Rich Mode! (P)");
        richbt.setBounds(520,350,230,30);
        richbt.setFont(new Font("바탕", Font.BOLD, 25));
        richbt.setBackground(Color.white);
        richbt.setOpaque(false);
        richbt.setBorderPainted(false);
        richbt.setFocusPainted(false);
        mpanel.add(richbt);
        if (user.rich == 1){
            richbt.setVisible(true);
        }
        else {
            richbt.setVisible(false);
        }

        
        
        richbt.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	user.point = 7777;
            }
        });


        JLabel rname2 = new JLabel("[!] Will you really 'reset' it?");
        rname2.setBounds(50,55,700,100);
        rname2.setFont(new Font("고딕", Font.BOLD, 55));
        rname2.setBackground(Color.black);
        rname2.setForeground(Color.WHITE);
        rname2.setOpaque(true);
        JButton ryes = new JButton("Yes");
        ryes.setBounds(150,200,200,100);
        ryes.setFont(new Font("바탕", Font.BOLD, 80));
        ryes.setBackground(Color.white);
        ryes.setBorderPainted(false);
        ryes.setFocusPainted(false);
        JButton rno = new JButton("No");
        rno.setBounds(400,200,200,100);
        rno.setFont(new Font("바탕", Font.BOLD, 80));
        rno.setBackground(Color.white);
        rno.setBorderPainted(false);
        rno.setFocusPainted(false);

        ryes.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {

                user.point = 0;
                user.maxHP = 5000;
                user.Slash = 0;
                user.damage = 15;
                user.healing = 10;
                mini_logic.MaxMini = 10;
                mini_logic.px = Arrays.copyOf(mini_logic.px, mini_logic.MaxMini );
                mini_logic.py = Arrays.copyOf(mini_logic.py, mini_logic.MaxMini );
                mini_logic.minian = Arrays.copyOf(mini_logic.minian, mini_logic.MaxMini );
                mini_logic.motion = Arrays.copyOf(mini_logic.motion, mini_logic.MaxMini );
                mini_logic.spownCheck = Arrays.copyOf(mini_logic.spownCheck, mini_logic.MaxMini );
                mini_logic.HP = 800;
                mini_logic.damage = 15;
                mini_logic.speed = 150;
                user.rich = 0;
                ryes.setVisible(false);
                rno.setVisible(false);
                rname2.setVisible(false);
            }
        });        
        rno.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {

                ryes.setVisible(false);
                rno.setVisible(false);
                rname2.setVisible(false);            
            }
        });
        
        mpanel.add(rname2);
        mpanel.add(ryes);
        mpanel.add(rno);
        ryes.setVisible(false);
        rno.setVisible(false);
        rname2.setVisible(false);


        JButton reset = new JButton("<!>Data Reset<!>");
        reset.setBounds(630,580,200,10);
        reset.setFont(new Font("바탕", Font.BOLD, 10));
        reset.setBackground(Color.white);
        reset.setOpaque(false);
        reset.setBorderPainted(false);
        reset.setFocusPainted(false);
        
        
        reset.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	rname2.setVisible(true);
                ryes.setVisible(true);
                rno.setVisible(true);
                
            }
        });
        
   
        mpanel.add(name);
        mpanel.add(name2);

        mpanel.add(sta);
        mpanel.add(reset);
        
        setSize(800,630);
        setResizable(false);//창의 크기를 변경하지 못하게
		setLocationRelativeTo(null);//창이 가운데 나오게
        setVisible(true);
        
    }

	class MyPanel extends JPanel{
		private static final long serialVersionUID = 1L;
		private ImageIcon Main_img = new ImageIcon("jav/Castle.gif");//이미지 불러오기
        private Image img = Main_img.getImage();
        public void paintComponent(Graphics g){
            super.paintComponent(g);

            g.drawImage(img, 0, 0, this);
        }
    }
    static void File_W(boolean bb) throws IOException{
        String filePath = "jav/Game_Data.txt"; 
	    File file = new File(filePath); // File객체 생성 
		
        if(!file.exists()){ // 파일이 존재하지 않으면 
			file.createNewFile(); // 신규생성 } 

            BufferedWriter writer = new BufferedWriter(new FileWriter(file)); // 파일에 쓰기
		    writer.write(Integer.toString(user.point)); 
		    writer.newLine(); 
		    writer.write(Integer.toString(user.maxHP)); 
		    writer.newLine(); 
            writer.write(Integer.toString(user.Slash)); 
		    writer.newLine(); 
            writer.write(Integer.toString(user.damage)); 
		    writer.newLine(); 
            //writer.write(Integer.toString(user.healing)); 
		    //writer.newLine(); 
            writer.write(Integer.toString(mini_logic.MaxMini)); 
		    writer.newLine(); 
            writer.write(Integer.toString(mini_logic.HP)); 
		    writer.newLine(); 
            writer.write(Integer.toString(mini_logic.damage)); 
		    writer.newLine(); 
            writer.write(Integer.toString(mini_logic.speed)); 
		    writer.newLine(); // 버퍼 및 스트림 뒷정리 
		    writer.flush(); // 버퍼의 남은 데이터를 모두 쓰기 
		    writer.close(); // 스트림 종료
		}
        if(bb==true){   

            BufferedWriter writer = new BufferedWriter(new FileWriter(file)); // 파일에 쓰기
		    writer.write(Integer.toString(user.point)); 
		    writer.newLine(); 
		    writer.write(Integer.toString(user.maxHP)); 
		    writer.newLine(); 
            writer.write(Integer.toString(user.Slash)); 
		    writer.newLine(); 
            writer.write(Integer.toString(user.damage)); 
		    writer.newLine(); 
            //writer.write(Integer.toString(user.healing)); 
		    //writer.newLine(); 
            writer.write(Integer.toString(mini_logic.MaxMini)); 
		    writer.newLine(); 
            writer.write(Integer.toString(mini_logic.HP)); 
		    writer.newLine(); 
            writer.write(Integer.toString(mini_logic.damage)); 
		    writer.newLine(); 
            writer.write(Integer.toString(mini_logic.speed)); 
		    writer.newLine();
            if (user.rich == 1){
                writer.write(Integer.toString(1)); 
		        writer.newLine();
            }
             // 버퍼 및 스트림 뒷정리 
		    writer.flush(); // 버퍼의 남은 데이터를 모두 쓰기 
		    writer.close(); // 스트림 종료
		}
		// BufferedWriter 생성 
		
    }
    static void File_R() throws IOException{
        String filePath = "jav/Game_Data.txt"; 
	    File file = new File(filePath); // File객체 생성
		
		
		if(file.exists()){ // 파일이 존재하면
			BufferedReader reader = new BufferedReader(new FileReader(file));
            user.point = Integer.parseInt(reader.readLine());
            user.maxHP = Integer.parseInt(reader.readLine());
            user.Slash = Integer.parseInt(reader.readLine());
            user.damage = Integer.parseInt(reader.readLine());
            //user.healing = Integer.parseInt(reader.readLine());
            mini_logic.MaxMini = Integer.parseInt(reader.readLine());
            mini_logic.px = Arrays.copyOf(mini_logic.px, mini_logic.MaxMini );
            mini_logic.py = Arrays.copyOf(mini_logic.py, mini_logic.MaxMini );
            mini_logic.minian = Arrays.copyOf(mini_logic.minian, mini_logic.MaxMini );
            mini_logic.motion = Arrays.copyOf(mini_logic.motion, mini_logic.MaxMini );
            mini_logic.spownCheck = Arrays.copyOf(mini_logic.spownCheck, mini_logic.MaxMini );
            mini_logic.HP = Integer.parseInt(reader.readLine());
            mini_logic.damage = Integer.parseInt(reader.readLine());
            mini_logic.speed = Integer.parseInt(reader.readLine());
            String line = null;
            if ((line = reader.readLine()) != null) 
                user.rich = Integer.parseInt(line);
			reader.close(); 
		}
    }
    public static void main(String[] args) throws IOException{
		new Defense_Game();
        File_W(false);
        try {
            File_R();
        } catch (IOException e1) {
            e1.printStackTrace();
        }

	}
}

//================================================================================



class Play_Game extends JFrame implements Runnable{
	private static final long serialVersionUID = 1L;
		
	GamePanel gpanel = new GamePanel();
	JButton rst = new JButton("Re Start? >>");
	JLabel name = new JLabel("Victory!");
	JLabel name2 = new JLabel("Victory!");

    static void File_W(boolean bb) throws IOException{
        String filePath = "jav/Game_Data.txt"; 
	    File file = new File(filePath); // File객체 생성 
		
        if(!file.exists()){ // 파일이 존재하지 않으면 
			file.createNewFile(); // 신규생성 } 

            BufferedWriter writer = new BufferedWriter(new FileWriter(file)); // 파일에 쓰기
		    writer.write(Integer.toString(user.point)); 
		    writer.newLine(); 
		    writer.write(Integer.toString(user.maxHP)); 
		    writer.newLine(); 
            writer.write(Integer.toString(user.Slash)); 
		    writer.newLine(); 
            writer.write(Integer.toString(user.damage)); 
		    writer.newLine(); 
            //writer.write(Integer.toString(user.healing)); 
		    //writer.newLine(); 
            writer.write(Integer.toString(mini_logic.MaxMini)); 
		    writer.newLine(); 
            writer.write(Integer.toString(mini_logic.HP)); 
		    writer.newLine(); 
            writer.write(Integer.toString(mini_logic.damage)); 
		    writer.newLine(); 
            writer.write(Integer.toString(mini_logic.speed)); 
		    writer.newLine(); // 버퍼 및 스트림 뒷정리 
		    writer.flush(); // 버퍼의 남은 데이터를 모두 쓰기 
		    writer.close(); // 스트림 종료
		}
        if(bb==true){   

            BufferedWriter writer = new BufferedWriter(new FileWriter(file)); // 파일에 쓰기
		    writer.write(Integer.toString(user.point)); 
		    writer.newLine(); 
		    writer.write(Integer.toString(user.maxHP)); 
		    writer.newLine(); 
            writer.write(Integer.toString(user.Slash)); 
		    writer.newLine(); 
            writer.write(Integer.toString(user.damage)); 
		    writer.newLine(); 
            //writer.write(Integer.toString(user.healing)); 
		    //writer.newLine(); 
            writer.write(Integer.toString(mini_logic.MaxMini)); 
		    writer.newLine(); 
            writer.write(Integer.toString(mini_logic.HP)); 
		    writer.newLine(); 
            writer.write(Integer.toString(mini_logic.damage)); 
		    writer.newLine(); 
            writer.write(Integer.toString(mini_logic.speed)); 
		    writer.newLine(); 
            if (user.rich == 1){
                writer.write(Integer.toString(1)); 
		        writer.newLine();
            }// 버퍼 및 스트림 뒷정리 
		    writer.flush(); // 버퍼의 남은 데이터를 모두 쓰기 
		    writer.close(); // 스트림 종료
		}
		// BufferedWriter 생성 
		
    }
	void victory(){
		name.setVisible(true);
		name2.setVisible(true);
	}
	void restart(){
		rst.setVisible(true);
	}
	Play_Game(){
		user.time = 0.000f;
		
		
		user.ppp = 1;
		user.ux =10;
		user.uy = 400;
		user.HP = user.maxHP;
		
		Dragon.dspown = false;
		Dragon.maxHP = 10000;
		Dragon.HP = 0;
		Dragon.damage = 30;
		
		for(int i = 0; i < mini_logic.MaxMini; i++) {
			
			mini_logic.spownCheck[i] = 0;
		}
        for(int i = 0; i < ene_logic.MaxMini; i++) {
			
        	ene_logic.spownCheck[i] = 0;
		}
		
		mini_logic.battleLine = 0;
		mini_logic.attackLine = 31;
		mini_logic.castle = 10000;
		
		ene_logic.battleLine = 730;
		ene_logic.attackLine = 700;
		ene_logic.castle = 10000;
		ene_logic.HP = 3000;
		ene_logic.damage = 30;
		ene_logic.speed = 100;

		
		setTitle("GAME");
        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) { 
                try {
                    File_W(true);
                } catch (IOException e1) {
                    e1.printStackTrace();
                }
                System.exit(0); 
            } 
        }); 
        

        //setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setContentPane(gpanel);
        
        rst.setBounds(100,200,600,100);
        rst.setFont(new Font("바탕", Font.BOLD, 80));
        rst.setBackground(Color.white);
        rst.setOpaque(false);
        rst.setBorderPainted(false);
        rst.setFocusPainted(false);
        
        rst.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {

            	dispose();
            	user.runig = true;
                Play_Game pGame = new Play_Game();
                Thread t = new Thread(pGame);
            	t.setDaemon(true);
                t.start();
 
            }
        });
        
        gpanel.add(rst);
        rst.setVisible(false);
        
        
        name.setBounds(200,200,600,150);
        name.setFont(new Font("Enchanted Land", Font.BOLD, 150));
        name.setForeground(Color.WHITE);
        name2.setBounds(205,205,600,150);
        name2.setFont(new Font("Enchanted Land", Font.BOLD, 150));
        
        gpanel.add(name);
        name.setVisible(false);
        gpanel.add(name2);
        name2.setVisible(false);
        
        JButton back = new JButton("<< Back");
        back.setBounds(0,20,120,30);
        back.setFont(new Font("바탕", Font.BOLD, 20));
        back.setBackground(Color.white);
        back.setOpaque(false);
        back.setBorderPainted(false);
        back.setFocusPainted(false);
        
        back.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	dispose();
            	user.runig = false;
            	new Defense_Game();
                
            }
        });
        this.add(back);
        
        JButton spUP = new JButton("+>>");
        spUP.setBounds(250,0,55,30);
        spUP.setFont(new Font("바탕", Font.BOLD, 9));
        spUP.setBackground(Color.white);
        spUP.setOpaque(false);
        spUP.setBorderPainted(false);
        spUP.setFocusPainted(false);
        JButton spDown = new JButton("<<-");
        spDown.setBounds(200,0,55,30);
        spDown.setFont(new Font("바탕", Font.BOLD, 9));
        spDown.setBackground(Color.white);
        spDown.setOpaque(false);
        spDown.setBorderPainted(false);
        spDown.setFocusPainted(false);
        
        spUP.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	getContentPane().requestFocus(); 
                getContentPane().setFocusable(true);
            	if (user.RUNspeed > 2)
                user.RUNspeed -= 1;
            }
        });
        spDown.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	getContentPane().requestFocus(); 
                getContentPane().setFocusable(true);
            	if (user.RUNspeed < 20)
                    user.RUNspeed += 1;
            }
        });
        JLabel upL1 = new JLabel("공격력UP-10P");
        upL1.setBounds(5,510,100,10);
        upL1.setFont(new Font("돋움", Font.BOLD, 10));
        upL1.setForeground(Color.WHITE);
        ImageIcon up1 = new ImageIcon("jav/wariar_up.png");//이미지 불러오기
        JButton upB1 = new JButton(up1);
        upB1.setBounds(10,515,80,80);;
        upB1.setBorderPainted(false);
        upB1.setFocusPainted(false);
        upB1.setRolloverIcon(up1);
        upB1.setBackground(Color.white);
        upB1.setOpaque(false);
        
        upB1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	getContentPane().requestFocus(); 
                getContentPane().setFocusable(true);
                if(user.point >= 10) {
                	mini_logic.damage += 2;
                	user.point -= 10;
                }
                
            }
        });
        gpanel.add(upB1);
        gpanel.add(upL1);
        
        JLabel upL2 = new JLabel("최대인구UP-5P");
        upL2.setBounds(105,510,100,10);
        upL2.setFont(new Font("돋움", Font.BOLD, 10));
        upL2.setForeground(Color.WHITE);
        ImageIcon up2 = new ImageIcon("jav/wariar_up2.png");//이미지 불러오기
        JButton upB2 = new JButton(up2);
        upB2.setBounds(110,515,80,80);;
        upB2.setBorderPainted(false);
        upB2.setFocusPainted(false);
        upB2.setRolloverIcon(up2);
        upB2.setBackground(Color.white);
        upB2.setOpaque(false);
        
        upB2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	getContentPane().requestFocus(); 
                getContentPane().setFocusable(true);
                if(user.point >= 5 && mini_logic.MaxMini<35) {
                	mini_logic.px = Arrays.copyOf(mini_logic.px, mini_logic.MaxMini + 1);
                	mini_logic.py = Arrays.copyOf(mini_logic.py, mini_logic.MaxMini + 1);
                	mini_logic.minian = Arrays.copyOf(mini_logic.minian, mini_logic.MaxMini + 1);
                	mini_logic.motion = Arrays.copyOf(mini_logic.motion, mini_logic.MaxMini + 1);
                	mini_logic.spownCheck = Arrays.copyOf(mini_logic.spownCheck, mini_logic.MaxMini + 1);
                	mini_logic.MaxMini += 1;
                	user.point -= 5;
                }
                
            }
        });
        gpanel.add(upB2);
        gpanel.add(upL2);
        
        JLabel upL3 = new JLabel("생산속도UP-20P");
        upL3.setBounds(205,510,100,10);
        upL3.setFont(new Font("돋움", Font.BOLD, 10));
        upL3.setForeground(Color.WHITE);
        ImageIcon up3 = new ImageIcon("jav/wariar_up3.png");//이미지 불러오기
        JButton upB3 = new JButton(up3);
        upB3.setBounds(210,515,80,80);;
        upB3.setBorderPainted(false);
        upB3.setFocusPainted(false);
        upB3.setRolloverIcon(up3);
        upB3.setBackground(Color.white);
        upB3.setOpaque(false);
        
        upB3.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	getContentPane().requestFocus(); 
                getContentPane().setFocusable(true);
                if(user.point >= 20 && mini_logic.speed >= 30) {
                	mini_logic.speed -= 10;
                	user.point -= 20;
                }
                
            }
        });
        gpanel.add(upB3);
        gpanel.add(upL3);
        
        JLabel upL4 = new JLabel("체력UP-10P");
        upL4.setBounds(315,510,100,10);
        upL4.setFont(new Font("돋움", Font.BOLD, 10));
        upL4.setForeground(Color.WHITE);
        ImageIcon up4 = new ImageIcon("jav/wariar_up4.png");//이미지 불러오기
        JButton upB4 = new JButton(up4);
        upB4.setBounds(310,515,80,80);;
        upB4.setBorderPainted(false);
        upB4.setFocusPainted(false);
        upB4.setRolloverIcon(up4);
        upB4.setBackground(Color.white);
        upB4.setOpaque(false);
        
        upB4.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	getContentPane().requestFocus(); 
                getContentPane().setFocusable(true);
                if(user.point >= 10) {
                	mini_logic.HP += 200;
                	user.point -= 10;
                }
                
            }
        });
        gpanel.add(upB4);
        gpanel.add(upL4);
        
        JLabel upL5 = new JLabel("기사공격UP-30P");
        upL5.setBounds(405,510,100,10);
        upL5.setFont(new Font("돋움", Font.BOLD, 10));
        upL5.setForeground(Color.WHITE);
        ImageIcon up5 = new ImageIcon("jav/champ_up.png");//이미지 불러오기
        JButton upB5 = new JButton(up5);
        upB5.setBounds(410,515,80,80);;
        upB5.setBorderPainted(false);
        upB5.setFocusPainted(false);
        upB5.setRolloverIcon(up5);
        upB5.setBackground(Color.white);
        upB5.setOpaque(false);
        
        upB5.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	getContentPane().requestFocus(); 
                getContentPane().setFocusable(true);
                if(user.point >= 30) {
                	user.damage += 1;
                	
                	user.point -= 30;
                }
                
            }
        });
        gpanel.add(upB5);
        gpanel.add(upL5);
        
        JLabel upL6 = new JLabel("기사체력UP-30P");
        upL6.setBounds(515,510,100,10);
        upL6.setFont(new Font("돋움", Font.BOLD, 10));
        upL6.setForeground(Color.WHITE);
        ImageIcon up6 = new ImageIcon("jav/champ_up2.png");//이미지 불러오기
        JButton upB6 = new JButton(up6);
        upB6.setBounds(510,515,80,80);;
        upB6.setBorderPainted(false);
        upB6.setFocusPainted(false);
        upB6.setRolloverIcon(up6);
        upB6.setBackground(Color.white);
        upB6.setOpaque(false);
        
        upB6.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	getContentPane().requestFocus(); 
                getContentPane().setFocusable(true);
                if(user.point >= 30) {
                	user.maxHP += 200;
                	user.HP += 200;
                	user.point -= 30;
                }
                
            }
        });
        gpanel.add(upB6);
        gpanel.add(upL6);
        
        JLabel upL7 = new JLabel("공격범위UP-40P");
        upL7.setBounds(620,510,100,10);
        upL7.setFont(new Font("돋움", Font.BOLD, 10));
        upL7.setForeground(Color.WHITE);
        ImageIcon up7 = new ImageIcon("jav/champ_up3.png");//이미지 불러오기
        JButton upB7 = new JButton(up7);
        upB7.setBounds(610,515,80,80);;
        upB7.setBorderPainted(false);
        upB7.setFocusPainted(false);
        upB7.setRolloverIcon(up7);
        upB7.setBackground(Color.white);
        upB7.setOpaque(false);
        
        upB7.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	getContentPane().requestFocus(); 
                getContentPane().setFocusable(true);
                if(user.point >= 40 && user.Slash < 50) {
                	user.Slash += 1;
                	user.point -= 40;
                }
                
            }
        });
        gpanel.add(upB7);
        gpanel.add(upL7);
        
        this.add(spUP);
        this.add(spDown);
   
        getContentPane().requestFocus(); 
        getContentPane().setFocusable(true);
        
        getContentPane().addKeyListener(new KeyAdapter() {
        	@Override
        	public void keyPressed(KeyEvent e) {
        		if (e.getKeyCode()==44) {
        			if (user.RUNspeed < 20)
                        user.RUNspeed += 1;
        		}
        		if (e.getKeyCode()==46) {
        			if (user.RUNspeed > 2)
                        user.RUNspeed -= 1;
        		}
        		
        		if (e.getKeyCode()==KeyEvent.VK_LEFT) {
        			user.kleft = true;
        		}
        		if (e.getKeyCode()==KeyEvent.VK_RIGHT) {
        			user.kright = true;
        		}
        		if (e.getKeyCode()==KeyEvent.VK_UP) {
        			if(user.uy >=390) {
        				user.jump = true;
            			user.motion=-10;
        			}
        		}
        		if (e.getKeyCode()==KeyEvent.VK_SPACE) {
        			if (user.attack==0) {
        				user.kspace = true;
                		
                	}
        		}
            }
        	@Override
        	public void keyReleased(KeyEvent e) {
        		if (e.getKeyCode()==KeyEvent.VK_LEFT) {
        			user.kleft = false;
        		}
        		if (e.getKeyCode()==KeyEvent.VK_RIGHT) {
        			user.kright = false;
        		}
        		if (e.getKeyCode()==KeyEvent.VK_SPACE) {
        			user.kspace = false;
        		}
        	}
        });
        
        
        

        getContentPane().setLayout(null);
        setSize(800,630);
        setResizable(false);//창의 크기를 변경하지 못하게
		setLocationRelativeTo(null);//창이 가운데 나오게
        setVisible(true);
        
	}
	class GamePanel extends JPanel{
		private ImageIcon war_img = new ImageIcon("jav/wariar2.png");//이미지 불러오기
		private Image wimg = war_img.getImage();
		private ImageIcon war_img2 = new ImageIcon("jav/wariar22.png");//이미지 불러오기
		private Image wimg2 = war_img2.getImage();
		private ImageIcon war_img3 = new ImageIcon("jav/wariar23.png");//이미지 불러오기
		private Image wimg3 = war_img3.getImage();
		private ImageIcon ewar_img = new ImageIcon("jav/wariar3.png");//이미지 불러오기
		private Image ewimg = ewar_img.getImage();
		private ImageIcon ewar_img2 = new ImageIcon("jav/wariar32.png");//이미지 불러오기
		private Image ewimg2 = ewar_img2.getImage();
		private ImageIcon ewar_img3 = new ImageIcon("jav/wariar33.png");//이미지 불러오기
		private Image ewimg3 = ewar_img3.getImage();
		
		private static final long serialVersionUID = 1L;
		private ImageIcon Main_img = new ImageIcon("jav/Castle2.png");//이미지 불러오기
        private Image img = Main_img.getImage();
        private ImageIcon HP_img = new ImageIcon("jav/CastleHP.png");//이미지 불러오기
        private Image HPbar = HP_img.getImage();
        private ImageIcon HP_img2 = new ImageIcon("jav/CastleHP2.png");//이미지 불러오기
        private Image HPbar2 = HP_img2.getImage();
        
        private ImageIcon img1 = new ImageIcon("jav/champ.png");//이미지 불러오기
    	private Image cimg1 = img1.getImage();
    	private ImageIcon img2 = new ImageIcon("jav/champ2.png");//이미지 불러오기
    	private Image cimg2 = img2.getImage();
    	private ImageIcon img3 = new ImageIcon("jav/champ3.png");//이미지 불러오기
    	private Image cimg3 = img3.getImage();
    	private ImageIcon img4 = new ImageIcon("jav/champ4.png");//이미지 불러오기
    	private Image cimg4 = img4.getImage();
    	private ImageIcon img5 = new ImageIcon("jav/champ5.png");//이미지 불러오기
    	private Image cimg5 = img5.getImage();
    	private ImageIcon ss1 = new ImageIcon("jav/slash1.png");//이미지 불러오기
    	private Image slash1 = ss1.getImage();
    	private ImageIcon ss2 = new ImageIcon("jav/slash2.png");//이미지 불러오기
    	private Image slash2 = ss2.getImage();
    	private ImageIcon ss3 = new ImageIcon("jav/slash3.png");//이미지 불러오기
    	private Image slash3 = ss3.getImage();
    	
    	private ImageIcon dimg1 = new ImageIcon("jav/dragon.png");//이미지 불러오기
    	private Image dcimg1 = dimg1.getImage();
    	private ImageIcon dimg2 = new ImageIcon("jav/dragon2.png");//이미지 불러오기
    	private Image dcimg2 = dimg2.getImage();
    	private ImageIcon dimg3 = new ImageIcon("jav/dragon_fire.png");//이미지 불러오기
    	private Image dcimgf1 = dimg3.getImage();
    	private ImageIcon dimg4 = new ImageIcon("jav/dragon_fire2.png");//이미지 불러오기
    	private Image dcimgf2 = dimg4.getImage();
    	private ImageIcon dimg5 = new ImageIcon("jav/dragon_skil.png");//이미지 불러오기
    	private Image dcimgs1 = dimg5.getImage();
    	private ImageIcon dimg6 = new ImageIcon("jav/dragon_skil2.png");//이미지 불러오기
    	private Image dcimgs2 = dimg6.getImage();
    	private ImageIcon ff1 = new ImageIcon("jav/Sfire.png");//이미지 불러오기
    	private Image fimg1 = ff1.getImage();
    	private ImageIcon ff2 = new ImageIcon("jav/Sfire2.png");//이미지 불러오기
    	private Image fimg2 = ff2.getImage();
    	private ImageIcon buff = new ImageIcon("jav/dragon_buff.png");//이미지 불러오기
    	private Image Dbuff = buff.getImage();
    	private ImageIcon buff2 = new ImageIcon("jav/dragon_buff2.png");//이미지 불러오기
    	private Image Dbuff2 = buff2.getImage();
        
		public void paintComponent(Graphics g){
            super.paintComponent(g);
            Font upFont = new Font("고딕",Font.BOLD, 12);
            g.clearRect(0,0,800, 630);
            g.drawImage(img, 0, 0, this);
            
            String ups1 ="+"+ Integer.toString((mini_logic.damage-15)/2);
            g.setFont(upFont);
            g.drawString(ups1, 78, 517);
            if (mini_logic.MaxMini < 35) {
            	String ups2 ="+"+ Integer.toString(mini_logic.MaxMini-10);
                g.drawString(ups2, 182, 517);
            }
            else
            	g.drawString("+Max", 182, 517);
            
            if (mini_logic.speed <= 20) {
            	g.drawString("+Max", 290, 517);
            }
            else {
            	String ups3 ="+"+ Integer.toString(Math.abs((mini_logic.speed-150)/10));
                g.drawString(ups3, 290, 517);
            }
            String ups4 ="+"+ Integer.toString((mini_logic.HP-800)/200);
            g.drawString(ups4, 378, 517);
            String ups5 ="+"+ Integer.toString((user.damage-15));
            g.drawString(ups5, 490, 517);
            String ups6 ="+"+ Integer.toString((user.maxHP-5000)/200);
            g.drawString(ups6, 599, 517);
            if (user.Slash >= 50) {
            	g.drawString("+Max", 708, 517);
            }
            else {
            	String ups3 ="+"+ Integer.toString(user.Slash);
                g.drawString(ups3, 708, 517);
            }

            
            String tos = Integer.toString(mini_logic.castle);
            g.drawImage(HPbar2, 1,0,200, 20,this);
            g.drawImage(HPbar, 1,0,mini_logic.castle/50, 20,this);
            g.drawString(tos, 10, 15);
            String tos2 = Integer.toString(ene_logic.castle);
            g.drawImage(HPbar2, 585,0,200, 20,this);
            g.drawImage(HPbar, 585+(200-ene_logic.castle/50),0,ene_logic.castle/50, 20,this);
            g.drawString(tos2, 750, 15);
            
            Font drawFont = new Font("Arial",Font.BOLD, 17);
            String pp = Integer.toString(user.point);;
            String ptime = String.format("%.3f",(user.time)/1000);
            g.setFont(drawFont);
            g.drawString("POINT: "+pp+'p',340, 15);
            g.drawString("PLAY TIME: "+ptime+"sec",580, 40);
            
            
            if (user.HP>=1) {
            	if (user.Slash >= 1) {
            		if (user.motion<=40 && user.motion>=20) {
            			if(user.motion%3==0) {
            				g.drawImage(slash1, user.ux+20+user.Slash*Math.abs(20-(user.motion/2))-user.Slash,user.uy-user.Slash/2,100+user.Slash,100+user.Slash,this);
            				g.drawImage(slash2, user.ux+10+user.Slash*Math.abs(20-(user.motion/2))-user.Slash,user.uy-user.Slash/2,100+user.Slash,100+user.Slash,this);
            				
            			}
            		    else if(user.motion%3==1) {
            				g.drawImage(slash3, user.ux+20+user.Slash*Math.abs(20-(user.motion/2))-user.Slash,user.uy-user.Slash/2,100+user.Slash,100+user.Slash,this);
            				g.drawImage(slash2, user.ux+10+user.Slash*Math.abs(20-(user.motion/2))-user.Slash,user.uy-user.Slash/2,100+user.Slash,100+user.Slash,this);
            			}
            			else {
            				g.drawImage(slash3, user.ux+20+user.Slash*Math.abs(20-(user.motion/2))-user.Slash,user.uy-user.Slash/2,100+user.Slash,100+user.Slash,this);
            				g.drawImage(slash1, user.ux+10+user.Slash*Math.abs(20-(user.motion/2))-user.Slash,user.uy-user.Slash/2,100+user.Slash,100+user.Slash,this);
            				
            			}
            		}
            	}
            	if (user.motion<0 && user.motion>-10) {
        			g.drawImage(cimg3, user.ux,user.uy,this);
        			user.motion = (user.motion+1);
        		}
            	else if (user.motion<=40 && user.motion>35) {
        			g.drawImage(cimg4, user.ux,user.uy,this);
        			user.motion = (user.motion-1);
        		}
            	else if (user.motion<=35 && user.motion>=20) {
        			g.drawImage(cimg5, user.ux,user.uy,this);
        			user.motion = (user.motion-1);
        		}
            	else if (user.motion>=0 && user.motion<10) {
        			g.drawImage(cimg1, user.ux,user.uy,this);
        			user.motion = ((user.motion+1)%20);
        		}
        		else if (user.motion<20) {
        			g.drawImage(cimg2, user.ux,user.uy,this);
        			user.motion = ((user.motion+1)%20);
        		}
        		g.drawImage(HPbar2,user.ux,user.uy-10,50, 5,this);
                g.drawImage(HPbar,user.ux,user.uy-10,50*user.HP/user.maxHP, 5,this);
        	}
            if (Dragon.HP>=1) {
            	if(Dragon.HP < Dragon.maxHP/4) {
        			g.drawImage(Dbuff2,Dragon.ux+30,Dragon.uy-50,40, 40,this);
        		}
            	if (Dragon.motion<=40 && Dragon.motion>=20 && Dragon.motion%6 < 3) {
    				g.drawImage(fimg1, user.ux-20-850+Dragon.motion*40,user.uy+630-Dragon.motion*30,this);
        		}
            	if(Dragon.motion<=40 && Dragon.motion>=20 && Dragon.motion%6 >= 3) {
            		g.drawImage(fimg2, user.ux-20-850+Dragon.motion*40,user.uy+630-Dragon.motion*30,this);
        		}
            	if (Dragon.motion<-10 && Dragon.motion>=-20) {
        			g.drawImage(dcimgf1, Dragon.ux-228,Dragon.uy+6,this);
        			Dragon.motion = (Dragon.motion+1);
        		}
            	else if (Dragon.motion<0 && Dragon.motion>=-10) {
        			g.drawImage(dcimgf2, Dragon.ux-228,Dragon.uy+6,this);
        			Dragon.motion = (Dragon.motion+1);
        		}
            	else if (Dragon.motion<=40 && Dragon.motion>30) {
        			g.drawImage(dcimgs1, Dragon.ux,Dragon.uy-15,this);
        			Dragon.motion = (Dragon.motion-1);
        		}
            	else if (Dragon.motion<=30 && Dragon.motion>=20) {
        			g.drawImage(dcimgs2, Dragon.ux,Dragon.uy-15,this);
        			Dragon.motion = (Dragon.motion-1);
        		}
            	else if (Dragon.motion>=0 && Dragon.motion<10) {
        			g.drawImage(dcimg1, Dragon.ux,Dragon.uy,this);
        			Dragon.motion = ((Dragon.motion+1)%20);
        		}
        		else if (Dragon.motion<20) {
        			g.drawImage(dcimg2, Dragon.ux,Dragon.uy,this);
        			Dragon.motion = ((Dragon.motion+1)%20);
        		}
            	Font dFont = new Font("고딕",Font.BOLD, 10);
            	g.setFont(dFont);
            	String dHP = Integer.toString(Dragon.HP);
                g.drawString(dHP, Dragon.ux,Dragon.uy-10);
        		g.drawImage(HPbar2,Dragon.ux,Dragon.uy-10,100, 5,this);
                g.drawImage(HPbar,Dragon.ux,Dragon.uy-10,100*Dragon.HP/Dragon.maxHP, 5,this);
        	}
            
            for(int i = 0; i < mini_logic.MaxMini; i++) {
            	if (mini_logic.spownCheck[i]==1) {
            		if (Dragon.HP>=1) {
            			if (Dragon.motion<=40 && Dragon.motion>=20 && Dragon.motion%6 < 3) {
            				g.drawImage(fimg1, mini_logic.px[i]-850+Dragon.motion*40,mini_logic.py[i]-10+630-Dragon.motion*30,this);
                		}
                    	else if(Dragon.motion<=40 && Dragon.motion>=20 && Dragon.motion%6 >= 3) {
                    		g.drawImage(fimg2, mini_logic.px[i]-850+Dragon.motion*40,mini_logic.py[i]-10+630-Dragon.motion*30,this);
                		}
            		}
            		if (mini_logic.motion[i]>=1 && mini_logic.motion[i]<10) {
            			g.drawImage(wimg, mini_logic.px[i],mini_logic.py[i],this);
            			mini_logic.motion[i] = ((mini_logic.motion[i]+1)%30)+1;
            		}
            		else if (mini_logic.motion[i]<20) {
            			g.drawImage(wimg3, mini_logic.px[i],mini_logic.py[i],this);
            			mini_logic.motion[i] = ((mini_logic.motion[i]+1)%30)+1;
            		}
            		else if (mini_logic.motion[i]<=30) {
            			g.drawImage(wimg2, mini_logic.px[i],mini_logic.py[i],this);
            			mini_logic.motion[i] = ((mini_logic.motion[i]+1)%30)+1;
            		}
            		g.drawImage(HPbar2,mini_logic.px[i]+10,mini_logic.py[i]-10,30, 2,this);
                    g.drawImage(HPbar,mini_logic.px[i]+10,mini_logic.py[i]-10,30*mini_logic.minian[i]/mini_logic.HP, 2,this);
            	}
            }
            for(int i = 0; i < ene_logic.MaxMini; i++) {
            	if (ene_logic.spownCheck[i]==1) {
            		if (Dragon.HP>=1 && Dragon.HP < Dragon.maxHP/2) {
            			g.drawImage(Dbuff,ene_logic.px[i]+20,ene_logic.py[i]-50,40, 40,this);
            		}
            		if (ene_logic.motion[i]>=1 && ene_logic.motion[i]<10) {
            			g.drawImage(ewimg, ene_logic.px[i],ene_logic.py[i],this);
            			ene_logic.motion[i] = ((ene_logic.motion[i]+1)%30)+1;
            		}
            		else if (ene_logic.motion[i]<20) {
            			g.drawImage(ewimg3, ene_logic.px[i],ene_logic.py[i],this);
            			ene_logic.motion[i] = ((ene_logic.motion[i]+1)%30)+1;
            		}
            		else if (ene_logic.motion[i]<=30) {
            			g.drawImage(ewimg2, ene_logic.px[i],ene_logic.py[i],this);
            			ene_logic.motion[i] = ((ene_logic.motion[i]+1)%30)+1;
            		}
            		g.drawImage(HPbar2,ene_logic.px[i]+10,ene_logic.py[i]-10,30, 2,this);
                    g.drawImage(HPbar,ene_logic.px[i]+10,ene_logic.py[i]-10,30*ene_logic.minian[i]/ene_logic.HP, 2,this);
            	}
            }
            
            
           
            
        }
    }
	int counting = mini_logic.speed;
	int counting2 = ene_logic.speed;
    @Override
    public void run() {
        try{
            while(user.runig) {
                repaint();
                if (ene_logic.castle <= 5000 && Dragon.dspown == false) {
                	Dragon.HP = Dragon.maxHP;
                	Dragon.dspown = true;
                }
                if (user.HP>=1) {
            		if (user.heal == 0 && user.maxHP > user.HP) {
            			user.heal = 20;
                        user.healing = 10 + 5*((user.maxHP-5000)/200);
            			user.HP += user.healing;
            		}
            		if (user.motion<=40 && user.motion>=20) {
            			if (user.ux+90+user.Slash*10 > Dragon.ux) {
                			Dragon.HP -= user.damage;
            			}
            		}
                }
                if (Dragon.HP>=1) {
                	if(Dragon.HP< Dragon.maxHP/2) {
                		ene_logic.damage = 100;
                		Dragon.damage = 100;
                    	ene_logic.speed = 50;
                	}
                	if(Dragon.HP< Dragon.maxHP/4) {
                		ene_logic.damage = 200;
                		Dragon.damage = 200;
                		Dragon.maxHP = 20000;
                	}
                	
                	if (Dragon.motion<=40 && Dragon.motion>=20) {
                		user.HP -= Dragon.damage;
                	}
            		if (Dragon.motion<0 && Dragon.motion>=-20) {
            			
            			if (user.ux > Dragon.ux-228 && user.ux < Dragon.uy) {
            				user.HP -= Dragon.damage; 
            			}
            		}
            		if (Dragon.heal == 0 && Dragon.maxHP > Dragon.HP) {
            			Dragon.heal = 50;
            			Dragon.HP += 100;
            			if(Dragon.HP < Dragon.maxHP/4)
            				Dragon.HP += 300;
            		}
                }
                
                for(int i = 0; i < mini_logic.MaxMini; i++) {
                	if (mini_logic.spownCheck[i]==1) {
                		if (mini_logic.minian[i]>=1) {
                			if (Dragon.HP>=1) {
                				if (Dragon.motion<=40 && Dragon.motion>=20) {
                					mini_logic.minian[i] -= Dragon.damage*2;
                            	}
                        		if (Dragon.motion<0 && Dragon.motion>=-20) {
                        			if (mini_logic.px[i] > Dragon.ux-228) {
                        				mini_logic.minian[i] -= Dragon.damage*2; 
                        			}
                        		}
                        		if (mini_logic.px[i] > Dragon.ux-10) {
                        			Dragon.HP -= mini_logic.damage/100;
                        			ene_logic.battleLine = Dragon.ux+10;
                        		}
                    		}
                    		if(mini_logic.px[i]<ene_logic.battleLine) {
                    			if(mini_logic.px[i] < ene_logic.attackLine)
                    				mini_logic.px[i] += 1;
                    			else
                    				ene_logic.castle -= mini_logic.damage;
                    		}
                    		if(mini_logic.px[i]>=ene_logic.battleLine) {	
                    			mini_logic.minian[i] -= ene_logic.damage;
                    		}
                    		if(mini_logic.battleLine<mini_logic.px[i]) {
                    			mini_logic.battleLine = mini_logic.px[i];
                    		}
                  	
                    	}
                    	else if(mini_logic.minian[i]<=0) {
                    		mini_logic.spownCheck[i] = 0;
                    		mini_logic.battleLine = mini_logic.spownLine;
                    	}
                	}
                	
                		
                	if (mini_logic.spownCheck[i]!=1) {
                		if(counting >= mini_logic.speed) {
                			mini_logic.minian[i] = mini_logic.HP;
                			mini_logic.px[i] = mini_logic.spownLine;
                			mini_logic.py[i] = 430;
                			counting = 0;
                			mini_logic.motion[i] = 1;
                			mini_logic.spownCheck[i] = 1;
                		}
                	}		
                }
                for(int i = 0; i < ene_logic.MaxMini; i++) {
                	if (ene_logic.spownCheck[i]==1) {
                		if (ene_logic.minian[i]>=1) {
                    		if (user.HP>=1) {
                        		if (user.motion<=40 && user.motion>=20) {
                        			if (ene_logic.px[i] < user.ux+90+user.Slash*10 && ene_logic.px[i] > user.ux && ene_logic.py[i] < user.uy+80) {
                        				ene_logic.minian[i] -= user.damage*4; 
                        			}
                        		}
                        		if (ene_logic.px[i] < user.ux+50 && ene_logic.px[i] > user.ux && ene_logic.py[i] < user.uy+60) {
                        			user.HP -= ene_logic.damage/4;
                        		}
                    		}
                    		if(ene_logic.px[i]>mini_logic.battleLine) {
                    			if(ene_logic.px[i] > mini_logic.attackLine)
                    				ene_logic.px[i] -= 1;
                    			else
                    				mini_logic.castle -= ene_logic.damage;
                    		}
                    		if(ene_logic.px[i]<=mini_logic.battleLine) {
                    			ene_logic.minian[i] -= mini_logic.damage;
                    		}
                    		if(ene_logic.battleLine>ene_logic.px[i]) {
                    			ene_logic.battleLine = ene_logic.px[i];
                    		}
                    	}
                    	else if(ene_logic.minian[i]<=0) {
                    		ene_logic.spownCheck[i] = 0;
                    		user.point += user.ppp;
                    		if(Dragon.HP>=1) {
                    			user.ppp = 10;
                    			if(Dragon.HP<Dragon.maxHP/2) {
                    				user.ppp = 30;
                    			}
                    			if(Dragon.HP<Dragon.maxHP/4) {
                    				user.ppp = 50;
                    			}
                    		}
                    		ene_logic.battleLine = ene_logic.spownLine;
                    	}
                	}
                	
                		
                	if (ene_logic.spownCheck[i]!=1) {
                		if(counting2 >= ene_logic.speed) {
                			ene_logic.minian[i] = ene_logic.HP;
                			ene_logic.px[i] = ene_logic.spownLine;
                			ene_logic.py[i] = 420;
                			counting2 = 0;
                			ene_logic.motion[i] = 1;
                			ene_logic.spownCheck[i] = 1;
                			if (Dragon.HP>=1 && Dragon.HP< Dragon.maxHP/2) {
                				 ene_logic.HP = 10000;
                			}
                			
                		}
                	}
                	
                }
                
                Thread.sleep((20*user.RUNspeed)/10);
                counting += 1;
                counting2 += 1;
                user.time += (20*user.RUNspeed)/10;
                if(user.jump) {
                	if (user.uy < 280)
                		user.jump = false;
                	user.uy -= (user.uy-200)/10;
                }
                if(user.kleft&& user.ux > 0) {
                	user.ux -= 5;
                }
                if(user.kright && user.ux < 740) {
                	user.ux += 5;
                }
                if(!user.jump && user.uy <= 393)
                	user.uy += (user.uy-220)/10;
                if(user.kspace) {
                	user.motion=40;
            		user.attack=20;
            		user.kspace = false;
                }
                if (user.attack>0)
                	user.attack -= 1;
                if (user.heal>0)
                	user.heal -= 1;
                if (Dragon.fire>0)
                	Dragon.fire -= 1;
                if (Dragon.skil>0)
                	Dragon.skil -= 1;
                if (Dragon.heal>0)
                	Dragon.heal -= 1;
                if (Dragon.fire==0 && Dragon.skil != 0 && Dragon.motion<22) {
                	Dragon.motion=-20;
                	if(Dragon.HP < Dragon.maxHP/4) {
                		Dragon.fire=30;
                	}
                	else
                		Dragon.fire=60;
                }
                if (Dragon.skil == 0) {
                	Dragon.motion=40;
                	if(Dragon.HP < Dragon.maxHP/4) {
                		Dragon.skil=100;
                	}
                	else
                		Dragon.skil=200;
                }
                
                if (mini_logic.castle <= 0 ) {
                	restart();
                	user.runig = false;
                }
                if (ene_logic.castle <= 0) {
                	victory();
                	user.runig = false;
                }
            }
        } 
        catch (Exception e){
            e.printStackTrace();
        }
    }
}

