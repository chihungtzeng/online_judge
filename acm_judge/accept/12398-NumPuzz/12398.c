#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 255


struct Neighborhood {
	int nNeighbor;
	int x, y;
	int neighbor[10];
};

int validPos(int x){
	if((x >=0 )&& (x < 3)) return 1;
	else return 0; 
}


void initNeighborhood(struct Neighborhood neighborhood[9]){
	int i, j, xoffset, yoffset, newX, newY;
	for(i=0; i<9; i++){
		neighborhood[i].x = i/3;
		neighborhood[i].y = i % 3;
		neighborhood[i].neighbor[0] = i;
		neighborhood[i].nNeighbor = 1;
	}
	for(i=0; i<9; i++){
		for(xoffset=-1; xoffset <= 1; xoffset++){
			for(yoffset=-1; yoffset<=1; yoffset++){
				if(abs(xoffset) + abs(yoffset) != 1){
					continue;
				}
				newX = neighborhood[i].x + xoffset;
				newY = neighborhood[i].y + yoffset;
				if (validPos(newX) && validPos(newY)){
			
					neighborhood[i].neighbor[neighborhood[i].nNeighbor] = newX + newX + newX + newY;
					
					neighborhood[i].nNeighbor += 1;
				}  
			}
		}
	}
	#if 0
	for(i=0; i<9; i++){
		printf("%c: #neighbor=%d ", i + 'a', neighborhood[i].nNeighbor);
		for(j=0; j<neighborhood[i].nNeighbor; j++){
			printf("%c, ", neighborhood[i].neighbor[j] + 'a');
		}
		printf("\n");
	}
	#endif
}

int main(){
	int i, j, p, q, nbr;
	struct Neighborhood neighborhood[9];
	char line[LEN];
	int count[256];
	int ans[9];
	char *ptr;
	int k = 1;
	initNeighborhood(neighborhood);

	while(NULL != fgets(line, LEN, stdin)){
		for(i='a'; i<='i'; i++){
			count[i] = 0;
		}
		
		
		ptr = line;
		while( ('a' <= *ptr) && (*ptr <= 'i')){
			count[*ptr] += 1;
			ptr++;
		}
		for(i='a'; i<='i'; i++){
			count[i-'a'] = count[i];
		}
		for(i=0; i<9; i++){
			ans[i] = 0;
			for(j=0; j<neighborhood[i].nNeighbor; j++){
				nbr = neighborhood[i].neighbor[j];
				ans[i] += count[nbr];
			}
		}
		printf("Case #%d:\n", k++);
		for(i=0; i<3; i++){
			printf("%d", ans[i+i+i] % 10);
			for(j=1; j<3; j++){
				p = i+i+i + j;
				printf(" %d", ans[p] % 10);
			}
			printf("\n");
		}
	}
	
	return 0;
}