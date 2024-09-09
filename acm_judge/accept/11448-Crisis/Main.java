import java.io.*;
import java.math.BigDecimal;
import java.util.Scanner;

class Main{
	public static void main(String args[]){
		BigDecimal a, b, c;
		int nTest;
		Scanner stdin = new Scanner(System.in);
		nTest = stdin.nextInt();
		while(nTest >= 1){
			nTest--;
			a = stdin.nextBigDecimal();
			b = stdin.nextBigDecimal();
			c = a.subtract(b);
			System.out.println(c.toPlainString());
		}
	}
}