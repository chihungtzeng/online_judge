#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_CITY_NUM 101
#define INF 100000




struct Point {
	short x, y;
};

int squareSum(int a, int b){
	return a*a + b*b;
}

void calculateDist(
	short nCity, 
	struct Point cityPos[], 
	double dist[MAX_CITY_NUM][MAX_CITY_NUM],
	char connected[MAX_CITY_NUM][MAX_CITY_NUM])
{	
	short i, j;
	int sum;
	for(i=0; i<nCity; i++){
		dist[i][i] = 0;
		connected[i][i] = 0;
		for(j=i+1; j<nCity; j++){		
			sum = squareSum(cityPos[i].x - cityPos[j].x, cityPos[i].y - cityPos[j].y);
			if(sum > 100){
				dist[i][j] = INF;
				dist[j][i] = INF;
				connected[i][j] = 0;
				connected[j][i] = 0;
			} else{
				dist[i][j] = sqrt(sum);
				dist[j][i] = dist[i][j];
				connected[i][j] = 1;
				connected[j][i] = 1;
			}
		}
	}
}

int isGraphConnected(short nCity, char connected[MAX_CITY_NUM][MAX_CITY_NUM]){
	char queue[MAX_CITY_NUM];
	char color[MAX_CITY_NUM];
	char src, target;
	char head = 0, tail = 1, i;
	memset(color, 0, nCity);
	
	queue[0] = 0;
	color[0] = 1;
	while(head < tail){
		src = queue[head++];
		for(i=0; i<nCity; i++){
			if(connected[src][i]){
				if(color[i] == 0){
					queue[tail++] = i;
					color[i] = 1;
				}
			}
		}
	}
	for(i=0; i<nCity; i++){
		if(color[i] == 0) return 0;
	}
	return 1;
}

double solve(short nCity, double dist[MAX_CITY_NUM][MAX_CITY_NUM]){
	double curDist[MAX_CITY_NUM][MAX_CITY_NUM];	
	double newDist, result;
	short u, v, w;
	
	for(u = 0; u < nCity; u++){
		for(v=0; v < nCity; v++){
			for(w = v + 1; w < nCity; w++){
				newDist = dist[v][u] + dist[u][w];
				if(newDist  < dist[v][w]){
					curDist[v][w] = newDist;
					curDist[w][v] = newDist;
				} else{
					curDist[v][w] = dist[v][w];
					curDist[w][v] = dist[w][v];
				}
			}
		}
		memcpy(dist, curDist, sizeof(double)*MAX_CITY_NUM*MAX_CITY_NUM);
	}
	
	result = 0;
	for(u=0; u<nCity; u++){
		for(v=u+1; v<nCity; v++){
			if(result < dist[u][v]){
				result = dist[u][v];
			} 
		}
	} 
	return result;
}

int main(){
	double dist[MAX_CITY_NUM][MAX_CITY_NUM];
	double ans;
	char connected[MAX_CITY_NUM][MAX_CITY_NUM];
	short nCity, i;
	struct Point cityPos[MAX_CITY_NUM];
	FILE *fp = stdin;
	int k = 1, nTest;
	fscanf(fp, "%d", &nTest);
	while(nTest--){
		fscanf(fp, "%hd", &nCity);
		for(i=0; i<nCity; i++){
			fscanf(fp, "%hd %hd", &cityPos[i].x, &cityPos[i].y);
		}
		calculateDist(nCity, cityPos, dist, connected);
		printf("Case #%d:\n", k++);
		if(isGraphConnected(nCity, connected)){
			ans = solve(nCity, dist);
			printf("%.4lf\n", ans);
		} else{
			puts("Send Kurdy");
		}
		puts("");
	}
	return 0;
}