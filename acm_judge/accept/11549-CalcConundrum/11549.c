#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <search.h>

#define DEBUG 0

long long g_pow10[10];

int compareInt(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int *newInt(int n){
    int *pInt;
    pInt = (int *) malloc(sizeof(int));
    *pInt = n;
    return pInt;
}

int solve(int initNum, int nDigit){
    long long square;
    long long curNum = initNum;
    void *root = NULL, *match;
    int done = 0;    
    int *pInt;
    int max = initNum;

    pInt = newInt(initNum);
    tsearch(pInt, &root, compareInt);
    
    do {
        square = curNum * curNum;
        while(square >= g_pow10[nDigit]){
            square = square / 10;
        }
        
        curNum = square;
        if(max < curNum){
            max = curNum;
        }
        pInt = newInt((int)curNum);
        
        match = tsearch(pInt, &root, compareInt);
        if(*(int **)match != pInt){
            done = 1;
            free(pInt);
        }
    }
    while(!done);
    tdestroy(root, free);
        
    return max;
}

int main(){
    int nTest, i;
    int nDigit, initNum;
    FILE *fp = (DEBUG)? fopen("in.txt", "r") : stdin;
    g_pow10[0] = 1;
    for(i=1; i<10; i++){
        g_pow10[i] = (g_pow10[i-1] << 3) + (g_pow10[i-1] << 1);
        #if DEBUG
        printf("g_pow10[%d]=%lld\n", i, g_pow10[i]);
        #endif 
    }
    
    fscanf(fp,"%d", &nTest);
    while(nTest--){
        
        fscanf(fp,"%d %d", &nDigit, &initNum);
        printf("%d\n", solve(initNum, nDigit));
    }
    return 0;
}