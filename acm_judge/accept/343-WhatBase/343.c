#include <stdio.h>
#include <string.h>
#define LEN 128
#define MAXBASE 37

char X[LEN], Y[LEN];
int baseMap[255];
int xMinBase, yMinBase;

int compareLL(const void *a, const void *b){
	return *(long long *)a - *(long long *)b;
}

void buildTable(){
	char i;
	
	for(i='0'; i<='9'; i++){
		baseMap[i] = i - '0';
	}
	for(i='A'; i<='Z'; i++){
		baseMap[i] = i - 'A' + 10;
	}
}

int minBase(char *s){
	char *p;
	int result = 0;
	p = s;
	while(*p != '\0'){
		if(baseMap[*p] > result){
			result = baseMap[*p];
		}
		p++;
	}
	return result;
}

unsigned long long itoa(char *s, int base){
	unsigned long long result = 0;
	while(*s != '\0'){
		result = result * base + baseMap[*s];
		s++;
	}
	return result;
}

int myBsearch(unsigned long long target, unsigned long long pArray[], int left, int right){
	int middle;
	while(left <= right){
		middle = (left + right) >> 1;
		if(pArray[middle] == target) return middle;
		else if (pArray[middle] < target) left = middle + 1;
		else right = middle - 1;
	}
	return -1;
}

void solve(){
	int i, nPXValue;
	unsigned long long xValue[MAXBASE];
	unsigned long long yValue;
	int xBase, xMaxBase, yBase, found;
	xMinBase = minBase(X) + 1;
	if(xMinBase < 2) xMinBase = 2;
	
	yMinBase = minBase(Y) + 1;
	if(yMinBase < 2) yMinBase = 2;
	xValue[1] = -1;
	xMaxBase = MAXBASE - 1;
	for(i=xMinBase; i< MAXBASE; i++){
		xValue[i] = itoa(X, i);
		if(xValue[i] == xValue[i-1]){
			xMaxBase = i - 1;
			break;
		}
	}
	if(xValue[xMinBase] == 0){
		for(i=xMinBase + 1; i< MAXBASE; i++){
			xValue[i] = -1;
		}
	}
	
	#if 0
	printf("xMinBase=%d yMinBase=%d\n", xMinBase, yMinBase);
	for(i=xMinBase; i < 36; i++){
		printf("%llu ", xValue[i]);
	}
	puts("");
	#endif
	
	for(yBase=yMinBase, found = 0; yBase < MAXBASE; yBase++){
		yValue = itoa(Y, yBase);
		xBase = myBsearch(yValue, xValue, xMinBase, xMaxBase);
		if(xBase >= 2){
			found = 1;
			break;
		}
	}
	if(found){
		printf("%s (base %d) = %s (base %d)\n", X, xBase, Y, yBase);
	} else{
		printf("%s is not equal to %s in any base 2..36\n", X, Y);
	}
	
}

int main(){
	buildTable();
	while(2 == scanf("%s %s", X, Y)){
		solve();
	}
	return 0;
}
