#include <stdio.h>
#include <string.h>
#define DEBUG 0
#define LEN 128

int calcPeriod(char *input){
	int len;
	int i,j, nRepeat, isPeriodic, offset;
	int period, bound;
	int ans;
	len = strlen(input);
	bound = len / 2;
	for(period = 1; period <= bound; period++){
		if(len % period == 0){
			nRepeat = len / period;
			isPeriodic = 1;
			
			for(j=1, offset = period; (j<nRepeat) && isPeriodic; j++, offset += period){
				if(strncmp(input + offset, input, period) != 0){
					isPeriodic = 0;
				} 
			}
			if(isPeriodic) return period;
		}
	}
	return len;
}

int main(){
	int nTest, first=1;
	char input[LEN];
	FILE *fp;
	fp = (DEBUG)? fopen("in2.txt", "r"):stdin;
	fscanf(fp, "%d", &nTest);
	while(nTest--){
		fscanf(fp, "%s", input);
		if(first){
			first = 0;
		} else{
			printf("\n");
		}
		printf("%d\n",calcPeriod(input));
	}
	return 0;
}