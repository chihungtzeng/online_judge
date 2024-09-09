/*
Prime cached, no much gain; 9.564s
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define DEBUG 0
#define COMPOSITE 1
#define PRIME 0
#define SMALL_PRIME_BOUND 100

struct Term{
	long long factor;
	char pow;
};

int nPrime;
int prime[450];
long long cachedPrime[2048];
int nMaxCachedPrime = 1024;
int nCachedPrime = 0;


int compareTerm(const void *a, const void *b){
	struct Term *x, *y;
	x = (struct Term *)a;
	y = (struct Term *)b;
	if(x->factor > y->factor) return 1;
	else if (x->factor == y->factor) return 0;
	else return -1;
}

long long gcd(long long a, long long b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}

long long multiplyMod(long long a, long long b, long long n){
	/*
		return (a*b)%n
	*/
	unsigned long long tmp[4], bitArray[2][2];
	unsigned long long carry;
	long long result;
	char i, j, pos;
	for(i=0; i<4; i++) tmp[i] = 0;
	bitArray[0][1] = a >> 32; /*msb*/
	bitArray[0][0] = (unsigned long long)a & 0xffffffffUL; /*lsb*/
	bitArray[1][1] = b >> 32; /*msb*/
	bitArray[1][0] = (unsigned long long)b & 0xffffffffUL; /*lsb*/
	for(i=0; i<2; i++){
		carry = 0;
		for(j=0; j<2; j++){
			pos = i + j;
			tmp[pos] += bitArray[0][i]*bitArray[1][j] + carry;
			carry = tmp[pos] >> 32;
			tmp[pos] = tmp[pos] & 0xffffffffUL;
		}
		if(carry > 0){
			tmp[pos + 1] += carry; 
		}
	}
	#if 0
	for(i=3; i>=0; i--){
		printf("%llx ", tmp[i]);
	}
	#endif
	result = 0;
	for(i=3; i>=0; i--){
		if(result >> 31){
			/*the 31 bit is 1, if we shift 32 bits directly, the bit will disappear*/
			for(j=0; j<32; j++){
				result = result << 1;
				result = result % n;
			}
			result += tmp[i];	
		} else {
			result = result << 32;
			result = result | tmp[i];
		}
		result = result % n;
	}
	return result;
}

long long squareMod(long long a, long long n){
	unsigned long long tmp[4], bitArray[2];
	unsigned long long carry;
	long long result;
	char i, j, pos;
	for(i=0; i<4; i++) tmp[i] = 0;
	bitArray[1] = a >> 32; /*msb*/
	bitArray[0] = (unsigned long long)a & 0xffffffffUL; /*lsb*/
	
	for(i=0; i<2; i++){
		carry = 0;
		for(j=0; j<2; j++){
			pos = i + j;
			tmp[pos] += bitArray[i]*bitArray[j] + carry;
			carry = tmp[pos] >> 32;
			tmp[pos] = tmp[pos] & 0xffffffffUL;
		}
		if(carry > 0){
			tmp[pos + 1] += carry; 
		}
	}
	#if 0
	for(i=3; i>=0; i--){
		printf("%llx ", tmp[i]);
	}
	#endif
	result = 0;
	for(i=3; i>=0; i--){
		if(result >> 31){
			/*the 31 bit is 1, if we shift 32 bits directly, the bit will disappear*/
			
			for(j=0; j<32; j++){
				result = result << 1;
				if(result > n){
					result = result % n;
				}
			}
			result += tmp[i];	
		} else {
			result = result << 32;
			result = result | tmp[i];
		}
		result = result % n;
	}
	return result;
}

long long powMod(long long a, long long m, long long n){
	/*return a^m % n*/
	long long d1;
	if (1 == m) return (a % n);
	d1 = powMod(a, m >> 1, n);
	d1 = squareMod(d1, n);
	return (m & 1)? multiplyMod(d1, a, n) : d1;  		
}

void buildPrimeTable(){
	int i, j;
	char isPrime[SMALL_PRIME_BOUND]; /*look for small primes < 1000*/
	memset(isPrime, PRIME, SMALL_PRIME_BOUND);
	nPrime = 0;
	for(i=2; i<SMALL_PRIME_BOUND; i++){
		if(isPrime[i] == PRIME){
			prime[nPrime++] = i;
			j = i << 1;
			while(j < SMALL_PRIME_BOUND){
				isPrime[j] = COMPOSITE;
				j += i;
			} 
		}
	}
}

