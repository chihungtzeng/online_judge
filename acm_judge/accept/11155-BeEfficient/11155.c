#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10001

int A, B, C, M, N;
int *sum, *res, *seq, *prefixSum;

void initSum(){
    int i;
    for(i=0; i<MAX; i++){
        sum[i] = (i * (i-1)) >> 1;
    }
}

int calcAns(){
    int i, j, ans;
    seq[0] = A;
    
    prefixSum[0] = A;
    for(i=1, j=0; i<N; j=i, i++){
        seq[i] = ((seq[j] * B + C) % M) + 1;
        prefixSum[i] = prefixSum[j] + seq[i];
    }
    memset(res, 0, sizeof(int)*M);
    for(i=0; i<N; i++){
        res[prefixSum[i]%M]++;
    }
    #if 0
    printf("seq:");
    for(i=0; i<N; i++){
        printf("%d ", seq[i]);
    }
    printf("\n");
    printf("pfx:");
    for(i=0; i<N; i++){
        printf("%d ", prefixSum[i]);
    }
    printf("\n");
    printf("res:");
    for(i=0; i<M; i++){
        printf("%d ", res[i]);
    }
    printf("\n");
    printf("sum:");
    for(i=0; i<M; i++){
        printf("%d ", sum[i]);
    }
    printf("\n");
    #endif
    ans = res[0];
    for(i=0; i<M; i++){
        ans += sum[res[i]];
    }
    return ans;
}



int main(){
    int k;
    sum = (int *)malloc(sizeof(int)*MAX);
    res = (int *)malloc(sizeof(int)*MAX);
    seq = (int *)malloc(sizeof(int)*MAX);
    prefixSum = (int *)malloc(sizeof(int)*MAX);
 
    initSum(); 
 
    scanf("%d", &k);
    k=1;
    while(5 == scanf("%d %d %d %d %d", &A, &B, &C, &M, &N)){
        printf("Case %d: %d\n", k++, calcAns());
    }
     
 
    free(sum);
    free(res);
    free(seq);  
    free(prefixSum); 
    return 0;
}