#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 44722
#define MAX_NUM_FACTOR 32
#define VERBOSE 0

int nPrime;
int *prime;
int *primeSquare;

struct PrimeFactor {
    int factor;
    int pow;
};

int compareInt(const void *a, const void *b){
    int x, y;
    x = *(int *)a;
    y = *(int *)b;
    if(x < y) return -1;
    else if (x == y) return 0;
    else return 1;
}

int findAllPrimeFactors(struct PrimeFactor pPrimeFactor[MAX_NUM_FACTOR], int n){
    int i, k, p;
    int nPrimeFactor = 0;
    
    for(i=0; (i<nPrime) && (primeSquare[i] <= n); i++){
        p = prime[i];
        if (n % p != 0){
            continue;
        }
        pPrimeFactor[nPrimeFactor].factor = p;
        k = 0;
        while(n % p == 0){
            k++;
            n = n / p;
        }
        pPrimeFactor[nPrimeFactor++].pow = k;      
    }

    if(n > 1){
        pPrimeFactor[nPrimeFactor].factor = n;
        pPrimeFactor[nPrimeFactor++].pow = 1;
    }    
    
    return nPrimeFactor;
}


void calcAllDivisors(int *divisors, int nPrimeFactor, struct PrimeFactor pPrimeFactor[], int curPrimeFactorIdx, int curDivisorIdx){
    int i, j, t;
    int p, nCopy, idx;
    int destIdx;

    if(curPrimeFactorIdx >= nPrimeFactor) return;
        
    p = pPrimeFactor[curPrimeFactorIdx].factor;
    nCopy = pPrimeFactor[curPrimeFactorIdx].pow;
    if(curPrimeFactorIdx == 0){               
        for(i=0, t=1; i<=nCopy; i++, t *= p){
            divisors[i] = t;
        }
        calcAllDivisors(divisors, nPrimeFactor, pPrimeFactor, 1, nCopy + 1);
    }    
    else{
        destIdx = curDivisorIdx;
        for(i=1; i<=nCopy; i++){
            memcpy(divisors + destIdx, divisors, sizeof(divisors[0])*curDivisorIdx);
            destIdx += curDivisorIdx;
        }
        t = p;        
        idx = curDivisorIdx;
        for(i=0; i<nCopy; i++){
            for(j=0; j<curDivisorIdx; j++){
                divisors[idx++] *= t;
            }
            t = t * p;
        }
        calcAllDivisors(divisors, nPrimeFactor, pPrimeFactor, curPrimeFactorIdx + 1, destIdx);
    }
}

int getAllDivisors(int *divisors, int n){
    int nDivisor = 1;
    int nPrimeFactor;
    int i, t;
    struct PrimeFactor pPrimeFactor[MAX_NUM_FACTOR];
    
    nPrimeFactor = findAllPrimeFactors(pPrimeFactor, n);

    for(i=0; i<nPrimeFactor; i++){
        nDivisor *= (pPrimeFactor[i].pow + 1);
    }  

    
    
    calcAllDivisors(divisors, nPrimeFactor, pPrimeFactor, 0, 0);
    qsort(divisors, nDivisor, sizeof(int), compareInt);
    
    #if VERBOSE
    for(i=0; i<nDivisor; i++){
        printf("%d ", divisors[i]);
    }
    printf("\n");
    
      
    printf("#divisor=%d\n", nDivisor);
    #endif
    
    return nDivisor;
}

void buildPrimeTable(){
    char cprime[MAX];
    int i, t;    
    memset(cprime, 1, MAX);
    for(i=2; i<MAX; i++){
        if(cprime[i]){
            for(t=i+i; t<MAX; t+=i){
                cprime[t] = 0;
            }
        }
    }
    nPrime = 0;
    prime = (int *) malloc(sizeof(int)*MAX);
    for(i=2;i<MAX; i++){
        if(cprime[i]){
            prime[nPrime++] = i;
        }
    }
    prime = (int *) realloc(prime, sizeof(int)*nPrime);
    primeSquare = (int *) malloc(sizeof(int)*nPrime);
    for(i=0; i<nPrime; i++){
        primeSquare[i] = prime[i] * prime[i];
    }
    
    #if VERBOSE
    for(i=0; i<100; i++){
        printf("%d ", prime[i]);
    }
    
    printf("\n %d primes\n", nPrime);
    #endif
}

int solve(int *start, int *end, int sum){
    int *divisors;;
    int nDivisor;
    int i;
    int s, t, q, dsum, tmp;
    int ell;
    dsum = sum << 1;
 
    divisors = (int *) malloc(sizeof(int)*1024);
    nDivisor = getAllDivisors(divisors, dsum);

    

    for(i=nDivisor -2; i>=0; i--){
        
        ell = divisors[i];

        q = dsum / ell;
        #if VERBOSE
        printf("testing dsum=%d, ell = %d, q=%d\n",dsum, ell, q);
        #endif
        tmp = q + 1 - ell;
        if (tmp <= 0){
            continue;
        }
        if( !(tmp & 1) ){
            s = tmp >> 1;
            t = s + ell - 1;
            break;
        }
    }
    *start = s;
    *end = t;
    #if VERBOSE
    printf("s=%d t=%d\n", s, t);
    #endif
    
    if(divisors != NULL){
        free(divisors);
    }
}

int main(){
    int start, end, sum;
    buildPrimeTable();

    while(1 == scanf("%d", &sum)){
        if (sum <= 0) break;
        solve(&start, &end, sum);
        printf("%d = %d + ... + %d\n", sum, start, end);    
    }    
    
    
    free(prime);
    free(primeSquare);
    return 0;
}
