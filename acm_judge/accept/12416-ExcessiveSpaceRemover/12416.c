#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LEN 1048576
#define DEBUG 0

int calcMove(int nSpace){
    int p, n;
    
    p = 0;
    n = 1;
    while(n < nSpace){
        n = n << 1;
        p++;
    }
    return p;
}

int solve(char *line){
    int nSpace = 0, i;
    int nSpaceMax = 0;
    int bPrevisouSpace = 1;
    char *ptr, ch;
    int ans;
    int done = 0;
 
 
    
    for(i=0; (i<LEN) && !done; i++){
        ch = line[i];
        if((ch == ' ') && bPrevisouSpace){
            nSpace++;
        } 
        else if ((ch == ' ') && !bPrevisouSpace){
            nSpace = 1;
            bPrevisouSpace = 1;
        } 
        else if (isgraph(ch) && bPrevisouSpace){
            if(nSpaceMax < nSpace){
                nSpaceMax = nSpace;
            }
            bPrevisouSpace = 0;
            nSpace = 0;
            
        }
        /*
        else if ((*ptr != ' ') && !bPrevisouSpace){
            
        }
        */
        if(ch == '\0'){
            done = 1;
        }
    }    
    assert(bPrevisouSpace == 0);
    
    #if DEBUG
    printf("max length of consecutive space:%d\n",nSpaceMax);
    #endif
    return calcMove(nSpaceMax);
}

int main(){
    char *line;
    FILE *fp = (DEBUG)? fopen("in.txt", "r") : stdin;
    int ans;
    line = (char *) malloc(LEN);    

    while(NULL != fgets(line, LEN, fp)){
        ans = solve(line);
        printf("%d\n", ans);
    }    
    
    free(line);
    return 0;
}