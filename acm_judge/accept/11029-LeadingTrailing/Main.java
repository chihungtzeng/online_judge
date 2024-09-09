import java.math.*;
import java.io.*;
import java.util.*;

public class Main{
	static void solve(int base, int expn){
		BigInteger bi = new BigInteger(""+base);
		int len;
		String s;
		bi = bi.pow(expn);
		s = bi.toString();
		len = s.length();
		System.out.println(s.substring(0,3) + "..." + s.substring(len-3, len));
	}
	public static void main(String args[]){
		Scanner stdin = new Scanner(System.in);
		int nTest, base, expn;
		nTest = stdin.nextInt();
		
		while(nTest > 0){
			nTest--;
			base = stdin.nextInt();
			expn = stdin.nextInt();
			solve(base, expn);
		}
	}
}