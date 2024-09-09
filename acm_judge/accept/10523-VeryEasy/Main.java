import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	final static int MAXA = 16;
	final static int MAXCOEF = 151;
	public static void main(String args[]){
		int i, j, A, N;
		BigInteger bi[][] = new BigInteger[MAXA][MAXCOEF];
		BigInteger coef[] = new BigInteger[MAXCOEF];
		BigInteger ans;
		
		for(i=0; i<MAXCOEF; i++){
			bi[0][i] = BigInteger.ZERO;
		}
		for(i=0; i<MAXCOEF; i++){
			bi[1][i] = BigInteger.ONE;
		}
		for(i=2; i < MAXA; i++){
			bi[i][0] = BigInteger.ONE;
			bi[i][1] = new BigInteger("" + i);
			for(j=2; j<MAXCOEF; j++){
				bi[i][j] = bi[i][1].pow(j);
			}
		}
		for(i=0; i<MAXCOEF; i++){
			coef[i] = new BigInteger(""+i);
		}
		
		Scanner stdin = new Scanner(System.in);
		while(stdin.hasNext()){
			N = stdin.nextInt();
			A = stdin.nextInt();
			if((A == 0) && (N == 0)){
				continue;
			}
			else if(A == 0){
				System.out.println("0");
			} else if (A == 1){
				i = (N*(N+1)) >> 1;
				System.out.println(""+i);
			} else {
				ans = new BigInteger(""+0);
				for(i=1; i<=N; i++){
					ans = ans.add(bi[A][i].multiply(coef[i]));
				}
				System.out.println(ans.toString());
			}
		}
	}
}