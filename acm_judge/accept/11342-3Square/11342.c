#include<stdio.h>
#define MAX 50001
#define DEBUG 0

int sq[MAX];
int square[MAX];

int main(){
	int i, nTest;
	int a, b, c, n;
	int ua, ub, remain, remainForC;
	char done;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	
	for(i=0; i<225; i++){
		square[i] = i*i;
	}
	a = 0;
	b = 1;
	for(i=0; i<MAX; i++){
		if (b > i){
			sq[i] = a;
		}
		else{
			a++;
			b = square[a+1];
			sq[i] = a;
		}
	}
	
	if(DEBUG){	
		for(i=0; i<30; i++){
			printf("%d ", sq[i]);
		}
		printf("\n");
	}
	fscanf(fp,"%d", &nTest);
	while(nTest >= 1){
		nTest--;
		fscanf(fp, "%d", &n);
		ua = sq[n];
		done = 0;
		for(a = 0;  (!done) && (a <= ua); a++){
			remain = n - square[a];
			ub = sq[remain];
			for(b = a; (!done) && (b <= ub); b++){
				remainForC = remain - square[b];
				c = sq[remainForC];
				if (square[c] == remainForC){
					done = 1;
					
				}
			}
		}
		
		if(done){
			a--;
			b--;
			printf("%d %d %d\n", a, b, c);
		}
		else {
			printf("-1\n");
		}
	}
		
	
	return 0;
}