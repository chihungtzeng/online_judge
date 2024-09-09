#include <stdio.h>
#include <search.h>
#include <stdlib.h>

#define DEBUG 0

int nNode, nInDegreeOne, bIsTree;


struct Node {
    int id;
    int inDegree;
};



int compareNode(const void *a, const void *b){
    struct Node *x, *y;
    x = (struct Node *)a;
    y = (struct Node *)b;
    return x->id - y->id;
}

struct Node *newNode(int id){
    struct Node *pNode;
    pNode = (struct Node *) malloc(sizeof(struct Node));
    pNode->id = id;
    pNode->inDegree = 0;
    return pNode;
}

void insertEdge(void **ppRoot, int id[2]){
    void *match;
    struct Node *pNode[2];
    int i;

#if DEBUG
    printf("insert edge %d %d\n", id[0], id[1]);
#endif
    for(i=0; i<2; i++){
        pNode[i] = newNode(id[i]);
        match = tsearch(pNode[i], ppRoot, compareNode);
        if(*(struct Node **)match != pNode[i]){
            free(pNode[i]);
            pNode[i] =*(struct Node **)match;
        }
        else{
            nNode++;
        }
    }
    pNode[1]->inDegree += 1;

}

void twalkAction(const void *rootp, const VISIT way, const int depth){
    if((way == leaf) || (way == postorder)){
        struct Node *pNode;
        pNode = *(struct Node **)rootp;
        if(pNode->inDegree == 1){
            nInDegreeOne++;
        }
        else if (pNode->inDegree > 1){
            bIsTree = 0;
        }
    }
}


int isTree(void *pRoot){
    
    twalk(pRoot, twalkAction);
    #if DEBUG
    printf("nIndegree=%d nNode=%d\n", nInDegreeOne, nNode);
    #endif
    if((nInDegreeOne == nNode - 1) && bIsTree) return 1;
    else return 0;
}

int main(){
	FILE *fp = (DEBUG)? fopen("in.txt", "r") : stdin;
    int id[2], i, k = 1;
    void *root;
    
    while(2 == fscanf(fp, "%d %d", &id[0], &id[1])){
        if((id[0] < 0) || (id[1] < 0)){
            break;
        }
        if((id[0] == 0) && (id[1] == 0)){
            printf("Case %d is a tree.\n", k++);
            continue;
        }
        
        root = NULL;
        nNode = 0;
        nInDegreeOne = 0;
        bIsTree = 1;
        
        insertEdge(&root, id);
        while(2 == fscanf(fp, "%d %d", &id[0], &id[1])){
            if((id[0] == 0) && (id[1] == 0)){
                break;
            }
            else {
                insertEdge(&root, id);
            }
        }
        if(isTree(root)){
            printf("Case %d is a tree.\n", k++);
        }
        else {
            printf("Case %d is not a tree.\n",k++);
        }
        tdestroy(root, free);
    }
    return 0;
}
