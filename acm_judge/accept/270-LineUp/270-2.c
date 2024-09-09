#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1000
#define MAX 701

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(){
	short nTest, nPoint, ans, count, i;
	char line[LEN];
	int slope[MAX], x, y;
	char *tok, done, firstCase = 1;
	FILE *fp;
	
	
	fp = stdin;

	fgets(line, LEN, fp);
	nTest = atoi(line);
	fgets(line, LEN, fp); /*the first empty line*/
	while(nTest >= 1){
		nTest--;		
		nPoint = 0 ;
		done = 0;
		while(!done){
			if(NULL == fgets(line, LEN, fp)){
				done = 1;
				continue;
			}
			
			tok = strtok(line, " \n");
			if(tok == NULL) {
				done = 1;
				continue;
			}
			
			x = atoi(tok);
			tok = strtok(NULL, " \n");
			y = atoi(tok);
			
			slope[nPoint++] = y/x;
			
		}
		qsort(slope, nPoint, sizeof(int), compareInt);
		ans = 0;
		count = 1;
		for(i=1; i<nPoint; i++){
			if(slope[i] == slope[i-1]){
				count++;
			} 
			else{
				if(count > ans){
					ans = count;
				}
				count = 1;
			}
		}			
		if(count > ans){
			ans = count;
		}
		
		if(firstCase){
			firstCase = 0;
		}
		else{
			printf("\n");
		}
		printf("%hd\n",ans);
	
	}
	return 0;
}