#include <stdio.h>
#include <string.h>
#define LEN 128
#define MAX 128

struct DNA{
	char seq[MAX];
	char sn;
	short nDisorder;
};

int compareDNA(const void *a, const void *b){
	struct DNA *x, *y;
	x = (struct DNA *)a;
	y = (struct DNA *)b;
	if(x->nDisorder != y->nDisorder) return x->nDisorder - y->nDisorder;
	return x->sn - y->sn;
}

void calDisorder(struct DNA *target){
	short nA = 0, nC=0, nG=0;
	char *s;
	short i;
	target->nDisorder = 0;
	
	s = target->seq;
	while(*s != '\0') s++;
	
/*	short len = strlen(target->seq);*/
	for(; s >= target->seq; s--){
		switch (*s){
			case 'A':
				nA += 1;
				break;
			case 'C':
				target->nDisorder += nA;
				nC += 1;
				break;
			case 'G':
				target->nDisorder += nA + nC;
				nG += 1;
				break;
			case 'T':
				target->nDisorder += nA + nC + nG;
				break;
			default:
				break;
		}
	}
 	
}

int main(){
	short nTest;
	char n, m, i;
	char first = 1;
	struct DNA dna[MAX];
	scanf("%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%hhd %hhd", &n, &m);
		for(i=0; i<m; i++){
			scanf("%s", dna[i].seq);
			dna[i].sn = i;
		}
		for(i=0; i<m; i++){
			calDisorder(&dna[i]);
		}
		qsort(dna, m, sizeof(struct DNA), compareDNA);
		if(first){
			first = 0;
		}
		else{
			printf("\n");
		}
		for(i=0; i<m; i++){
			printf("%s\n", dna[i].seq);
		}
	}
	return 0;
}