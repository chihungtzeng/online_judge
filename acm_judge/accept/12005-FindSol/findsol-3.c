#include <stdio.h>
#include <stdlib.h>

#define MSB(x) ((x) >> 32)
#define LSB(x) ((MSB((x)) << 32) ^ (x))

#define DEBUG 1
#define COMPOSITE 1
#define PRIME 0

/*
return b^e % m
*/
long long powMod(long long b, long long e, long long m){
	long long result;
	if(e == 1) return b % m;
	result = powMod(b, e >> 1, m);
	result = (result * result) % m;
	if(e & 1){
		result = (result * b) % m;
	}
	return result;
}

int checkPrimalityByWitness(long long n, int w){
	long long j, y, q, tmp, k;
	char done;
	if(n < w) return PRIME;

	q = n - 1;
	k = 0;
	/* 
		n = 1 + 2^k * q 
	*/
	while(!(q & 1)){
		q >>= 1;
		++k; 
	}
	if(n != 1 + (1 << k)*q){
		puts("shit!");
	}	
	
	j = 0;
	y = powMod(w, q, n);
	while(1){
		if((j == 0) && (y == 1)) return PRIME;
		if(y == n - 1) return PRIME;
		if((j > 0) && (y == 1)) return COMPOSITE;
		++j;
		if(j < k){
			y = (y*y) % n;
		} else {
			return COMPOSITE;
		}
	} 
}

/*
return PRIME if n is prime
otherwise if n is composite
*/
int isPrime(long long n){
	int i, nWitness;
	int witness[] = {
		 2,  3, 5, 7, 11,
		13, 17, 19, 23, 29,
		31, 37, 41, 43, 53,
		59, 61, 67, 71, 73
	};
	nWitness = sizeof(witness)/sizeof(witness[0]);
	
	for(i=0; i<nWitness; ++i){
		if(n == witness[i]) return PRIME;
	}
	
	for(i=0; i<nWitness; ++i){
		if(witness[i] > n) continue;
		if(checkPrimalityByWitness(n, witness[i]) == COMPOSITE){
			return COMPOSITE;
		} 
	}
	
	return PRIME;
}

long long gcd(long long a, long long b){
	if(0 == b) return a;
	else return gcd(b, a % b);
}

/*return x^2 % n*/
long long squareMod(long long x, long long m){
	long long low, high, carry = 0;
	long long tmp;
	short i, j, k;
	long long buf[4];

	low = LSB(x);
	high = MSB(x);
	
	tmp = low * low;
	buf[0] = LSB(tmp);
	carry = MSB(tmp);
	
	tmp = 2*low*high + carry;
	buf[1] = LSB(tmp);
	carry = MSB(tmp);
	
	tmp = high*high + carry;
	buf[2] = LSB(tmp);
	buf[3] = MSB(tmp);
	tmp = buf[3];

	for(i=2; i>=0; --i){
		for(j=31; j>=0; --j){
			tmp = (tmp << 1);
			k = ((buf[i] >> j) & 1);
			tmp += k;
			tmp = tmp % m;
		}
	}
	return tmp;
}

/*
return a factor of n;
*/
long long Pollard(long long n){
	int i;
	long long x = 5, xx = 5, k = 1, ell = 1;
	long long c = 1;
	long long divisor;
	long long count = 10000;
	if(n == 1) return 1;
	 
	 
	 
	if(n % 2 == 0) return 2;
	if(isPrime(n) == PRIME) return 1;
	do {
		x = (squareMod(x, n) + c) % n;
		xx = (squareMod(xx, n) + c) % n;
		xx = (squareMod(xx, n) + c) % n;
		divisor = gcd(llabs(xx - x), n);
		/*printf("x=%lld, xx=%lld gcd=%lld, n = %lld\n", x, xx, divisor, n);*/
		--count;
	} while((divisor == 1) && (count > 0));
	return 1;
}

long long findAns(long long n){
	long long divisor, primeFactor;
	long long ans = 1, k;
	char done = 0;
	while(!done){
		primeFactor = Pollard(n);
		while(1 != (divisor = Pollard(primeFactor))){
			primeFactor = divisor;
		}
		if(1 == primeFactor) {
			done = 1;
		} else {
			k = 1;
			do{
				k += 1;
				n = n / primeFactor;
			} while(n % primeFactor == 0);
			ans = ans * k;
		}
		
	}
	if(n > 1){
		ans = ans << 1;
	}
	return ans;
}

int main(){
	long long n, ans;
	FILE *fp;
	fp = (DEBUG)? fopen("in2.txt", "r") : stdin;

#if 0
	n = 1234567890123;
	ans = 987654321232;
	printf("%lld^2 %% %lld = %lld\n", n, ans, squareMod(n, ans));
#endif

#if 1
	while(1 == fscanf(fp, "%lld", &n)){
		if(n == 0) break;
		if(n == 1) {
			printf("1 1\n");
			continue;
		}
		ans = findAns((n << 2) - 3);
		printf("%lld %lld\n", n, ans);
	}
#endif
	return 0;
}
