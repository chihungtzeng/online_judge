
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10001
#define LEN 11


int calcYuan(int st, char name[LEN]){
    int len = 0;
    char buf[64], buf2[64], *pFrom, *pTo, *pTmp;
    int i, j, n;
    int yuan;
    int translation;
    
    for(i=0; name[i] != '\0'; i++){
        translation = name[i] - 'A' + st;
        n = sprintf(buf2, "%d", translation);
        for(j=0; j<n; j++){
            buf[len++] = buf2[j] - '0';
        }
    }

    pFrom = buf;
    pTo = buf2;

    while(len > 3){
        for(i=len - 1; i >=0; i--){
            pTo[i] = (pFrom[i] + pFrom[i+1]) % 10;
        }
        pFrom[len] = '\0';
        len--;
        pTmp = pFrom;
        pFrom = pTo;
        pTo = pTmp;
    }
    yuan = 0;    
    for(i=0; i<3; i++){
        yuan = yuan * 10 + pFrom[i];
    }
    if(yuan == 100) return EXIT_SUCCESS;
    else return EXIT_FAILURE;
    
        
}

void solve(char name[LEN]){
    int st;
    int yuan;
    for(st=1; st<MAX; st++){
        yuan = calcYuan(st, name);
        if(yuan == EXIT_SUCCESS){
            printf("%d\n", st);
            return;
        }
    }
    printf(":(\n");
}

int main(){
    
    char name[LEN];
    
    /*calcYuan(81, "JYFTYR");*/
    
    while(1 == scanf("%s", name)){
        solve(name);
    }
    
    return 0;
}