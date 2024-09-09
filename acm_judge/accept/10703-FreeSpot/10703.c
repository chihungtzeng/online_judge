#include <stdio.h>
#include <string.h>
#define MAX 512

void swap(short *x, short *y){
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

int main(){
	
	short i, j, k, x1,x2, y1, y2;
	int count, W, H, N;
	char map[MAX][MAX];
	while(3 == scanf("%d %d %d",&W, &H, &N)){
		if((0 == W) && (0 == H) && (0 == N)) break;
		
		memset(map, 0, MAX*MAX);
		for(i=0; i<N; i++){
			scanf("%hd %hd %hd %hd",&x1, &y1, &x2, &y2);
			if(x1 > x2) swap(&x1, &x2);
			if(y1 > y2) swap(&y1, &y2);
			for(j=x1; j<=x2; j++){
				for(k=y1; k<=y2; k++){
					map[j][k] = 1;
				}
			}
		}
		count = 0;
		for(i=1; i<=W; i++){
			for(j=1; j<=H; j++){
				count += map[i][j];
			}
		}
		count = W*H - count;
		
		if(count == 0){
			puts("There is no empty spots.");
		}
		else if(count == 1){
			puts("There is one empty spot.");
		}
		else{
			printf("There are %d empty spots.\n",count);
		}
	}
	return 0;
}