import java.io.*;
import java.math.*;
import java.util.*;


class Main{
	public static void main(String args[]){
		Scanner stdin;
		BigDecimal fac[] = new BigDecimal[1001];
		int i;
		int n;
		fac[0] = new BigDecimal(1);		
		fac[1] = new BigDecimal(1);
		for(i=2;i<1001;i++){
			fac[i] = fac[i-1].multiply(new BigDecimal(i));
		}
		
		stdin = new Scanner(new BufferedInputStream(System.in));
		while(stdin.hasNext()){
			n = stdin.nextInt();
			System.out.println(n+"!");
			System.out.println(fac[n].toString());
		}
	}
}