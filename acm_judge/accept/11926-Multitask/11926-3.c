#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 1000010
#define DEBUG 0
#define CONFLICT 1
#define NO_CONFLICT 0
#define MAX 1000009
#define NONE 0
#define START 1
#define END 2
#define MIDDLE 4
#define SHIT 8

struct Task{
	int start, end;
	int interval;
	unsigned char taskId;
};

unsigned char timeline[LEN];

struct Task regular[102], repeat[102];
unsigned char nRegular, nRepeat;


int setInterval(int start, int end, int taskId){
	int j;
	
	
	return NO_CONFLICT;
}

int checkConflict(){
	unsigned char i;
	int j, k;
	int s, e;
	int state;
	memset(timeline, 0, sizeof(unsigned char)*LEN);
	for(i=1; i<=nRegular; i++){
		for(j=regular[i].start; j < regular[i].end; j++){
			if(timeline[j] == 0){
				timeline[j] = regular[i].taskId;
			}
			else return CONFLICT;
		}
	}
	for(i=1; i<=nRepeat; i++){
		s = repeat[i].start;
		e = repeat[i].end;
		if(e > 1000001) e = 1000001;
		while(s < 1000000){
			for(j=s; j<e; j++){
				if(timeline[j] == 0){
					timeline[j] = repeat[i].taskId;
				}
				else {
					return CONFLICT;
				}
			}		
			s += repeat[i].interval;
			e += repeat[i].interval;
			if(e > 1000001) e = 1000001;
		}
	}
	return NO_CONFLICT;
}

int main(){
	unsigned char i;
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	while(2 == fscanf(fp, "%hhu %hhu", &nRegular, &nRepeat)){
		if( (0 == nRegular) && (0 == nRepeat)) return 0;
		
		for(i=1; i<=nRegular; i++){
			fscanf(fp, "%d %d", &regular[i].start, &regular[i].end);
			regular[i].taskId = i;
			if(DEBUG){
				printf("regular task: [%d %d] id=%d\n", regular[i].start, regular[i].end, regular[i].taskId);
			}
		}
		for(i=1; i<=nRepeat; i++){
			fscanf(fp, "%d %d %d", &repeat[i].start, &repeat[i].end, &repeat[i].interval);
			repeat[i].taskId = nRegular + i;
			if(DEBUG){
				printf("repeatd task: [%d %d], interval=%d, id=%d\n", repeat[i].start, repeat[i].end, repeat[i].interval, repeat[i].taskId);
			}
		}
		
		if(CONFLICT == checkConflict()){
			puts("CONFLICT");
		}
		else{
			puts("NO CONFLICT");
		}
		if(DEBUG) puts("");
	}
	return 0;
}