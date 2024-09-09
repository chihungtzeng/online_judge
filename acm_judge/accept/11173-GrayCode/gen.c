#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define BIT 29

int main(){
    int n;
    int i;
    int k;
    int range;
    printf("%d\n", MAX);
    srand(time(NULL));
    for(i=0; i<MAX; i++){
        n = 1 + rand() % BIT;
        range = 1 << n;
        k = rand() % range;
        printf("%d %d\n", n, k);
    }
}
