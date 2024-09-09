#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define LEN 32
#define DEBUG 1
#define MAX 1000

struct Order{
	char big, small;
};

void *root;

struct Order *newOrder(char c, char d){
	struct Order *r;
	r = (struct Order *) malloc(sizeof(struct Order));
	r->small = c;
	r->big = d;
	return r;
}

int compareOrder(const void *a, const void *b){
	struct Order *x, *y;
	x = (struct Order *)a;
	y = (struct Order *)b;
	return (x->small - y->small)*32 + (x->big - y->big);
}

int compareChar(const void *a, const void *b){
	char c, d;
	struct Order *order;
	void *match;
	c = *(char *)a;
	d = *(char *)b;
	order = newOrder(c, d);
	match = tfind(order, &root, compareOrder);
	if(match != NULL) return -1;
	free(order);
	order = newOrder(d, c);
	match = tfind(order, &root, compareOrder);
	if(match != NULL) return 1;
	else return c - d;
}

int main(){
	char line[MAX][LEN];
	char flag[26];
	char output[26];
	FILE *fp;
	short i, j, len, nOutput, nLine;
	struct Order *order;
	char *xc, *yc;
	void *match;
		
	fp = (DEBUG)? fopen("in8.txt","r") : stdin;
	memset(flag, 0, 26);
	root = NULL;
	nLine=0;
	while(1 == fscanf(fp, "%s", line[nLine])){
		if(line[nLine][0] == '#'){ break; }
		else{ nLine++;}
	}

	for(i=0; i<nLine; i++){
		for(j=i+1; j<nLine; j++){
			xc = line[i];
			yc = line[j];
			while( (*xc != '\0') && (*yc != '\0') && (*xc == *yc)){
				xc++;
				yc++;
			}
			if( (*xc != '\0') && (*yc != '\0')){
				if(DEBUG){
					printf("(%c < %c) ",*xc, *yc);
				}
				order = newOrder(*xc, *yc);
				match = tsearch(order, &root, compareOrder);
				if(*(struct Order **) match != order){
					free(order);
				}
				flag[*xc - 'A'] = 1;
				flag[*yc - 'A'] = 1;
			}
		}
	}
	
	nOutput = 0;
	for(i=0; i<26; i++){
		if(flag[i] == 1){
			output[nOutput++] = i + 'A';
		}
	}
	qsort(output, nOutput, sizeof(char), compareChar);
	output[nOutput] = '\0';
	printf("%s\n",output);
	
	tdestroy(root, free);
	return 0;
}