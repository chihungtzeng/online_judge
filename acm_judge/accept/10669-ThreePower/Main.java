import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	final static int MAX = 64;
	static BigInteger set3[];
	static String output[] = new String[MAX];
	
	
	static void findSet3(){
		int i;
		set3 = new BigInteger[MAX];
		
		
		set3[0] = BigInteger.ONE;
		output[0] = set3[0].toString();
		for(i=1; i<MAX; i++){
			set3[i] = set3[i-1].shiftLeft(1).add(set3[i-1]);
			output[i] = set3[i].toString();
			/*System.out.println(i+": "+output[i]);*/
		}
	}	

	public static void main(String args[]){
		Scanner stdin = new Scanner(System.in);
		int i;
		boolean first;
		BigInteger input;		
		findSet3();
		
		while(stdin.hasNext()){
			input = stdin.nextBigInteger();
			if(input.compareTo(BigInteger.ZERO) == 0){
				break;
			}
			input = input.subtract(BigInteger.ONE);
			System.out.print("{ ");
			for(i=0, first = true; input.compareTo(BigInteger.ZERO) > 0; i++, input = input.shiftRight(1)){
				if(input.testBit(0)){
					if(first){
						System.out.print(output[i]+"");
						first = false;
					} else {
						System.out.print(", "+output[i]);
					}
				}
			}
			if(!first){
				System.out.print(" ");
			}
			System.out.println("}");
		}
	}
}