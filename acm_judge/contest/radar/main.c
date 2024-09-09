#include <stdio.h>
#include <string.h>
#define LEN 1000
#define DEBUG 0
#define EPSILON 1e-8

int map[LEN][LEN];
char affected[LEN][LEN];
int n;


struct Point{
	short x, y;
	double range;
};

struct Point radar[LEN*10];
int nRadar;

double findMean(short i, short j){
	int nNeighbor = 0;
	int istep, jstep, icur, jcur;;
	int sum = 0;
	double ell;
	for(istep=-1; istep <= 1; istep++){
		for(jstep = -1; jstep <= 1; jstep++){
			if(abs(istep) + abs(jstep) != 1){
				continue;
			}
			icur = i + istep;
			jcur = j + jstep;
			if((icur < 0) || (icur >= n)) continue;
			if((jcur < 0) || (jcur >= n)) continue;
			
				nNeighbor += 1;
				sum += map[icur][jcur];
			
		}
	}
	if(nNeighbor > 0){
		ell = (sum + 0.0) / nNeighbor;
		return ell*ell;
	}
	else return 0;
}

int dist(short i, short j, short x, short y){
	int p, q;
	p = i - x;
	q = j - y;
	return p*p + q*q;
}

void solve(){
	int i, j;
	int rstep, cstep;
	int row, col, rcur, ccur;
	int ans = 0;
/*
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
*/
	for(i=0; i<nRadar; i++){
		radar[i].range = findMean(radar[i].x, radar[i].y);
		#if 0
		printf("radar (%hd %hd) has range %lf\n", radar[i].x, radar[i].y, radar[i].range);
		#endif
	}
	
	for(i=0; i<nRadar; i++){
		double r;
		row = radar[i].x;
		col = radar[i].y;
		if(radar[i].range == 0) continue;
		r = radar[i].range + EPSILON;
		for(rstep = -radar[i].range; rstep <= radar[i].range; rstep++){
			rcur = row + rstep;
			if(rcur < 0) continue;
			if(rcur >= n) continue;
			for(cstep = -radar[i].range; cstep <= radar[i].range; cstep++){
				
				ccur = col + cstep;	
				if(ccur < 0) continue;
				if(ccur >= n) continue;
				
				if(dist(rcur, ccur, radar[i].x, radar[i].y) < r ){
					affected[rcur][ccur] = 1;
				}
				
			}
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(affected[i][j] == 0){
				ans += 1;
			}
		}
	}
	printf("%d\n", ans);
}

int main(){
	int nTest;
	int i, j;
	FILE *fp;	
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
		
	fscanf(fp, "%d", &nTest);

	

	while(nTest--){
		fscanf(fp, "%d", &n);
		for(i=0; i<LEN; i++){
			memset(map[i], 0, sizeof(map[0][0])*LEN);
			memset(affected[i], 0, sizeof(affected[0][0])*LEN);
		}
		nRadar = 0;
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				fscanf(fp, "%d", &map[i][j]);
				if(map[i][j] == 0){
					radar[nRadar].x = i;
					radar[nRadar].y = j;
					nRadar += 1;
				}
			}
		}
		solve();
	}
	
	return 0;
}