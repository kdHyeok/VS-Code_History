
import java.io.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class test {
	

	public static void main(String[] args) throws IOException{
		String filePath = "Game_Data.txt"; 
	    File file = new File(filePath); // File��ü ���� 
		if(!file.exists()){ // ������ �������� ������ 
			file.createNewFile(); // �űԻ��� } 
		}
		// BufferedWriter ���� 
		BufferedWriter writer = new BufferedWriter(new FileWriter(file)); // ���Ͽ� ����
		writer.write("���̷�!"); 
		writer.newLine(); 
		writer.write("�ݰ���!"); 
		writer.newLine(); // ���� �� ��Ʈ�� ������ 
		writer.flush(); // ������ ���� �����͸� ��� ���� 
		writer.close(); // ��Ʈ�� ����
		
		
		if(file.exists()){ // ������ �����ϸ�
			BufferedReader reader = new BufferedReader(new FileReader(file));
			System.out.println("���ϳ��� ���------------------"); 
			String line = null; 
			while ((line = reader.readLine()) != null){ 
				System.out.println(line); 
			} 
			System.out.println("------------------------------"); 
			reader.close(); 
		}
	}
}


