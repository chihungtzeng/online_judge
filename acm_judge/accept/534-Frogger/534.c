#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 210
#define INF 1000000000

struct Point {
	short x, y;
};

double findAns(short nStone, struct Point stone[]){
	double dist[MAX][MAX];
	double best[MAX], sPath;
	char color[MAX];
	int queue[50000];
	int src, target;
	int head, tail;
	int i,j;
	memset(color, 0, sizeof(char)*MAX);
	
	for(i=0; i<nStone; i++){
		for(j=i+1; j<nStone; j++){
			dist[i][j] = (stone[i].x - stone[j].x)*(stone[i].x - stone[j].x) + (stone[i].y - stone[j].y)*(stone[i].y - stone[j].y);
			dist[j][i] = dist[i][j];
		}
		best[i] = INF;
	}
	color[0] = 1;
	queue[0] = 0;
	best[0] = 0;
	head = 0;
	tail = 1;
	while(head < tail){
		src = queue[head++];
		color[src] = 0;
		for(target = 0; target < nStone; target++){
			if(target == src) continue;
			sPath = (dist[src][target] > best[src])? dist[src][target] : best[src]; 
			
			if(best[target] > sPath){
				best[target] = sPath;
				if(color[target] == 0){
					color[target] = 1;
					queue[tail++] = target;
				}
			}
		}
	}
	return sqrt(best[1]);
}

int main(){
	struct Point stone[MAX];
	short nStone, i, k=1;
	double ans;
	while(1 == scanf("%hd", &nStone)){
		if(nStone == 0) return 0;
		for(i=0; i<nStone; i++){
			scanf("%hd %hd", &stone[i].x, &stone[i].y);
		}
		ans = findAns(nStone, stone);
		printf("Scenario #%hd\n",k++);
		printf("Frog Distance = %.3lf\n\n",ans);
	}
	return 0;
}