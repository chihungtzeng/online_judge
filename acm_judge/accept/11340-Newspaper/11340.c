#include <stdio.h>
#include <string.h>
#define CHARRANGE 256
#define MAX 20001
#define DEBUG 0

unsigned int pay[CHARRANGE];
char line[MAX];

unsigned long findPay(char *line){
	char *c;
	unsigned long result = 0;
	c = line;
	while((*c != '\n') && (*c != EOF)){
		result += pay[(unsigned char)*c];
		c++;
	}
	return result;
}

int main(){
	int nTest, money;
	int N, K, i;
	char paychar;
	FILE *fp;
	unsigned long ans, x, y;	
	
	
	fp = (DEBUG)? fopen("in2.txt", "r") : stdin;
	
	fgets(line, MAX, fp);
	nTest = atoi(line);
	
	while(nTest >= 1){
		nTest--;
		memset(pay, 0, sizeof(int)*CHARRANGE);
		ans = 0;
		
		fgets(line, MAX, fp);
		N = atoi(line);
		for(i=N-1; i>=0; i--){
			fgets(line, MAX, fp);
			paychar = line[0];
			strtok(line, " ");
			money = atoi(strtok(NULL, " "));
			pay[paychar] = money; 
		}
		fgets(line, MAX, fp);
		K = atoi(line);
		for(i=K-1; i>=0; i--){
			fgets(line, MAX, fp);
			ans += findPay(line);
		}
		x = ans / 100;
		y = ans % 100;
		
		printf("%ld.%02ld$\n", x, y);
		
	}
	return 0;
}