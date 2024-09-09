#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 21
#define UP 1
#define DOWN 0


short n, r, k;
long nPath[2*MAXN][MAXN][MAXN][2];



void fillNPath(){
	short x, y, p, end, prex, prey, prep;
	short prange, nexty;
	memset(nPath, 0, sizeof(long)*MAXN*MAXN*MAXN*2);
	nPath[0][0][0][DOWN] = 1;
	end = n << 1;
	
	prange = n;
	
	for(x=1; x <= end; x++){
		prex = x - 1;
		/*y=0 and p=0*/
		if(k == 1){
			nPath[x][0][0][DOWN] = nPath[prex][1][0][DOWN];
		} 
		else{
			nPath[x][0][0][DOWN] = nPath[prex][1][0][DOWN] + nPath[prex][1][0][UP];
		}
		/*y=0 and p>0*/
		for(p=1; p <= prange; p++){
			if(k == 1){
				nPath[x][0][p][DOWN] = nPath[prex][1][p][DOWN] + nPath[prex][1][p-1][UP];
			}
			else {
				nPath[x][0][p][DOWN] = nPath[prex][1][p][DOWN] + nPath[prex][1][p][UP];
			}
		}
		
		for(y=1; y <= n; y++){
			prey = y - 1;
			nexty = y + 1;
			/*y>0 and p=0*/
			nPath[x][y][0][UP] = nPath[prex][prey][0][DOWN] + nPath[prex][prey][0][UP];
			if(y + 1 == k){
				nPath[x][y][0][DOWN] = nPath[prex][nexty][0][DOWN];
			}
			else{
				nPath[x][y][0][DOWN] = nPath[prex][nexty][0][DOWN] + nPath[prex][nexty][0][UP];
			}
			/*y>0 and p>0*/
			for(p=1; p <= prange ; p++){
				if( nexty == k ){
					nPath[x][y][p][DOWN] = nPath[prex][nexty][p][DOWN] + nPath[prex][nexty][p-1][UP];
				}
				else{
					nPath[x][y][p][DOWN] = nPath[prex][nexty][p][DOWN] + nPath[prex][nexty][p][UP];
				}
				nPath[x][y][p][UP] = nPath[prex][prey][p][DOWN] + nPath[prex][prey][p][UP];
			}
			
		}
	}
}

int main(){
	while(3 == scanf("%hu %hu %hu",&n, &r, &k)){
		fillNPath();
		printf("%ld\n",nPath[n << 1][0][r][DOWN]);
	}
	return 0;
}
