import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	final static int LEN = 801;
	public static void main(String args[]){
		int n;
		Scanner stdin = new Scanner(System.in);
		BigInteger ans[] = new BigInteger[LEN];
		ans[1] = BigInteger.ZERO;
		ans[2] = BigInteger.ONE;
		for(n=3; n<LEN; n++){
			ans[n] = ans[n-1].add(ans[n-2]).multiply(new BigInteger(""+(n-1)));
		}
		while(stdin.hasNext()){
			n = stdin.nextInt();
			if(n == -1) System.exit(0);
			else System.out.println(ans[n].toString());
		}
	}
}