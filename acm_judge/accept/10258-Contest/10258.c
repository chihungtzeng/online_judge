#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 16
#define MAX 101
#define DEBUG 0

struct Submit{
	char teamId;
	char problemId;
	char correct;
	short penalty;
};

struct Team{
	char nSolve;
	char doSubmit;
	char teamId;
	short penalty;
};

struct Team team[MAX];
struct Submit *submit[10000];
short nSubmit;

int compareTeam(const void *a, const void *b){
	struct Team *x, *y;
	x = (struct Team *)a;
	y = (struct Team *)b;
	if(x->nSolve != y->nSolve) return y->nSolve - x->nSolve;
	if(x->penalty != y->penalty) return x->penalty - y->penalty;
	return x->teamId - y->teamId; 
}

struct Submit *newSubmit(char teamId, char problemId, char correct, short submitTime){
	struct Submit *s;
	s = (struct Submit *) malloc(sizeof(struct Submit));
	s->teamId = teamId;
	s->correct = correct;
	s->problemId = problemId;
	s->penalty = (correct == 'C')? submitTime : 20;
	return s;
}

struct Submit *findSubmit(char teamId, char problemId){
	short i;
	for(i=0; i<nSubmit; i++){
		if( (submit[i]->teamId == teamId) && (submit[i]->problemId == problemId)){
			return submit[i];
		} 
	}
	return NULL;
}

int solve(){
	short i, tid, n=0;
	struct Team sTeam[MAX];
	if(DEBUG){
		for(i=0; i<nSubmit; i++){
			printf("tid: %hhd pid:%hhd penalty:%hd correct=%c\n",submit[i]->teamId, submit[i]->problemId, submit[i]->penalty, submit[i]->correct);
		}
	}
	
	for(i=0; i<nSubmit; i++){
		tid = submit[i]->teamId;
		team[tid].nSolve += (submit[i]->correct == 'C')? 1 : 0;
		team[tid].penalty += (submit[i]->correct == 'C')? submit[i]->penalty : 0;
	}
	
	for(i=0; i<MAX; i++){
		if(team[i].doSubmit){
			memcpy(&sTeam[n], &team[i], sizeof(struct Team));
			n++;
		}
	}
	qsort(sTeam, n, sizeof(struct Team), compareTeam);
	for(i=0; i<n; i++){
		printf("%hhd %hhd %hd\n",sTeam[i].teamId, sTeam[i].nSolve, sTeam[i].penalty);
	}
	return EXIT_SUCCESS;
}

int main(){
	short nTest;	
	char line[LEN];
	char teamId, problemId, submitType, type[2];
	char first = 1;
	short submitTime;
	short i, j, idx;
	struct Submit submitEntry, *match;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in3.txt","r") : stdin;
	fgets(line, LEN, fp);
	nTest = atoi(line);
	fgets(line, LEN, fp); /*first empty line*/
	while(nTest >= 1){
		if(first){
			first = 0;
		}
		else{
			printf("\n");
		}
		nTest--;
		nSubmit = 0;
		memset(team, 0, sizeof(struct Team)*MAX);
		for(i=0; i<MAX; i++){
			team[i].teamId = i;
		}
		
		while(NULL != fgets(line, LEN, fp)){
			if( (line[0] == ' ') || (line[0] == '\n')){		
				break;
			}
			
			sscanf(line, "%hhd %hhd %hd %s", &teamId, &problemId, &submitTime, type);
			submitType = type[0];
			team[teamId].doSubmit = 1;
			if( (submitType == 'R') || (submitType == 'U') || (submitType == 'E')) continue;
			
			match = findSubmit(teamId, problemId);
			
			if(match){
				if((match->correct == 'I') && (submitType == 'I')){
					match->penalty += 20;
				}
				else if ((match->correct == 'I') && (submitType == 'C')){
					match->penalty += submitTime;
					match->correct = 'C';
				}
			}
			else{
				submit[nSubmit++] = newSubmit(teamId, problemId, submitType, submitTime);
			}
		}
		
		solve();
		for(i=0; i<nSubmit; i++){
			free(submit[i]);
		}
	}
	return 0;
}