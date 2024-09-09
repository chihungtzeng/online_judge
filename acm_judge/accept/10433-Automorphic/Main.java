import java.io.*;
import java.math.*;
import java.util.*;

public class Main{
	public static void main(String args[]){
		BigInteger sq, input;
		String s, ssq;
		int sLen, sqLen;
		Scanner stdin = new Scanner(System.in);
		while(stdin.hasNext()){
			s = stdin.next();
			sLen = s.length();
			input = new BigInteger(s);
			if(input.compareTo(BigInteger.ZERO) == 0){
				System.out.println("Not an Automorphic number.");
				continue;
			} 
			sq = input.pow(2);
			ssq = sq.toString();
			sqLen = ssq.length();
			ssq = ssq.substring(sqLen >> 1);
			if(ssq.compareTo(s) == 0){
				System.out.println("Automorphic number of "+sLen+"-digit.");
			} else {
				System.out.println("Not an Automorphic number.");
			}
		}
	}
}