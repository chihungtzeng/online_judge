import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	static void solve(BigInteger input){
		BigInteger sq = new BigInteger("1");
		BigInteger base, ans;
		BigInteger square = new BigInteger("1");
		StringBuilder sb;
		int len, i;
		base = new BigInteger("1");
		while(square.compareTo(input) < 0){
			base = sq;
			sq  = sq.multiply(BigInteger.TEN);
			square = sq.pow(2);
		}
		sq = base;
		do{
			square = sq.pow(2);
			ans = sq;
			sq = sq.add(base);
		} while(square.compareTo(input) <= 0);
		
			ans = ans.subtract(base);
				
		sb = new StringBuilder(ans.toString());
		len = sb.length();
		for(i=1; i<len; i++){
			sb.setCharAt(i, '0');
		}
		
		System.out.println(sb.toString());
	}

	public static void main(String args[]){
		Scanner stdin = new Scanner(System.in);
		BigInteger input;
		while(stdin.hasNextBigInteger()){
			input = stdin.nextBigInteger();
			if(input.compareTo(BigInteger.ZERO) == 0){
				System.exit(0);
			}
			else {
				solve(input);
			}
		}
	} 
}