#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TRUE 1
#define FALSE 0
#define NEIGHBOR_LIMIT 8
#define MAX_NUM_NODE 10002



struct Node {
    short nNeighbor;
    short neighborLimit;
    short *neighbor;
    char isDown;
};

void freeNode(struct Node *pNode){
    free(pNode->neighbor);
}

void initNode(struct Node *pNode){
    
    pNode->neighborLimit = NEIGHBOR_LIMIT;
    pNode->neighbor = (short *) malloc(sizeof(short)*NEIGHBOR_LIMIT);
    pNode->isDown = FALSE;
    pNode->nNeighbor = 0;
}

void addNeighbor(struct Node *pNode, short neighbor){
    if(pNode->nNeighbor == pNode->neighborLimit){
        pNode->neighborLimit <<= 1;
        pNode->neighbor = (short *) realloc(pNode->neighbor, sizeof(pNode->neighbor[0])*pNode->neighborLimit);
    }
    pNode->neighbor[pNode->nNeighbor++] = neighbor;
}

int calcHowManyKnockDown(short nNode, struct Node *nodes, short startNode){
    short i;
    short *queue;
    short head, tail;
    
    short curNodeIdx, nbr;
    
    if((startNode <= 0) || (startNode > nNode) || (nodes[startNode].isDown == TRUE)){
        return 0;
    }
    
    
    queue = (short *) malloc(sizeof(short)*MAX_NUM_NODE);
    head = 0;
    tail = 1;
    queue[0] = startNode;
    
    while(head < tail){
        curNodeIdx = queue[head++];
        nodes[curNodeIdx].isDown = TRUE;
        
        for(i=0; i<nodes[curNodeIdx].nNeighbor; i++){
            nbr = nodes[curNodeIdx].neighbor[i];
            if(nodes[nbr].isDown == FALSE){
                queue[tail++] = nbr;
            }
        }
    }
    
    free(queue);
    return head;
}

int main(){
    struct Node *nodes;
    short nNode, nEdge, nAction;
    short nKnock;
    short nTest;
    short i, u, v;
    FILE *fp = stdin;
    
    nodes = (struct Node *) malloc(sizeof(struct Node)*MAX_NUM_NODE);
    fscanf(fp, "%hd", &nTest);
    while(nTest--){
        fscanf(fp, "%hd %hd %hd", &nNode, &nEdge, &nAction);
        
        for(i=1; i<=nNode; i++){
            initNode(&nodes[i]);
        }
 /*read edges*/       
        for(i=0; i<nEdge; i++){
            fscanf(fp, "%hd %hd", &u, &v);
            addNeighbor(&nodes[u], v);
        }
        #if 0
        for(i=1; i<=nNode; i++){
            printf("Node %hd: ", i);
            for(u=0; u<nodes[i].nNeighbor; u++){
                printf("%hd ", nodes[i].neighbor[u]);
            }
            printf("\n");
        }
        #endif
        
        /*read queries*/
        nKnock = 0;
        for(i=0; i<nAction; i++){
            fscanf(fp, "%hd", &u);
            nKnock += calcHowManyKnockDown(nNode, nodes, u);
        }
        #if 1 /*only this works, don't know why*/
        for(i=1, nKnock=0; i<=nNode; i++){
            if(nodes[i].isDown) {
                nKnock++;
            }
        }
        #endif
        printf("%hd\n", nKnock);
        
        /*free memory*/
        for(i=1; i<=nNode; i++){
            freeNode(&nodes[i]);
        }
        
    }
    free(nodes);
    
    
    return 0;
}
