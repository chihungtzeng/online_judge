import java.io.*;
import java.util.Scanner;
import java.math.BigDecimal;

class Main{
	public static void main(String args[]){
		BigDecimal bi;
		Scanner stdin = new Scanner(System.in);
		
		while(stdin.hasNext()){
			bi = stdin.nextBigDecimal();
			bi = bi.multiply(stdin.nextBigDecimal());
			System.out.println(bi.toPlainString());
		}
	}
}