import java.math.*;
import java.io.*;
import java.util.*;

public class Main{
	final static int LEN = 50001;
	public static void main(String args[]){
		BigInteger bi[] = new BigInteger[LEN];
		int i;
		bi[1] = BigInteger.ONE;
		for(i=2; i<LEN; i++){
			bi[i] = bi[i-1].add(new BigInteger(""+i).pow(3));
		}   
		Scanner stdin = new Scanner(System.in);
		while(stdin.hasNext()){
			i = stdin.nextInt();
			System.out.println(bi[i].toString());
		}
	}
}