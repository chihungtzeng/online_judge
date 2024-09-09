import java.io.*;
import java.util.*;
import java.math.BigDecimal;

class Main{
	public static void main(String args[]){
		BigDecimal fac[],result[],target,bd0;;
		Scanner stdin;
		int i,n,d;
		
		fac = new BigDecimal[1000];
		result = new BigDecimal[2];
		bd0 = new BigDecimal(0);
		
		fac[0] = new BigDecimal(1);
		for(i=1;i<1000;i++){
			fac[i] = fac[i-1].multiply(new BigDecimal(i));
		}		
		
		stdin = new Scanner(System.in);
		while(stdin.hasNext()){
			n = stdin.nextInt();
			d = stdin.nextInt();
			if(d < n){
				System.out.println(d+" divides "+n+"!");
				continue;
			}
			if(n<1000){
				target = fac[n];
			}
			else {
				target = fac[999];
				for(i=1000;i<=n;i++){
					target = target.multiply(new BigDecimal(i));
				}
			}
			result = target.divideAndRemainder(new BigDecimal(d));
			if (result[1].compareTo(bd0) == 0){
				System.out.println(d+" divides "+n+"!");
			}
			else{
				System.out.println(d+" does not divide "+n+"!");
			}
		}
	}
}