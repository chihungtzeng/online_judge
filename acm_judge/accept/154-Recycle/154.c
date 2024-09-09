#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 102
#define DEBUG 1

enum Color {r, o, y, g, b};

struct City{
	char waste[5];
};

struct City city[LEN];
char nCity = 0;


void parseLine(char *line){
	char count;
	char *tok;
	enum Color color;
	tok = strtok(line, ",");
	while(tok != NULL){
		switch (tok[0]){
			case 'r':
				color = r;
				break;
			case 'o':
				color = o;
				break;
			case 'y':
				color = y;
				break;
			case 'g':
				color = g;
				break;
			case 'b':
				color = b;
				break;
			default:
				printf("undefined color: %c\n", tok[0]);
				break;
		}
		city[nCity].waste[color] = tok[2];
		tok = strtok(NULL, ",");
	}
}

void printConfig(){
	char i, j;
	for(i=0; i<nCity; i++){
		for(j=0; j<5; j++){
			printf("%c ", city[i].waste[j]);
		}
		puts("");
	}
	puts("");
}

void solve(){
	int cost = 1000000, curCost;
	char best = LEN;
	char i, j, scheme;
	for(scheme=0; scheme<nCity; scheme++){
		curCost = 0;
		for(i=0; i<nCity; i++){ 
			for(j=0; j<5; j++){
				if(city[i].waste[j] != city[scheme].waste[j]){
					curCost++;
				}
			}
		}
		if(curCost < cost){
			cost = curCost;
			best = scheme;
		}
	}
	printf("%d\n", best + 1);
}

int main(){
	char line[LEN];
	FILE *fp = stdin;	
	
	while(NULL != fgets(line, LEN, fp)){
		if(line[0] == '#') return 0;
		else if (line[0] == 'e'){
			/*printConfig();*/
			solve();
			nCity = 0;
		}
		else{
			parseLine(line);
			nCity++;
		}
	}
	return 0;
} 