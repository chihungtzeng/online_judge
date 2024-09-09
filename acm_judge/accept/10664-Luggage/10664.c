#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 10000



int dividable(short weight[], short nItem, short desireWeight){
	if(nItem == 0){
		if(desireWeight == 0) return 1;
		else return 0;
	}
	
	if(desireWeight - weight[nItem - 1] >= 0){
		return dividable(weight, nItem - 1, desireWeight - weight[nItem - 1]) || dividable(weight, nItem - 1, desireWeight); 
	}
	else{
		return dividable(weight, nItem - 1, desireWeight);
	}
}

int main(){
	char line[LEN];
	short nTest, nItem, totalWeight;
	short weight[21];
	FILE *fp;
	char *tok;
	
	fp = stdin;	
	
	fgets(line, LEN, fp);
	nTest = atoi(line);
	while(nTest >= 1){
		nTest--;
		fgets(line, LEN, fp);
		nItem = 0;
		totalWeight = 0;
		tok = strtok(line, " \n");
		while(tok != NULL){
			weight[nItem] = atoi(tok);
			totalWeight += weight[nItem];
			nItem++;
			tok = strtok(NULL, " \n");
		}
		if(nItem == 0){
			printf("YES\n");
		}
		else if (totalWeight & 1){
			printf("NO\n");
		}
		else{
			if (dividable(weight, nItem, totalWeight >> 1)){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
	}
	return 0;
}