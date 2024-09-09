import java.io.*;
import java.math.*;

class Main{

	static BigDecimal bcoef(int n, int m){
		BigDecimal bi;
		int i;
		if (m > n - m) {
			m = n - m;
		}
		bi = new BigDecimal(1);
		for(i=0; i < m; i++){		
			bi = bi.multiply(new BigDecimal(n - i));
		}
		for(i=2; i<=m; i++){
			bi = bi.divideToIntegralValue(new BigDecimal(i));
		}
		
		return bi;
	}
	public static void main(String args[]){
		int n, m;
		n = Integer.parseInt(args[0]);
		m = Integer.parseInt(args[1]);
		System.out.println("C("+n+", "+m+") = "+ bcoef(n,m).toPlainString());
	}
}
