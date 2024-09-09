#include <stdio.h>
#include <stdlib.h>
#define MAX 201

int main(){
	short *degree;
	short n, R, i, u, v;
	char possible;	
	degree = (short *) malloc(sizeof(short)*MAX);
	
	
	while( 2 == scanf("%hd %hd", &n, &R)){
		for(i=0; i<n; i++) {
			degree[i] = 0;
		}
		
		for(i=0; i<R; i++){
			scanf("%hd %hd", &u, &v);
			degree[u]++;
			degree[v]++;
		}
		
		possible = 1;
		for(i=0; (i<n) && possible; i++){
			if(degree[i] & 1) possible = 0;
			if(degree[i] == 0) possible = 0;
		}		
		if(possible){
			puts("Possible");
		} else {
			puts("Not Possible");
		}
	}
	

	return 0;
}