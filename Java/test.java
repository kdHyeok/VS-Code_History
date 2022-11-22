
import java.io.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class test {
	

	public static void main(String[] args) throws IOException{
		String filePath = "Game_Data.txt"; 
	    File file = new File(filePath); // File객체 생성 
		if(!file.exists()){ // 파일이 존재하지 않으면 
			file.createNewFile(); // 신규생성 } 
		}
		// BufferedWriter 생성 
		BufferedWriter writer = new BufferedWriter(new FileWriter(file)); // 파일에 쓰기
		writer.write("하이루!"); 
		writer.newLine(); 
		writer.write("반가워!"); 
		writer.newLine(); // 버퍼 및 스트림 뒷정리 
		writer.flush(); // 버퍼의 남은 데이터를 모두 쓰기 
		writer.close(); // 스트림 종료
		
		
		if(file.exists()){ // 파일이 존재하면
			BufferedReader reader = new BufferedReader(new FileReader(file));
			System.out.println("파일내용 출력------------------"); 
			String line = null; 
			while ((line = reader.readLine()) != null){ 
				System.out.println(line); 
			} 
			System.out.println("------------------------------"); 
			reader.close(); 
		}
	}
}


