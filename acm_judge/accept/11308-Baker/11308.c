#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 63
#define MAX 1024

struct Ingredient{
	char name[LEN];
	short cost;
};

struct Recipe{
	char name[LEN];
	char affordable;
};

int compareIngredient(const void *a, const void *b){
	struct Ingredient *x, *y;
	x = (struct Ingredient *)a;
	y = (struct Ingredient *)b;
	return strcmp(x->name, y->name);
}

int removeTrailingNewLine(char line[]){
	int len;
	len = strlen(line);
	len--;
	if(line[len] == '\n') line[len] = '\0';
	return len;
}

int main(){
	char nTest;
	char line[MAX];
	char title[MAX];
	FILE *fp = stdin;
	int i, j, len, budget, state;
	short nIngredient, nRecipe;
	struct Ingredient ingredient[101];
	
	
	fgets(line, MAX, fp);
	nTest = atoi(line);
	while(nTest >= 1){
		nTest--;
		fgets(title, MAX, fp);
		len = removeTrailingNewLine(title);
		for(i=0; i<len; i++){
			title[i] = toupper(title[i]);
		}
		fgets(line, MAX, fp);
		sscanf(line, "%hd %hd %d", &nIngredient, &nRecipe, &budget);
		for(i=0; i<nIngredient; i++){
			fgets(line, MAX, fp);
			state = sscanf(line, "%s %d", ingredient[i].name, &ingredient[i].cost);
			if(state != 2){
				ingredient[i].cost = 0;
			}
		}
	}
}