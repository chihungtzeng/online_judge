#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 11
#define MAX_NUM_CELL 10000001


int calcFunc(int nCoef, int *coef, int nCell, int x){
    long long result = 0;
    long long xk = 1;
    int i;
    for(i=0; i<=nCoef; i++){
        result = (result + coef[i]*xk ) % nCell;
        xk = (xk * x) % nCell;
    }
    return (int)result;
}

int solve(int nCoef, int *coef, int nCell, int nForce){
    char *flag;
    int nDiff = 0;
    int i;
    int res;
    
    
    flag = (char *) malloc(sizeof(char)*nCell);
    memset(flag, 0, sizeof(char)*nCell);
    
    for(i=nForce; i>=0; i--){
        res = calcFunc(nCoef, coef, nCell, i);
        #if 0
        printf("res=%d\n", res);
        #endif
        if(flag[res] == 0){
            flag[res] = 1;
            nDiff++;
        }
    }

    free(flag);
    return nDiff;
    
}

int main(){
    int coef[MAX], nCoef;
    int nCell, nForce;
    int i;
    
    
    
    while(2 == scanf("%d %d", &nCell, &nForce)){
        if((nCell == 0) && (nForce == 0)){
            break;
        }
        nCell++;
        scanf("%d", &nCoef);
        for(i=0; i<=nCoef; i++){
            scanf("%d", &coef[i]);
        }
        printf("%d\n",solve(nCoef, coef, nCell, nForce));
    }
    
    
    return 0;
}
