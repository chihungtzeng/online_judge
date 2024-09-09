import java.io.*;
import java.util.*;
import java.math.*;

class Main{
	public static boolean hasForbiddenDigit(int n){
		while(n>0){
			if (( 0 == (n % 10) % 2) || ( 5 == (n % 10) )){
				return true;
			}
			n = n/10;
		}
		return false;
	}
	public static boolean isIncreasing(int n){
		int lsb,preLsb;
		preLsb = n % 10;
		n= n/10;
		while(n>0){
			lsb = n % 10;
			if(lsb > preLsb) return false;
			
			preLsb = lsb;
			n = n/10; 
		}
		return true;
	}
	public static int pow10(int nDigit){
		if(nDigit == 1) return 10;
		else return pow10(nDigit/2)*pow10(nDigit - nDigit/2);
	}
	public static int findNumDigit(int n){
		int nDigit=1;
		
		while(n > 10){
			nDigit++;
			n = n/10;
		}
		return nDigit;
	}
	public static int rotateLeft(int n){
		int nDigit;
		int divider;
		
		nDigit = findNumDigit(n) - 1;
		divider = pow10(nDigit);
		return (n % divider)*10 + (n/divider);
	}
	public static boolean isCircularPrime(int n){
		int i;
		int nDigit;
		BigInteger bi;
		boolean result=true;
		if (hasForbiddenDigit(n)|| !isIncreasing(n)) return false;

		nDigit = findNumDigit(n);
		
		for(i=0;i<nDigit;i++){
			bi = new BigInteger(n+"");
			result = result & bi.isProbablePrime(10);
			if (!result) return false; 
		}
		System.out.println("Found Circ Prime: "+n);
		return true;
	}
	public static void main(String args[]){
		BigDecimal bigDec;
		Scanner stdin;
		
		int left, right;
		int i,count;
		
		stdin = new Scanner(System.in);
		while(stdin.hasNext()){
			left = stdin.nextInt();
			if ( -1 == left ){
				System.exit(0);
			}
			right = stdin.nextInt();
			count = 0;
			for(i=left; i<=right;i++){
				if(isCircularPrime(i)){
					count++;
				}
			}
			if (count == 0){
				System.out.println("No Circular Primes.");
			}
			else {
				System.out.println(count+" Circular Primes.");
			}	
		}
	}
}