#include <stdio.h>
#include <string.h>
#define MAX 128

short max(short a, short b){
	if(a < b) return b;
	else return a;
}

int main(){
	short dp[MAX][MAX];
	short n, m, i, j, x, y;
	int tower1[MAX], tower2[MAX];
	short k=0;
	
	
	while(2 == scanf("%hd %hd",&m, &n)){
		if( (0 == n) && (0 == m)) return 0;
		memset(dp, 0, sizeof(short)*MAX*MAX);
		
		for(i=0; i<m; i++){
			scanf("%d", &tower1[i]);
		}
		for(i=0; i<n; i++){
			scanf("%d", &tower2[i]);
		}
		
		
		x=1;
		for(i=0; i<m; i++){
			y=1;
			for(j=0; j<n; j++){
				dp[x][y] = (tower1[i] == tower2[j])? dp[x-1][y-1] + 1 : max(dp[x][y-1], dp[x-1][y]);
				y++;
			}
			x++;
		}
		
		k++;
		printf("Twin Towers #%hd\n",k);
		printf("Number of Tiles : %hd\n\n",dp[m][n]);
	} 
	return 0;
}