#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

#define NUM_COURSE 5
#define DEBUG 0

int mostPopular;
int nConformity;

struct Combination{
    int course[NUM_COURSE];
    int nPopularity;
};

void printCombination(struct Combination *pComb){
    int i;
    for(i=0; i<NUM_COURSE; i++){
        printf("%d ", pComb->course[i]);
    }
    printf("\n");
}

struct Combination *newCombination(int courses[NUM_COURSE]){
    struct Combination *pObj;
    int i;
    pObj = (struct Combination *) malloc(sizeof(struct Combination));
    pObj->nPopularity = 1;
    for(i=0; i<NUM_COURSE; i++){
        pObj->course[i] = courses[i];
    }
    return pObj;
}

int compareInt(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int compareCombination(const void *a, const void *b){
    struct Combination *x, *y;
    int i;
    x = (struct Combination *)a;
    y = (struct Combination *)b;
    for(i=0; i< NUM_COURSE; i++){
        if(x->course[i] < y->course[i]){
            return -1;
        } else if (x->course[i] > y->course[i]){
            return 1;
        }
    }
    return 0;
}

void twalkAction(const void *rootp, const VISIT way, const int depth){
    if((way == leaf) || (way == postorder)){
        struct Combination *pComb;
        pComb = *(struct Combination **)rootp;
        if(pComb->nPopularity == mostPopular){
            nConformity += pComb->nPopularity;
        }
    }
}

int main(){
    int nStudent;
    
    int i, j;
    
    int courses[NUM_COURSE];
    void *root, *match;
    FILE *fp = (DEBUG)? fopen("in.txt","r"):stdin; 
    struct Combination *pComb;   
    
    while(1 == fscanf(fp, "%d", &nStudent)){
        
        if(0 == nStudent){
            break;
        }
        
        root = NULL;
        
        mostPopular = 1;
        nConformity = 0;
        for(i=0; i<nStudent; i++){
            for(j=0; j<NUM_COURSE; j++){
                fscanf(fp, "%d", courses+j);
            }
            qsort(courses, NUM_COURSE, sizeof(int), compareInt);
            pComb = newCombination(courses);
            #if DEBUG
            printCombination(pComb);
            #endif
            match = tsearch(pComb, &root, compareCombination);
            if(*(struct Combination **)match != pComb){
                
                free(pComb);
                pComb = *(struct Combination **)match;
                pComb->nPopularity += 1;
                if(pComb->nPopularity > mostPopular){
                    mostPopular = pComb->nPopularity;
                }
            }       
        }
        twalk(root, twalkAction);
        tdestroy(root, free);
        printf("%d\n", nConformity);
    }
    return 0;
}