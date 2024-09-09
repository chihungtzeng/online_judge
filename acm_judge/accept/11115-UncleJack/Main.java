import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	public static void main(String args[]){
		Scanner stdin = new Scanner(System.in);
		int N, D;
		
		while(stdin.hasNext()){
			N = stdin.nextInt();
			D = stdin.nextInt();
			if((N==0) && (D==0)){
				break;
			}
			System.out.println((new BigInteger(""+N).pow(D).toString()));
		}
	}
}