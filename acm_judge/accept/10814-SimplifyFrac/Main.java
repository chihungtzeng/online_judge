import java.io.*;
import java.math.BigDecimal;
import java.util.Scanner;

class Main{
	static BigDecimal gcd(BigDecimal a, BigDecimal b){
		if(b.compareTo(BigDecimal.ZERO) == 0) return a;
		else return gcd(b, a.remainder(b));
	}
	public static void main(String args[]){
		BigDecimal a, b, g;
		int n;
		String dummy;
		Scanner stdin = new Scanner(System.in);
		n = stdin.nextInt();
		while(n >= 1){
			n--;
			a = new BigDecimal(stdin.next());
			dummy = stdin.next();
			b = new BigDecimal(stdin.next());
			g = gcd(a, b);
			a = a.divideToIntegralValue(g);
			b = b.divideToIntegralValue(g);
			System.out.println(a.toPlainString() + " / " + b.toPlainString());
		}
	}
}