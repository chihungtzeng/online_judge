#include <stdio.h>
#include <math.h>
#define MAX 255000

double logsum[MAX];
int nFac;

int findAns(int target){
	int left, right, middle;
	left = 0;
	right = nFac - 1;
	while(left <= right){
		middle = (left + right) >> 1;
		if ((logsum[middle] < target) && (logsum[middle + 1] > target)){
			return middle;
		}
		else if ((logsum[middle - 1] < target) && (logsum[middle] > target)){
			return middle - 1;
		}
		else if (logsum[middle] < target){
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}
	return (left + right) >> 1;
}

int main(){
	int nBit;
	int nInterval;
	int year,i, fac;
	char line[100];
	
	logsum[0] = 0;
	logsum[1] = 0;
	for(i=2; (i<MAX) && (logsum[i-1] <= (1 << 22)); i++){
		logsum[i] = logsum[i-1] + log2(i);
	}
	
	nFac = i - 1;
	/*printf("%d fac\n", nFac);*/
	while(1){
		fgets(line, 100, stdin);
		year = atoi(line);
		if(year == 0){
			break;
		}
		nInterval = (year - 1960)/10;
		nBit = 4 << nInterval;
		printf("%d\n",findAns(nBit));
	}
	
	return 0;
}