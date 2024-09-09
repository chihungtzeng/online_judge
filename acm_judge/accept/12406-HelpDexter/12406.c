
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define LEN 18
#define SMALLEST 0
#define LARGEST 1
#define VERBOSE 0
#define DEBUG 0

int nextNum(char *next, char *cur, int nDigit){
    int i, carry, sum;
    memcpy(next, cur, nDigit);
    for(i=nDigit-1, carry=1; i>=0; i--){
        sum = cur[i] + carry;
        
        if(sum >= 3){
            carry = 1;
            next[i] = 1;
        }
        else{
            carry = 0;
            next[i] = sum;
            return EXIT_SUCCESS;
        }
        
    }    
    return EXIT_FAILURE;    
}

long long numArrayToLL(char num[LEN], int nDigit){
    int i;
    long long result = 0;
    for(i=0; i<nDigit; i++){
        result = (result << 3) + (result << 1) + num[i];
    }
    return result;
}



int solve(long long ans[2], int nDigit, int nPow){
    char buf[LEN], buf2[LEN];
    char *pCur, *pNext, *pTmp;
    long long candidate;
    long long res;
    int i;
    int nAns = 0;
    int done = 0;
    
    for(i=0;i<nDigit; i++){
        buf[i] = 1;
    }
    ans[SMALLEST] = 1000000000000000000LL;
    ans[LARGEST] = 0;
    res = 1LL << nPow;
    
    
    pCur = buf;
    pNext = buf2;
    
    while(!done) {
        
        candidate = numArrayToLL(pCur, nDigit);
        #if VERBOSE
        printf("%lld\n", candidate);
        #endif
        if(candidate % res == 0){
            if(candidate < ans[SMALLEST]) {
                ans[SMALLEST] = candidate;
                nAns++;
            }
            if(candidate > ans[SMALLEST]) {
                ans[LARGEST] = candidate;
                nAns++;
            }
        }
        
        if(EXIT_SUCCESS == nextNum(pNext, pCur, nDigit)){
            pTmp = pCur;
            pCur = pNext;
            pNext = pTmp;
        }
        else{
            done = 1;
        }
    }
    if((nAns ==2) && (ans[0] == ans[1])){
        nAns = 1;
    }
    else if (nAns > 2){
        nAns = 2;
    }
    
#if VERBOSE
    printf("res=%lld\n", res);
#endif
    
    return nAns;
}

int main(){
    int nTest, k=1;
    int nDigit, nPow, nAns;
    long long ans[2];
    FILE *fp = (DEBUG)? fopen("in4.txt", "r") : stdin;
    
    fscanf(fp, "%d", &nTest);
    
    while(nTest--){
        fscanf(fp, "%d %d", &nDigit, &nPow);
        nAns = solve(ans, nDigit, nPow);
        if(nAns == 1){
            printf("Case %d: %lld\n", k++, ans[0]);
        }
        else if (nAns == 2){
            printf("Case %d: %lld %lld\n", k++, ans[0], ans[1]);
        }
        else {
            printf("Case %d: impossible\n", k++);
        }
        
    }
    
    return 0;
}
