import java.util.*;
import java.io.*;
import java.math.BigDecimal;

class Main{
	public static void main(String args[]){
		Scanner stdin = new Scanner(System.in);
		BigDecimal ub,left,right;
		BigDecimal fib[] = new BigDecimal[500];
		int nFib;
		int count;
		boolean done=false;

		ub = new BigDecimal(10);
		ub = ub.pow(100);
		fib[0] = new BigDecimal(1);
		fib[1] = new BigDecimal(1);
		nFib=2;
		while(ub.compareTo(fib[nFib-1]) == 1){
			fib[nFib] = fib[nFib-1].add(fib[nFib-2]);
			nFib++;
		}
		
		while(!done){
			count = 0;
			left = stdin.nextBigDecimal();
			right = stdin.nextBigDecimal();
			if( (left.compareTo(new BigDecimal(0) ) == 0) && (right.compareTo(new BigDecimal(0)) == 0)){
				done = true;
			}
			else {
				int i;
				for(i=1;i<nFib;i++){
					if (
						(fib[i].compareTo(left) >= 0) && 
						(fib[i].compareTo(right) <= 0)
						){
						count++;
					}
				}
				System.out.println(""+count);
			}
		}
	}
}
