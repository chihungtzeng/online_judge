#include <stdio.h>
#include <search.h>
#include <stdlib.h>

#define DEBUG 0
#define INPUT_FILE "in2.txt"

int nNode, nRoot, bIsTree, nEdge, rootId;
#define BLACK 0
#define WHITE 1


struct Node {
    int id;
    int parent;
    int nChildren;
    int nChildrenLimit;
    int *children;
    int color;
};

void freeNode(void *pObj){
    struct Node *pNode = (struct Node *) pObj;
    free(pNode->children);
    free(pNode);
}

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
    pNode->parent = id;
    pNode->nChildren = 0;
    pNode->nChildrenLimit = 8;
    pNode->children = (int *) malloc(sizeof(int)*pNode->nChildrenLimit);
    pNode->color = WHITE;
    return pNode;
}

int insertEdge(void **ppRoot, int id[2]){
    void *match;
    struct Node *pNode[2];
    struct Node *parent, *child;
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
    parent = pNode[0];
    child = pNode[1];
    if(child->parent == child->id){
        child->parent = parent->id;
        
        if(parent->nChildren == parent->nChildrenLimit){
            parent->nChildrenLimit <<= 1;
            parent->children = (int *) realloc(parent->children, sizeof(int) * parent->nChildrenLimit);
                       
        }
        parent->children[parent->nChildren++] = child->id;
    }
    else {
        bIsTree = 0;
        #if DEBUG
        printf("node %d parent %d, new parent: %d\n", pNode[1]->id, pNode[1]->parent, id[0]);
        #endif
    }
    
    return 1;
}

void twalkAction(const void *rootp, const VISIT way, const int depth){
    if((way == leaf) || (way == postorder)){
        struct Node *pNode;
        pNode = *(struct Node **)rootp;
        if(pNode->parent == pNode->id){
            nRoot++;
            rootId = pNode->id;
            #if DEBUG
            printf("find root: %d\n", pNode->id);
            #endif
        }
    }
}


int isTree(void **ppRoot){
    struct Node *pNode, *pNodeTmp, queryNode;
    int *queue, head, tail;    
    int nBlack, queryId, targetId;
    void *match;
    int i;
    
    #if DEBUG
    printf("nNode=%d nEdge=%d, bIsTree=%d\n", nNode, nEdge, bIsTree);
    #endif
    if(!bIsTree) return 0;
    if(nEdge != nNode - 1) return 0;
    twalk(*ppRoot, twalkAction);
    
    if(nRoot != 1) return 0;
    
    queryNode.id = rootId;
    

    nBlack = 0;
    queue = (int *) malloc(sizeof(int)*(nNode + 1));
    head = 0;
    tail = 1;
    queue[0] = rootId;
    while(head < tail){
        queryId = queue[head++];
        queryNode.id = queryId;
        match = tfind(&queryNode, ppRoot, compareNode);
        if(!match){
            printf("cannot find node %d!!!\n", queryId);
        }
        else {
            pNode = *(struct Node **) match;
        }
        pNode->color = BLACK;
        nBlack++;
        for(i=pNode->nChildren - 1; i>=0; i--){
            targetId = pNode->children[i];
            queryNode.id = targetId;
            pNodeTmp = *(struct Node **)tfind(&queryNode, ppRoot, compareNode);
            if(pNodeTmp->color == WHITE){
                queue[tail++] = targetId;
            }
            else {
                return 0;
            }
        }
    }

    if(nBlack == nNode) return 1;
    else return 0;    
    
}

int main(){
	FILE *fp = (DEBUG)? fopen(INPUT_FILE, "r") : stdin;
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
        nRoot = 0;
        bIsTree = 1;
        nEdge = 0;
        
        nEdge += insertEdge(&root, id);
        while(2 == fscanf(fp, "%d %d", &id[0], &id[1])){
            if((id[0] == 0) && (id[1] == 0)){
                break;
            }
            else {
                nEdge += insertEdge(&root, id);
            }
        }
        if(isTree(&root)){
            printf("Case %d is a tree.\n", k++);
        }
        else {
            printf("Case %d is not a tree.\n",k++);
        }
        tdestroy(root, freeNode);
        #if DEBUG
        printf("\n");
        #endif
    }
    return 0;
}
