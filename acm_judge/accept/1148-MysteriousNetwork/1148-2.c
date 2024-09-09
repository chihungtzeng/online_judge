/*RE*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100001
#define MAX_FREIND_NUM 101
#define WHITE 0
#define BLACK 1

struct Person {
	int nFriend;
	int friend[MAX_FREIND_NUM];
};

int BFS(int nPeople, struct Person *person, int src, int dest){
	int *queue, *dist;
	int head, tail;
	int curPerson, friend, i;
	int done = 0;
	char *visit;
	if ( src == dest ) return 0;
	
	queue = (int *) malloc(sizeof(int)*nPeople);
	dist = (int *) malloc(sizeof(int)*nPeople);
	visit = (char *) malloc(sizeof(char)*nPeople);
	memset(dist, 0x7f, sizeof(int)*nPeople);
	memset(visit, WHITE, sizeof(char)*nPeople);
	
	
	head = 0;
	tail = 1;
	queue[0] = src;
	dist[src] = 0; 	
	visit[src] = BLACK;

	while((head < tail) && (!done)){
		curPerson = queue[head++];
		for(i=person[curPerson].nFriend - 1; (i >= 0) && (!done); i--){
			friend = person[curPerson].friend[i];
			if(visit[friend] == WHITE){
				visit[friend] = BLACK;
				dist[friend] = dist[curPerson] + 1;
				queue[tail++] = friend;
			}
		}		
	}	
	
	free(queue);
	free(dist);
	free(visit);
	return dist[dest] - 1;
}

int main(){
	struct Person *person;
	int nPeople;
	int id, i, j, src, dest;
	int nTest;
	FILE *fp = stdin;	
	int first = 1;

			
	person = (struct Person *) malloc( sizeof(struct Person) * MAX);
	fscanf(fp, "%d", &nTest);
	while(nTest--){
		fscanf(fp, "%d", &nPeople);
		
		for(i=nPeople - 1; i>=0; i--){
			fscanf(fp, "%d", &id);
			fscanf(fp, "%d", &person[id].nFriend);
			for(j=person[id].nFriend - 1; j >= 0; j--){
				fscanf(fp, "%d", &(person[id].friend[j]));
			}
		}
		fscanf(fp, "%d %d", &src, &dest);
		if(first){
			first = 0;
		} else {
			printf("\n");
		} 
		printf("%d %d %d\n", src, dest, BFS(nPeople, person, src, dest));
	
	}
	free(person);	
	
	return 0;
}