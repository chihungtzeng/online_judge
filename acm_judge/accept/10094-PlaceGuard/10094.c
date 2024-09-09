/*AC 1.308s*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 1024
#define DEBUG 0

void easyCaseSol(short pos[], short nGuard){
	short i, cur = 1;
	for(i=2; i <= nGuard; i+=2){
		pos[cur++] = i;
	}
	for(i=1; i <= nGuard; i+=2){
		pos[cur++] = i;
	}
}

int checkAns(short pos[], short nGuard){
	short i, j;
	for(i=1; i<=nGuard; i++){
		for(j=i+1; j<=nGuard; j++){
			if(pos[i] == pos[j]) return EXIT_FAILURE;
			if( abs(pos[i] - pos[j]) == j - i) return EXIT_FAILURE; 
		}
	}
	return EXIT_SUCCESS;
}

int findAns(short pos[], short nGuard, short k){
	short i, cur = 1, tmp, start = 1, spot;
	short stop = k << 1;
	for(i = stop + 2; i <= nGuard; i+=2){
		pos[cur++] = i;
	}
	for(i = 2; i <= stop; i+=2){
		pos[cur++] = i;
	}
	
	tmp = cur;
	
	
	while(1){	
		for(i = start; cur <= nGuard; i += 2){
			
			if(i > nGuard) i = 1;
			
			pos[cur++] = i;
			  
		}
		
		if(checkAns(pos, nGuard) == EXIT_SUCCESS) return EXIT_SUCCESS;
				
		cur = tmp;
		start += 2;
		
		if(start > nGuard){
			
			return EXIT_FAILURE;
		}
	}  
}

int main(){
	short pos[MAX];
	short nGuard;
	short k; /* k = nGuard / 6*/
	short r; /*r = nGuard % 6*/
	int state;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in3.txt", "r") : stdin;
	
	while(1 == fscanf(fp, "%hd",&nGuard)){
		r = nGuard % 6;
		
		if ((r != 2) && (r != 3)){
			easyCaseSol(pos, nGuard);
			state = EXIT_SUCCESS;
		} 	
		else{
			k = (nGuard - r) / 6;
			state = findAns(pos, nGuard, k);
		}
		if(state == EXIT_SUCCESS){
			printf("%hd",pos[1]);
			for(k=2; k <= nGuard; k++){
				printf(" %hd", pos[k]);
			}
			printf("\n");
		}
		else{
			puts("Impossible");
		}
	}
	return 0;
}