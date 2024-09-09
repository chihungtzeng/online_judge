import java.io.*;
import java.math.*;
import java.util.*;

public class Main{
	public static BigInteger calcFactorial(int n){
		/*return n!*/
		BigInteger result = new BigInteger("1");
		int i;
		for(i=2; i<=n; i++){
			result = result.multiply(new BigInteger(""+i));
		}
		return result;
	}
	public static BigInteger getTerm(int n, int k){
		/*
			return (n-k)!/(k!(n-2k)!)
		*/
		BigInteger result = calcFactorial(n);
		result = result.divide(calcFactorial(k));
		result = result.divide(calcFactorial(n - 2*k));
		System.out.println("getTerm("+n+","+k+") = "+result.toString());
		return result;
	}
	public static void main(String args[]){
		BigInteger ans;
		Scanner stdin = new Scanner(System.in);
		int i, j, nTest, n;
		
		
		nTest = stdin.nextInt();
		while(nTest > 0){
			nTest -= 1;
			n = stdin.nextInt();
			ans = BigInteger.ZERO;
			for(i=n/2; i>=0; i--){
				ans = ans.add(getTerm(n, i));
			}
			System.out.println(ans.toString());
		}
		
	}
}