#include <stdio.h>
#define MAX 1000002
#define DEBUG 0

char line[MAX];
int pSum[MAX];
size_t len;

void parseLine(){
	len = 0;
	char *pos;
	int *target, *pre;
	
	pos = line + 1;
	target = pSum + 1;
	pre = pSum;
	while(*pos != '\0'){
		*target = *pre + (*pos - '0');
		pre = target;
		target += 1;
		pos += 1;
	} 
	len = pos - line - 1;
}

int main(){
	FILE *fp;
	int nQuery, start, end, i, nEle, sum;
	short k = 1;
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	pSum[0] = 0;
	while(1 == fscanf(fp, "%s", &line[1])){
		printf("Case %hd:\n",k++);
		parseLine();
		
		fscanf(fp, "%d", &nQuery);
		for(i=0; i<nQuery; i++){
			fscanf(fp, "%d %d", &start, &end);
			if(start > end){
				/*SWAP*/
				start = start ^ end;
				end = start ^ end;
				start = start ^ end;
			}
			nEle = end - start + 1;
			start++;
			end++;
			sum = pSum[end] - pSum[start - 1];
			/*printf("sum=%d nEle=%d start=%d end=%d ", sum, nEle, start, end);*/ 
			if((sum == 0) || (sum == nEle)){
				puts("Yes");
			} else {
				puts("No");
			}
		}
	}
	return 0;
}
