#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 100002

int calcAntiRhyme(char *s, char *t){
    int r=0;
    while((*s != '\0') && (*t != '\0') && (*s == *t)){
        r++;
        s++;
        t++;
    }
    return r;
}

int check(int s, int nString){
    if((s < 1) || (s > nString)){
        printf("damn");
    }
    return 0;
}

int main(){
    int nTest, k=1, nString, nQuery;
    int i, s, t, lineLength;
    char **sSet;
    char *line;
    
    line = (char *) malloc(LEN);
    sSet = (char **) malloc(sizeof(char *)*LEN);
    scanf("%d", &nTest);
    while(nTest--){
        scanf("%d", &nString);
        for(i=1; i<=nString; i++){
            scanf("%s", line);
            lineLength = strlen(line);
            sSet[i] = (char *) malloc(lineLength + 1);
            
            strcpy(sSet[i], line);
        }
        #if 0
        for(i=1; i<=nString; i++){
            printf("string %d: %s\n", i, sSet[i]);
        }
        #endif
        
        scanf("%d", &nQuery);
        printf("Case %d:\n", k++);
        for(i=nQuery; i > 0; i--){
            scanf("%d %d", &s, &t);
            
            printf("%d\n", calcAntiRhyme(sSet[s], sSet[t]));
        }
        
        for(i=1; i<=nString; i++){
            if(sSet[i] != NULL){
                free(sSet[i]);
            }
        }
    }
    free(line);
    free(sSet);
    
    return 0;
}
