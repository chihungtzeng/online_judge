import java.io.*;
import java.util.*;

class Main{
	public static void main(String args[]){
		double a, b, S, prob;
		int nTest;
		Scanner stdin = new Scanner(System.in);
		StringBuilder sb;
		Formatter formatter;	
	
		nTest = stdin.nextInt();
		while(nTest >= 1){
			sb = new StringBuilder();
			formatter  = new Formatter(sb);
			nTest--;
			a = stdin.nextDouble();
			b = stdin.nextDouble();
			S = stdin.nextDouble();
			if(S <= Double.MIN_VALUE){
				prob = 1.0;
			}
			else{
				prob = 1 - ((S/a)/b)*(1 + Math.log(a) + Math.log(b) - Math.log(S));
			}
			prob = prob * 100;
			formatter.format("%.6f%%", prob);
			System.out.println(formatter.toString());
		}
	}
}