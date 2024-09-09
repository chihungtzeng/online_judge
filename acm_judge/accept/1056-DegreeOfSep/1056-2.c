#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

#define DEBUG 0
#define INF 127
#define MAX_NUM_PEOPLE 51
#define LEN 128



int solve(int nPeople, char **dist){
	char ans = 0;
	int i, j, k;
	
	
	for(k=0; k<nPeople; k++){
		for(i=0; i<nPeople; i++){
			for(j=0; j<nPeople; j++){
				dist[i][j] = (dist[i][k] + dist[k][j] < dist[i][j])? 
				 	dist[i][k] + dist[k][j] : dist[i][j];
			}
		}
		/*
		for(i=0; i<nPeople; i++){
			memcpy(dist[i], newDist[i], nPeople);
		}
		*/
	}
	for(i=1; i<nPeople; i++){	
		for(j=0; j<i; j++){
			if(dist[i][j] == INF) {
				return INF;
			}
			if(dist[i][j] > ans){
				ans = dist[i][j];
			}
		}
	}

	return (int) ans;
}

int main(int argc, char *argv[]){
	int nPeople, nEdge;
	char *name[2];
	ENTRY *entry, *match, tmpEntry;
	int nEntry, ans;
	int id[2];
	int k=1;
	int i, j;
	char **dist;
	FILE *fp;
	
	
	
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	for(j=0; j<2; j++){
		name[j] = (char *) malloc(LEN);
	}
	
	dist = (char **) malloc(sizeof(char *) * MAX_NUM_PEOPLE);
	
	
	entry = (ENTRY *) malloc(sizeof(ENTRY) * MAX_NUM_PEOPLE);
	for(i=0; i<MAX_NUM_PEOPLE; i++){
		entry[i].key = (char *) malloc(LEN);
	}
		
	for(i=0; i<MAX_NUM_PEOPLE; i++){
		dist[i] = (char *) malloc(MAX_NUM_PEOPLE);	
	}
	
	while(2 == fscanf(fp, "%d %d", &nPeople, &nEdge)){
		if(0 == nPeople) {
			break;
		}
		
		nEntry = 0;
		hcreate(256);
		

		for(i=0; i<nPeople; i++){
			memset(dist[i], INF, nPeople);
			dist[i][i] = 0;
		}		
		
		for(i=0; i<nEdge; i++){
			fscanf(fp, "%s %s", name[0], name[1]);
			for(j=0; j<2; j++){
				tmpEntry.key = name[j];
				match = hsearch(tmpEntry, FIND);
				if(!match){
					/*new name*/
					entry[nEntry].data = (void *) nEntry;
					strcpy(entry[nEntry].key, name[j]);
					hsearch(entry[nEntry], ENTER);
					id[j] = nEntry;
					nEntry++;
				} else {
					id[j] = (size_t) match->data;
				}
				#if DEBUG
				printf("id of %10s -> %d\n", name[j], id[j]);
				#endif
			}
			
			dist[id[0]][id[1]] = 1;
			dist[id[1]][id[0]] = 1;
			
		}
		
		ans = (nEntry == nPeople)? solve(nPeople, dist) : INF;
		if(ans == INF){
			printf("Network %d: DISCONNECTED\n\n", k++);
		} else {
			printf("Network %d: %d\n\n", k++, ans);
		}
		
		
		hdestroy();
	}

	for(j=0; j<2; j++){
		free(name[j]);
	}	
	for(i=0; i<MAX_NUM_PEOPLE; i++){
		free(dist[i]);
		
	}
	free(dist);
	
	free(entry);
	
	return 0;
}