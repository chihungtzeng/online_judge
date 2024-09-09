#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define LEN 4096
#define MAX 32
#define DEBUG 0

struct Team{
	char name[MAX];
	short nPoint;
	short nWin, nLose, nTie;
	short nGame;
	short goalScore, goalAgainst;
};

int mystrcmp(char *s, char *t){
	char *x, *y;
	x = s;
	y = t;
	while((tolower(*x) == tolower(*y)) && (*x != '\0') && (*y != '\0')){
		x++;
		y++;
	}
	return *x - *y;
}

int compareTeam(const void *a, const void *b){
	struct Team *x, *y;
	x = (struct Team *)a;
	y = (struct Team *)b;
	if(x->nPoint != y->nPoint) return y->nPoint - x->nPoint;
	if(x->nWin != y->nWin) return y->nWin - x->nWin;
	if(x->goalScore - x->goalAgainst != y->goalScore - y->goalAgainst)
		return (y->goalScore - y->goalAgainst) - (x->goalScore - x->goalAgainst);
	if(x->goalScore != y->goalScore) return y->goalScore - x->goalScore;
	if(x->nGame != y->nGame) return x->nGame - y->nGame;	
	return strcasecmp(x->name, y->name);   
}

int compareTeamByName(const void *a, const void *b){
	struct Team *x, *y;
	x = (struct Team *)a;
	y = (struct Team *)b;
	return strcmp(x->name, y->name);
}

int parse(char line[], struct Team team[], short nTeam){
	char score[2], i, foe;
	char *tok;
	struct Team *match, query[2];
	
	tok = strtok(line, "#");
	strcpy(query[0].name, tok);
	tok = strtok(NULL, "@");
	score[0] = atoi(tok);
	tok = strtok(NULL, "#");
	score[1] = atoi(tok);
	tok = strtok(NULL, "\n");
	strcpy(query[1].name, tok);
	if(DEBUG){
		printf("%s %hhd v.s. %s %hhd\n", query[0].name, score[0], query[1].name, score[1]);
	}
	for(i=0; i<2; i++){
		foe = 1 - i;
		match = bsearch(&query[i], team, nTeam, sizeof(struct Team), compareTeamByName);
		assert(match != NULL);
		match->nGame += 1;
		if(score[i] > score[foe]){
			match->nWin += 1;
			match->nPoint += 3;
		}
		else if (score[i] == score[foe]){
			match->nTie += 1;
			match->nPoint += 1;
		}
		else {
			match->nLose += 1;
		}
		match->goalScore += score[i];
		match->goalAgainst += score[foe];
	} 
	
	return EXIT_SUCCESS;
}



int main(){
	short nTest, nTeam, nGame;
	short i, len;
	char line[LEN];
	char title[LEN];
	char first=1;
	struct Team team[MAX];
	FILE *fp = stdin;
	
	fgets(line, LEN, fp);
	nTest = atoi(line);	
	while(nTest >= 1){
		nTest--;
		fgets(title, LEN, fp);
		fgets(line, LEN, fp);
		nTeam = atoi(line);
		memset(team, 0, sizeof(struct Team)*MAX);
		for(i=0; i<nTeam; i++){
			fgets(team[i].name, MAX, fp);
			len = strlen(team[i].name);
			if(team[i].name[len - 1] == '\n'){
				team[i].name[len - 1] = '\0';
			}			
		}
		qsort(team, nTeam, sizeof(struct Team), compareTeamByName);
		fgets(line, LEN, fp);
		nGame = atoi(line);
		for(i = nGame - 1; i >= 0; i--){
			fgets(line, LEN, fp);
			parse(line, team, nTeam);
		}
		qsort(team, nTeam, sizeof(struct Team), compareTeam);
		
		if(first){
			first = 0;
		}
		else{
			printf("\n");
		}
		printf("%s",title);
		for(i=0; i<nTeam; i++){
			printf("%hd) %s %hdp, %hdg (%hd-%hd-%hd), %hdgd (%hd-%hd)\n",
				i + 1, team[i].name, team[i].nPoint, team[i].nGame,
				team[i].nWin, team[i].nTie, team[i].nLose,
				team[i].goalScore - team[i].goalAgainst,
				team[i].goalScore, team[i].goalAgainst);
		}
	}
	return 0;
}