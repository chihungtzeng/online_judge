import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	final static int LEN = 5000;
	static BigInteger fib[];
	
	static void buildFib(){
		int i;
		fib = new BigInteger[LEN];
		fib[1] = new BigInteger("1");
		fib[2] = new BigInteger("1");
		for(i=3; i<LEN; i++){
			fib[i] = fib[i-1].add(fib[i-2]);
		}
	}
	public static void main(String args[]){
		int n;
		Scanner stdin = new Scanner(System.in);
		buildFib();
		
		while(stdin.hasNext()){
			n = stdin.nextInt();
			System.out.println(fib[n].toString());
		}
	}
}