int MRTest(long long n, long long witness){
	long long k=0, m, i;
	long long residue;
	assert(n & 1);
	/*rewrite n - 1 = 2^k * m*/
	
	m = n - 1;
	k = 0;
	while(!(m & 1)){
		k += 1;
		m = m >> 1;
	}
	/*
		b0 = a^m % n
		if b0 is 1 or n - 1, then n is probably prime;
	*/
	residue = powMod(witness, m, n);
	if((residue == 1) || (residue == n - 1)) return PRIME;
	
	/*
		b[i] = b[i-1]^2 % n, where 1 <= i <= k-2
		if b[i] is 1, then n is composite
		if b[i] is n - 1, then n is probably prime
	*/
	for(i=k-2; i>=0; i--){
		residue = squareMod(residue, n);
		if(residue == 1){
			return COMPOSITE;
		} else if (residue == n - 1){
			return PRIME;
		}
	}
	/*
		b[k-1] = b[k-2]^2 % n
		if b[k-1] != n-1, then n is composite
	*/
	residue = squareMod(residue, n);
	if(residue != n - 1){
		return COMPOSITE;
	} else {
		return PRIME;
	}
}

int isProbablePrime(long long n){
	int i, verdict = PRIME;
	if(n < prime[nPrime - 1]) return PRIME;
	assert(n & 1); /*n must be odd*/
	
	for(i=0; i<nPrime; i++){
		if(COMPOSITE == MRTest(n, prime[i])){
			return COMPOSITE;
		}
	}
	return PRIME;
}

long long getBigFactor(long long n, int step){
	unsigned long long x = 5, xprime = 2, k = 1, ell=1;
	unsigned long long divisor;
	
	while(1){
		divisor = gcd((x > xprime)? x - xprime : xprime - x, n);
		if(1 == divisor){
			k--;
			if(k == 0){
				xprime = x;
				ell = ell << 1;
				k = ell;
			}
			x = squareMod(x, n);
			x = (x + step) % n;
		} else if (n == divisor){
			return 1;
		} else {
			return divisor;
		}
	}
}

int getSmallFactor(long long n){
	int i;
	for(i=0; i<nPrime; i++){
		if(n % prime[i] == 0) return prime[i];
	}
	return 0;
}



int factoring(long long input, struct Term term[]){
	int nFactor = 0;
	int step, i;
	while(0 != (term[nFactor].factor = getSmallFactor(input))){
		term[nFactor].pow = 0;
		do{
			term[nFactor].pow += 1;
			input = input / term[nFactor].factor;
		} while(input % term[nFactor].factor == 0);
		nFactor++;
	}
	for(i=0; i < nCachedPrime; i++){
		if(input % cachedPrime[i] == 0){
			term[nFactor].factor = cachedPrime[i];
			term[nFactor].pow = 0;
			do{
				term[nFactor].pow += 1;
				input = input / term[nFactor].factor;
			} while(input % term[nFactor].factor == 0);
			nFactor++;
		}
	}
	while(isProbablePrime(input) == COMPOSITE){
		step = 1;
		do{
			term[nFactor].factor = getBigFactor(input, step);
			step++;
		} while(term[nFactor].factor == 1);
		cachedPrime[nCachedPrime++] = term[nFactor].factor;
		/*
		if(term[nFactor].factor == 1){
			printf("Pollard method failed for %lld, ret=%lld\n", input, term[nFactor].factor);
			break;
		}
		*/
		term[nFactor].pow = 0;
		do{
			term[nFactor].pow += 1;
			input = input / term[nFactor].factor;
		} while(input % term[nFactor].factor == 0);
		nFactor++;
	}
	if(input > 1){
		term[nFactor].factor = input;
		term[nFactor].pow = 1;
		nFactor++;
		cachedPrime[nCachedPrime++] = input;
	}
	return nFactor;
}

int main(){
	int i, nTest;
	long long input;
	FILE *fp;
	struct Term term[128];
	int nFactor;
	fp = (DEBUG)? fopen("in7.txt","r") : stdin;		
	buildPrimeTable();
	
	fscanf(fp, "%d", &nTest);
	while(nTest >= 1){
		nTest--;
		fscanf(fp, "%lld", &input);
		nFactor = factoring(input, term);
		printf("%lld =", input);
		qsort(term, nFactor, sizeof(struct Term), compareTerm);
		if(term[0].pow == 1){
			printf(" %lld", term[0].factor);
		} else {
			printf(" %lld^%hhd", term[0].factor, term[0].pow);
		}
		for(i=1; i<nFactor; i++){
			if(term[i].pow == 1){
				printf(" * %lld", term[i].factor);
			} else {
				printf(" * %lld^%hhd", term[i].factor, term[i].pow);
			}	
		}
		printf("\n");
	}
	
	/*free(cachedPrime);*/
	return 0;
}