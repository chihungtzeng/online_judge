import java.util.*;
import java.math.*;
import java.io.*;
import java.security.SecureRandom;

public class Main{
	private final static SecureRandom random = new SecureRandom();
	
	static long Pollard(long n){
		/*return a prime factor of n*/
		    
		BigInteger N = new BigInteger(""+n);
	 	BigInteger divisor;
      BigInteger c  = new BigInteger(N.bitLength(), random);
      BigInteger x  = new BigInteger(N.bitLength(), random);
      BigInteger xx = x;
		if(n == 1) return 1;
		if(N.isProbablePrime(100)){
			return 1;
		}


        do {
            x  =  x.multiply(x).mod(N).add(c).mod(N);
            xx = xx.multiply(xx).mod(N).add(c).mod(N);
            xx = xx.multiply(xx).mod(N).add(c).mod(N);
            divisor = x.subtract(xx).gcd(N);
        } while((divisor.compareTo(BigInteger.ONE)) == 0);

        return divisor.longValue();
	}


	static long solve(long n){
		/*find the number of factorization of n*/
		long divisor, primeFactor;
		long ans = 1, k;
		boolean done = false; 
		
		
		while(!done){
			primeFactor = Pollard(n);
			while(1 != (divisor = Pollard(primeFactor))){
				primeFactor = divisor;
			}
/*			System.out.println("prime factor of "+n+": "+ primeFactor);*/
			if(primeFactor == 1){
				done = true;
			}	
			else{	
				k = 1;
				do{
					k++;
					n = n / primeFactor;
				} while(n % primeFactor == 0);
				/*System.out.println("k = "+k +" n = "+n);*/
				ans = ans * k;
			}
		}
		if(n > 1){
			ans <<= 1;
		}

		return ans;
	}

	public static void main(String args[]){
		Scanner stdin = new Scanner(System.in);
		long input;
		long ans;
		while(stdin.hasNext()){
			input = stdin.nextLong();
			if(input == 0) {
				continue;
			} else if(input == 1) {
				System.out.println("1 1");
			} else {
				ans = solve((input << 2) - 3);
				System.out.println(input + " " + ans);
			}
		}
		System.exit(0);
	}
}
