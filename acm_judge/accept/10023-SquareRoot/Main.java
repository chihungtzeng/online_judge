import java.math.*;
import java.util.*;
import java.io.*;


class Main{
	static BigInteger sqroot(BigInteger y){
		BigInteger left, right, middle;
		BigInteger middlesq, leftsq;
		BigInteger two = new BigInteger("2");
		
		int result;
		
		
		left = new BigInteger("1");
		leftsq = new BigInteger("1");
		while(leftsq.compareTo(y) < 0){
			left = left.multiply(BigInteger.TEN);
			leftsq = left.pow(2);
		} 
		right = left;
		left = right.divide(BigInteger.TEN);
		
		while(left.compareTo(right) <= 0){
			middle = left.add(right);
			middle = middle.divide(two);
			middlesq = middle.pow(2);
			result = middlesq.compareTo(y);
			if(result == 0) return middle;
			else if(result < 0) left = middle.add(BigInteger.ONE);
			else right = middle.subtract(BigInteger.ONE);
		}
		middle = left.add(right);
		middle = middle.divide(two);
		return middle;
	}
	public static void main(String args[]){
		BigInteger x, y;
		int nTest;
		boolean first = true;
		Scanner stdin = new Scanner(System.in);
		nTest = stdin.nextInt();
		while(nTest >= 1){
			nTest--;
			y = stdin.nextBigInteger();
			x = sqroot(y);
			if(first){
				first = false;
			}
			else{
				System.out.println("");
			}
			/*System.out.println("y=" + y.toString());*/
			System.out.println(x.toString());
		}
	}
}