import java.io.*;
import java.math.*;
import java.util.*;

class Main{
	static BigDecimal gcd(BigDecimal a, BigDecimal b){
		BigDecimal result;
		if(b.compareTo(BigDecimal.ZERO) == 0) return a;
		else {
			result = a.remainder(b);
			return gcd(b, result);
		}
	}
	public static void main(String args[]){
		Scanner stdin = new Scanner(System.in);
		BigDecimal biga, bigb, downa, downb, divisor;
		long a, b;
		int i, k=1, len;
		while(stdin.hasNext()){
			a = stdin.nextLong();
			b = stdin.nextLong();
			if((a == 0) && (b == 0)){
				System.exit(0);
			}
			biga = new BigDecimal(a);
			bigb = new BigDecimal(b);
			biga = biga.multiply(new BigDecimal(a*a + 6*a + 11));
			bigb = bigb.multiply(new BigDecimal(b*b + 6*b + 11));
			downa = new BigDecimal(18*(a+1));
			downa = downa.multiply(new BigDecimal((a+2)*(a+3)));
			downb = new BigDecimal(18*(b+1));
			downb = downb.multiply(new BigDecimal((b+2)*(b+3)));
			
			biga = biga.multiply(bigb);
			downa = downa.multiply(downb);
			divisor = gcd(biga, downa);
			biga = biga.divideToIntegralValue(divisor);
			downa = downa.divideToIntegralValue(divisor);
			
			System.out.println("Case "+k+":");
			System.out.println(biga.toPlainString());
			len = downa.toPlainString().length();
			for(i=0; i<len; i++){
				System.out.print("-");
			}
			System.out.println("");
			System.out.println(downa.toPlainString());
			System.out.println("");
			k++;
		}
	}
}