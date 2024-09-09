#include <stdio.h>
#include <string.h>
#define LEN 128
#define DEBUG 0

int main(){
	char line[LEN];
	
	long long fx, a, b, c, d, L;
	int count, i;
	
	while(NULL != fgets(line, LEN, stdin)){
		if(!strncmp(line, "0 0 0 0 0\n", 10)) return 0;
		
		sscanf(line, "%lld %lld %lld %lld %lld", &a, &b, &c, &d, &L);
		count = 0;
		for(i=0; i<=L; i++){
			fx = a*i*i + b*i + c;
			if(fx % d == 0) count++;
		}
		printf("%d\n",count);
	}
	return 0;
}