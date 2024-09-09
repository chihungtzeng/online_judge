import java.io.*;
import java.util.*;
import java.math.BigDecimal;

class Main{
	final static int MAX = 367;
	public static void main(String args[]){
		
		BigDecimal fac[] = new BigDecimal[MAX];
		Scanner stdin = new Scanner(System.in);
		StringBuilder sb;
		int i;		
		
		fac[0] = new BigDecimal(1);
		for(i=1; i<MAX; i++){
			fac[i] = new BigDecimal(i);
			fac[i] = fac[i].multiply(fac[i-1]);	
		}
		System.out.println(fac[366].toPlainString());
		/*
		while(0 != (i = stdin.nextInt())){
			
		}
		*/
	}
}