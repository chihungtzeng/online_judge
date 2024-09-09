#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <string.h>
#define MAX 16777216
#define DEBUG 0

int *newSnowFlake(int s){
	int *snow;
	snow = (int *) malloc(sizeof(int));
	*snow = s;
	return snow;
}

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(){
	void *root;
	int *match, *snow, *tmp;
	short nTest;
	int nSnow, maxPackage, i, j, start, count, snowFlake;
	int *iRead;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in3.txt","r") : stdin;
	
	iRead = (int *) malloc(sizeof(int)*MAX);
	fscanf(fp, "%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		fscanf(fp, "%d",&nSnow);
		maxPackage = 0;
		root = NULL;
		count = 0;
		for(i = nSnow; i>=1; i--){
			fscanf(fp, "%d",&snowFlake);
			snow = newSnowFlake(snowFlake);
			match = tfind(snow, &root, compareInt);
			if(match == NULL){
				tsearch(snow, &root, compareInt);
				iRead[count++] = snowFlake;
			}
			else{
				if(count > maxPackage){
					maxPackage = count;
				}
				/*rebuild search tree from the last immediate repetition*/
				tdestroy(root, free);
				root = NULL;
				start = 0;
				while(iRead[start] != snowFlake){
					start++;
				}
				start++;
				for(j=start; j<count; j++){
					tmp = newSnowFlake(iRead[j]);
					tsearch(tmp, &root, compareInt);
				}
				count = count - start;
				memmove(iRead, iRead + start, sizeof(int)*count);
				tsearch(snow, &root, compareInt);
				iRead[count++] = snowFlake;
			}
		}
		if(count > maxPackage){
			maxPackage = count;
		}
		printf("%d\n",maxPackage);
	}
	if(root != NULL){
		tdestroy(root, free);
	}
	free(iRead);
	return 0;
}