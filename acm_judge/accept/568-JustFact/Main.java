import java.io.*;
import java.math.BigDecimal;
import java.util.Scanner;

class Main{
	public static void main(String args[]){
		final int ub=10001; 
		BigDecimal fac[] = new BigDecimal[ub];
		BigDecimal result[] = new BigDecimal[2];
		BigDecimal tmp,r,q;
		Scanner stdin = new Scanner(System.in);
		StringBuffer sb;
		
		
		int i,nZero,j,k,nDigit;
		
		fac[0] = new BigDecimal(1);
		for(i=1;i<ub;i++){
			fac[i] = fac[i-1].multiply(new BigDecimal(i));
		}

		
		while(stdin.hasNext()){
			i = stdin.nextInt();
			
			nZero = 0;
			j=i;
			while(j>0){
				nZero = nZero + j/5;
				j = j/5;
			}
			tmp = new BigDecimal(fac[i].toPlainString());
			r = new BigDecimal(10);
			r = r.pow(nZero);
			tmp = tmp.divide(r, BigDecimal.ROUND_DOWN);
			
			r = tmp.remainder(new BigDecimal(10));
			
			nDigit=0;
			j=i;
			while(j>0){
				nDigit++;
				j = j /10;
			}
			sb = new StringBuffer();
			j = 5-nDigit;
			for(k=0;k<j;k++){
				sb.append(" ");
			}
			sb.append(i+" -> "+r.toPlainString());
			System.out.println(sb.toString());
		}
	}
}
