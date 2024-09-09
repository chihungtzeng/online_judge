#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 64

long long binToLL(char *s){
    long long result = 0;
    while(*s != '\0'){
        result = (result << 1) + *s - '0';
        s++;
    }
    return result;
}

int LLToBin(char *output, long long input){
    int len = 0, i, j;
    while(input > 0){
        output[len++] = (input & 1) + '0';
        input = input >> 1;
    }
    output[len] = 0;
    for(i=0, j=len-1; i<j; i++, j--){
        output[i] = output[i] ^ output[j];
        output[j] = output[i] ^ output[j];
        output[i] = output[i] ^ output[j];
    }
    return len;
}

void solve(char a[LEN], char b[LEN]){
    long long z;
    int x, y;
    char sz[LEN], allZero[LEN];
    int szLen;
    int aLen, bLen;
    int upBarLen;
    int identLen;
    
    aLen = strlen(a);
    bLen = strlen(b);
    upBarLen = (aLen > bLen)? aLen : bLen;
    
    z = binToLL(a) * binToLL(b);
    szLen = LLToBin(sz, z);
    
    for(x=0; x<aLen; x++){
        allZero[x]='0';
    }
    allZero[aLen]='\0';
    #if 0
    printf("%lld -> %s\n", z, sz);
    #endif
    printf("%*s\n", szLen, a);
    printf("%*s\n", szLen, b);
    /*(szLen - upBarLen) spaces followed by upBarLen '-'*/
    for(x=szLen - upBarLen; x > 0; x--){
        printf(" ");
    }
    for(x=upBarLen; x > 0; x--){
        printf("-");
    }
    printf("\n");
    /*To be done*/
    for(x=0, y=bLen-1; x<bLen; x++, y--){
        if(b[y] == '1'){
            printf("%*s\n", szLen - x, a);
        }
        else {
            printf("%*s\n", szLen - x, allZero);
        }
    }
    
    /*final result*/
    for(x=szLen; x>0; x--){
        printf("-");
    }
    printf("\n");
    printf("%s\n", sz);
    printf("\n");
}

int main(){
    char a[LEN], b[LEN];
    /*int first = 1;
                if(first){
                first = 0;
            } 
            else{
                printf("\n");
            }

    */
    while(2 == scanf("%s %s", a, b)){
        if( (a[0] == '0') && (b[0] == '0')){
            break;
        }
        else {
            solve(a, b);
        }
    }
    return 0;
}
