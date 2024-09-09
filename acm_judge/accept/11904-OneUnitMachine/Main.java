import java.math.*;
import java.io.*;
import java.util.*;

class Main {
	static BigInteger bcoef(int n, int m){
		BigInteger bi;
		BigDecimal tmp;
		int i;
		if (m > n - m) {
			m = n - m;
		}
		bi = new BigInteger("1");
		for(i=0; i < m; i++){
			tmp = new BigDecimal(n - i);		
			bi = bi.multiply( tmp.toBigInteger());
		}
		for(i=2; i<=m; i++){
			tmp = new BigDecimal(i);	
			bi = bi.divide( tmp.toBigInteger());
		}
		
		return bi;
	}
	static BigInteger findAns(int nJob, int job[]){
		int sum, i;
		BigInteger result = new BigInteger("1");
		BigInteger coef;
		sum = job[0];
		
		for(i=1; i<nJob; i++){
			coef = bcoef(sum + job[i] - 1, job[i] - 1);
			sum += job[i];
			result = result.multiply(coef);
		}
		result = result.mod(new BigInteger("1000000007"));
		return result;
	}

	public static void main(String args[]){
		Scanner stdin = new Scanner(System.in);
		BigInteger ans;
		int i, k=1, nTest;
		int nJob, job[];
		job = new int[1024];
		nTest = stdin.nextInt();
		while(k <= nTest){
			nJob = stdin.nextInt();
			for(i=0; i<nJob; i++){
				job[i] = stdin.nextInt();
			}
			ans = findAns(nJob, job);
			System.out.println("Case "+k+": "+ans.toString());
			k++;
		}
	}	
}