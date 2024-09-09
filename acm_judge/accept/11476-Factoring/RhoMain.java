import java.io.*;
import java.util.*;
import java.math.*;
import java.security.SecureRandom;

class Main{
	 private final static BigInteger ZERO = new BigInteger("0");
    private final static BigInteger ONE  = new BigInteger("1");
    private final static BigInteger TWO  = new BigInteger("2");
    private final static SecureRandom random = new SecureRandom();
    private final static BigInteger SOBIG = new BigInteger("1000000000000");

	private static int prime[] = new int[80000];
	private static int nPrime = 0;
	private static long primeSq[] = new long[80000];
	private static long bigPrime[] = new long[1600];
	private static int nBigPrime = 0;
	
	public static void buildPrimeTable(){
		int i, t;
		boolean isPrime;
		prime[0] = 2;
		prime[1] = 3;
		prime[2] = 5;
		nPrime = 3;
		for(i=0; i<3; i++){
			primeSq[i] = prime[i]*prime[i];
		}
		t = 7;
		while(t < 1000000){
			isPrime = true;
			for(i=2; (primeSq[i] <= t) && (isPrime); i++){
				if(t % prime[i] == 0) isPrime = false;
			} 
			if(isPrime){
				prime[nPrime] = t;
				primeSq[nPrime++] = t*t;
			}
			t += 4;
			isPrime = true;
			for(i=2; (primeSq[i] <= t) && (isPrime); i++){
				if(t % prime[i] == 0) isPrime = false;
			} 
			if(isPrime){
				prime[nPrime] = t;
				primeSq[nPrime++] = t*t;
			}
			t += 2;
		}
	}

	public static long rho(BigInteger N) {
        BigInteger divisor;
        BigInteger x, xprime;
        long k = 1, ell = 1;

			x = new BigInteger("5");
			xprime = new BigInteger("2");
        while(true){
            divisor = N.gcd(xprime.subtract(x));
            if(divisor.compareTo(BigInteger.ONE) == 0){
            	k = k - 1;
            	if(k == 0){
            		xprime = x;
            		ell = ell << 1;
            		k = ell;
            	}
            	x = x.multiply(x).add(BigInteger.ONE).mod(N);
            }
            else if (divisor.compareTo(N) == 0){
            	return 1;
            }
            else {
            	return divisor.longValue();
            } 
        } 

        
    }
	/*
   public static long rho(BigInteger N) {
        BigInteger divisor;
        BigInteger c  = new BigInteger(N.bitLength(), random);
        BigInteger x  = new BigInteger(N.bitLength(), random);
        BigInteger xx = x;

        // check divisibility by 2
        if (N.mod(TWO).compareTo(ZERO) == 0) return 2;

        do {
            x  =  x.multiply(x).mod(N).add(c).mod(N);
            xx = xx.multiply(xx).mod(N).add(c).mod(N);
            xx = xx.multiply(xx).mod(N).add(c).mod(N);
            divisor = x.subtract(xx).gcd(N);
        } while((divisor.compareTo(ONE)) == 0);

        return divisor.longValue();
    }
	*/
  
   public static int factoring(long n, long factor[], int fpow[]){
   	int nFactor = 0, i;
   	BigInteger N;
   	long f1, f2, ftmp;
   	for(i=0; (i < nPrime) && (primeSq[i] <= n); i++){
   		if(n % prime[i] == 0){
   			fpow[nFactor] = 0;
   			factor[nFactor] = prime[i];
   			/*System.out.println("found factor:"+prime[i]);*/
   			do{
   				fpow[nFactor]++;
   				n = n / prime[i];
   			} while(n % prime[i] == 0);
   			nFactor++;
   		}
   	}
   	
   	if(n == 1) return nFactor;
   	
   	N = new BigInteger(""+n);
   	if((n > 1) && (SOBIG.compareTo(N) > 0) ){
   		fpow[nFactor] = 1;
   		factor[nFactor++] = n;
   		return nFactor;
   	}
   	
   	

		if(N.isProbablePrime(20)){
			factor[nFactor] = n;
			bigPrime[nBigPrime++] = n;
			fpow[nFactor++] = 1;
			return nFactor;
		}   	
		boolean found = false;
		f1 = 0;
		for(i=0; (i<nBigPrime) && !found; i++){
			if(n % bigPrime[i] == 0){
				found = true;
				f1 = bigPrime[i];
			}
		}
   	
   	f1 = (found)? f1: rho(N);
   	f2 = n / f1;
   	if(f1 > f2){
   		ftmp = f1;
   		f1 = f2;
   		f2 = ftmp;
   	}
   	
   	if(f1 == f2){
   		factor[nFactor] = f1;
   		fpow[nFactor++] = 2;
   		bigPrime[nBigPrime++] = f1;
   		return nFactor;
   	}
   	else{
   		factor[nFactor] = f1;
   		fpow[nFactor++] = 1;
   		factor[nFactor] = f2;
   		fpow[nFactor++] = 1;
   		bigPrime[nBigPrime++] = f1;
   		bigPrime[nBigPrime++] = f2;
   		return nFactor;
   	}
   }
	public static void main(String args[]){
		int nTest, i;
		long n;
		long factor[] = new long[128];
		int fpow[] = new int[128];
		int nFactor;
		
		Scanner stdin = new Scanner(System.in);
		nTest = stdin.nextInt();
		buildPrimeTable();
		while(nTest >= 1){
			nTest--;
			n = stdin.nextLong();
			nFactor = factoring(n, factor, fpow);
			System.out.print(n+" =");
			if(fpow[0] == 1){
				System.out.print(" "+factor[0]);
			}
			else{
				System.out.print(" "+factor[0]+"^"+fpow[0]);
			}
			for(i=1; i<nFactor; i++){
				if(fpow[i] == 1){
				System.out.print(" * "+factor[i]);
				}
				else{
					System.out.print(" * "+factor[i]+"^"+fpow[i]);
				}
			}
			System.out.println("");
		}
		/*
		for(i=0; i<100; i++){
			System.out.print(prime[i]+" ");
		}
		*/
		
	}
}
