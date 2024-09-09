#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 21

struct Word {
    char unsort[LEN];
    char sort[LEN];
    int length;
};

int compareChar(const void *a, const void *b){
    return *(char *)a - *(char *)b;
}

void solve(char query[LEN], int nWord, struct Word *word){
    int nMatch = 0;
    int i;
    char squery[LEN];
    printf("Anagrams for: %s\n", query);
    strcpy(squery, query);
    qsort(squery, strlen(squery), sizeof(char), compareChar);
    
    for(i=0; i<nWord; i++){
        if(!strcmp(squery, word[i].sort)){
            ++nMatch;
            printf("%3d) %s\n", nMatch, word[i].unsort);
        }
    }
    if(nMatch == 0){
        printf("No anagrams for: %s\n", query);
    }
}

int main(){
    int nTest, first=1;
    int i;
    char query[LEN];
    struct Word *word;
    int nWord;
    int done;
    
    word = (struct Word *) malloc(sizeof(struct Word)*1001);
    
    scanf("%d", &nTest);
    while(nTest--){
        if(first){
            first = 0;
        }
        else {
            printf("\n");
        }
        
        scanf("%d", &nWord);
        for(i=0; i<nWord; i++){
            scanf("%s", word[i].unsort);
            word[i].length = strlen(word[i].unsort);
            strcpy(word[i].sort, word[i].unsort);
            qsort(word[i].sort, word[i].length, sizeof(char), compareChar);
        }
        #if 0
        for (i=0; i<nWord; i++){
            printf("%s %s\n", word[i].unsort, word[i].sort);
        }
        #endif
        done = 0;
        while(!done){
            scanf("%s", query);
            if (!strcmp(query, "END")){
                done = 1;
                continue;
            }
            solve(query, nWord, word);
        }
        
    }
    
    free(word);
    return 0;
}
