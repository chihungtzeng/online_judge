#include <stdio.h>
#include <stdlib.h>

#define LEN 32

char value[256];
char name[2][LEN];

short mapString(char *name){
	char *c;
	short result = 0, tmp;
	for(c=name; *c != '\0'; c++){
		if(isalpha(*c)) result += value[tolower(*c)];
	}
	while(result >= 10){
		tmp = 0;
		while(result > 0){
			tmp += result % 10;
			result = result / 10;
		}
		result = tmp;
	}
	return result;
}

int main(){
	short i;
	FILE *fp = stdin;
	short mappedValue[2];
	double ans;
	for(i='a'; i<='z'; i++){
		value[i] = i - 'a' + 1;
	}
	
	while(NULL != fgets(name[0], LEN, fp)){
		fgets(name[1], LEN, fp);
		mappedValue[0] = mapString(name[0]);
		mappedValue[1] = mapString(name[1]);
		ans = (mappedValue[0] + 0.0)/mappedValue[1];
		if(ans > 1) ans = 1/ans;
		printf("%.2lf %%\n", 100*ans);
	}
		
	return 0;
}