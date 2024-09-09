import java.io.*;
import java.util.Scanner;
import java.math.BigDecimal;


class Main{
	final static int MAXN = 301;
	
	
	static void initFac(BigDecimal fac[]){
		int i;
		fac[0] = new BigDecimal(1);
		for(i=1; i<MAXN; i++){
			fac[i] = fac[i-1].multiply(new BigDecimal(i));
		}
	}
	
	
	static BigDecimal catalanNum(int n, BigDecimal demoninator){
		BigDecimal bi;
		int i;
		
		bi = new BigDecimal(n << 1);
		for(i = (n << 1) - 1; i >= n + 1; i--){
			bi = bi.multiply(new BigDecimal(i));
		}
		bi = bi.divideToIntegralValue(demoninator);
		bi = bi.divideToIntegralValue(new BigDecimal(n+1));
		return bi;
	}
	public static void main(String args[]){
		int n;
		BigDecimal result;
		Scanner stdin = new Scanner(System.in);
		BigDecimal fac[] = new BigDecimal[MAXN];	
		
		initFac(fac);
		while(stdin.hasNext()){
			n = stdin.nextInt();
			if( n == 0){
				System.exit(0);
			}
			result = fac[n];
			result = result.multiply(catalanNum(n, fac[n]));
			System.out.println(result.toPlainString());
		}
	}
}