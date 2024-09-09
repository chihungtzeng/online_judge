import java.io.*;
import java.util.*;
import java.math.*;

class Main {
	
	static int findBase(int exp, BigDecimal n){
		int left,right,middle;
		BigDecimal trial;

		right=2;
		trial = new BigDecimal(right);
		while(n.compareTo(trial.pow(exp))==1){
			right = right * 2;			
			trial = new BigDecimal(right);
		}
		left = right/2;
		do {
			middle = (left+right)/2;
			trial = new BigDecimal(middle);
			switch (n.compareTo(trial.pow(exp))){
				case -1:
					right=middle;
					break;
				case 0:
					return middle;
				case 1:
					left = middle+1;
					break;					
			}
		} while (left <= right);
		return -1;
	}
	public static void main(String args[]){
		int exp;
		BigDecimal result;
		Scanner stdin = new Scanner(new BufferedInputStream(System.in));
		while (stdin.hasNext()){
			exp = Integer.parseInt(stdin.next());
			result = stdin.nextBigDecimal();
			System.out.println(""+findBase(exp,result));
		}
		
	}
}
