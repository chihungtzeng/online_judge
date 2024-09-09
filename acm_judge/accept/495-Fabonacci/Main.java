import java.io.*;
import java.util.*;
import java.math.*;

class Main{
	public static void main(String args[]){
		int i;
		int n;
		BigDecimal fab[] = new BigDecimal[5001];
		fab[0] = new BigDecimal(0);
		fab[1] = new BigDecimal(1);
		for(i=2;i<=5000;i++){
			fab[i] = fab[i-1].add(fab[i-2]);
		}
		Scanner stdin = new Scanner(new BufferedInputStream(System.in));
		while(stdin.hasNext()){
			n = stdin.nextInt();
			System.out.println("The Fibonacci number for "+n+" is "+fab[n].toString());
		}
	}
}