#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define LEN 50
#define DEBUG 0


char rNum[LEN];
short nRepeat, nRegular;
short kase = 1;
long long p10[LEN];

long long gcd(long long a, long long b){
	if(0 == b) return a;
	else return gcd(b, a % b);
}

void solve(){
	long long up, down, g;
	char i;
	char *sup[2];
	
	if(0 != nRepeat){
		nRegular = strlen(rNum) - 2 - nRepeat;
		sup[0] = strndup(rNum + 2, nRegular + nRepeat);
		sup[1] = strndup(rNum + 2, nRegular);
		up = atoll(sup[0]) - atoll(sup[1]);
		down = p10[nRegular + nRepeat] - p10[nRegular];
		if(DEBUG){
			printf("\n");
			printf("sup[0]=%s sup[1] = %s, up=%lld, down=%lld\n", sup[0], sup[1], up, down);
		}
		free(sup[0]);
		free(sup[1]);
	}
	else{
		up = atoll(rNum + 2);
		down = p10[strlen(rNum) - 2]; 
	}
	
	g = gcd(up, down);
	if(g > 1){
		up = up / g;
		down = down / g;
	}
	printf("Case %hd: %lld/%lld\n", kase++, up, down);
}

int main(){
	FILE *fp;
	char j;
	fp = (DEBUG)? fopen("in3.txt", "r") : stdin;
	p10[0] = 1;
	for(j=1; j<LEN; j++){
		p10[j] = p10[j-1]*10;
	}
	while(1 == fscanf(fp, "%hd", &nRepeat)){
		if(-1 == nRepeat) return 0;
		
		fscanf(fp, "%s", rNum);
		
		if(DEBUG){
			printf("nRepeat=%hd, real=%s\n", nRepeat, rNum);
		}
		if((0 == nRepeat) && (atof(rNum) == 0)){
			printf("Case %hd: 0/1\n", kase++);
		}
		else{
			solve();
		}
	}
	return 0;
}