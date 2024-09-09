#include <stdio.h>
#include <string.h>
#define LEN 105


int main(){
	FILE *fp = stdin;
	char grid[LEN][LEN];
	char output[LEN];
	int r, c, x, y, maxC, len, allBlank;
	for(r=0; r<LEN; r++){
		for(c=0; c<LEN; c++){
			grid[r][c] = '\0';
		}
	}
	r=0;
	maxC=0;
	while(NULL != fgets(grid[r], LEN, fp)){		
		len = strlen(grid[r]);
		if(len> maxC) {
			maxC = len;
		}
		grid[r][len - 1] = '\0';
		r++;
	}
	#if 0
	for(x=0; x < r; x++){
		y=0;
		while(grid[x][y] != '\n'){
			printf("%c", grid[x][y]);
			y++;
		}
		printf("\n");
	}
	#endif
	
	#if 1
	/*
	for(c=0; c<maxC; c++){
		y=0;
		while((y<r) && isspace(grid[y][c])){
			grid[y][c] = '\0';
			y++;
		}
	}
	*/
	len = r - 1;
	maxC--;
	for(x=0; x<maxC; x++){
		output[r] = '\0';
		for(y=len; (y>=0); y--){
			if(isprint(grid[y][x])){
				output[len - y] = grid[y][x];
				
			} else{
				output[len - y] = ' ';
			}			
		}
		
		puts(output);
		
	}
	#endif
	return 0;
}