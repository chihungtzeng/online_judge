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
	unsigned int taskId;
};

unsigned char timeline[LEN];

struct Task regular[101], repeate[101];
int nRegular, nRepeate;

int findType(int pos){
	if(timeline[pos] == 0) return NONE;

	
	if((timeline[pos] == timeline[pos - 1]) && (timeline[pos] == timeline[pos + 1])){
		return MIDDLE;
	} 
	else if ((timeline[pos] != timeline[pos - 1]) && (timeline[pos] == timeline[pos + 1])){
		return START;
	}
	else if ((timeline[pos] == timeline[pos - 1]) && (timeline[pos] != timeline[pos + 1])){
		return END;
	}
	else return SHIT;
}


int setInterval(int start, int end, int taskId){
	int i; 
	int x, type;

	if(DEBUG){
		printf("set [%d %d] to task %d\n", start, end, taskId);
	}
	
	for(i = start + 1; i < end; i++){
		if( (timeline[i] > 0) && (timeline[i] != taskId)){
			if(DEBUG) printf("conflict at time %d\n", i);
			return CONFLICT;
		}
		else{
			timeline[i] = taskId;
		}
	}
	/*for start time*/
	type = findType(start);
	if( (type != MIDDLE) || (timeline[start] == taskId)){
		timeline[start] = taskId;
	}
	else{
		if(DEBUG) printf("conflict at time %d\n", start);
		return CONFLICT;
	}
	/*for end time*/
	type = findType(end);
	if( (type != MIDDLE) || (timeline[end] == taskId)){
		timeline[end] = taskId;
	}
	else{
		if(DEBUG) printf("conflict at time %d\n", end);
		return CONFLICT;
	}
	
	return NO_CONFLICT;
}

int checkConflict(){
	int i, done;
	int x, s, t;
	memset(timeline, 0, sizeof(unsigned char)*LEN);
	
	
	for(i=1; i<=nRegular; i++){
		if(CONFLICT == setInterval(regular[i].start, regular[i].end, regular[i].taskId)){
			return CONFLICT;
		}
	}
	for(i=1; i<=nRepeate; i++){
		done = 0;
		s = repeate[i].start;
		t = repeate[i].end;

		while((s <= MAX) && (t <= MAX)){
			if(CONFLICT == setInterval(s, t, repeate[i].taskId)){
				return CONFLICT;
			}
			s += repeate[i].interval;
			t += repeate[i].interval;
		}
		if(s <= MAX){
			for(x=s+1; x<=MAX; x++){
				if( (timeline[x] > 0) && (timeline[x] != repeate[i].taskId)){
					if(DEBUG) printf("conflict at time %d\n", x);
					return CONFLICT;
				}
				else {
					timeline[x] = repeate[i].taskId;
				}
			}
			x = findType(s);
			if( (x != MIDDLE) || (timeline[s] == repeate[i].taskId)){
				timeline[s] = repeate[i].taskId;
			}
			else{
				if(DEBUG) printf("conflict at time %d\n", s);
				return CONFLICT;
			}	
		}
	}
	return NO_CONFLICT;
}

int main(){
	int i;
	FILE *fp;
	fp = (DEBUG)? fopen("in5.txt", "r") : stdin;
	while(2 == fscanf(fp, "%d %d", &nRegular, &nRepeate)){
		if( (0 == nRegular) && (0 == nRepeate)) return 0;
		
		for(i=1; i<=nRegular; i++){
			fscanf(fp, "%d %d", &regular[i].start, &regular[i].end);
			regular[i].taskId = i;
			if(DEBUG){
				printf("regular task: [%d %d] id=%d\n", regular[i].start, regular[i].end, regular[i].taskId);
			}
		}
		for(i=1; i<=nRepeate; i++){
			fscanf(fp, "%d %d %d", &repeate[i].start, &repeate[i].end, &repeate[i].interval);
			repeate[i].taskId = nRegular + i;
			if(DEBUG){
				printf("repeated task: [%d %d], interval=%d, id=%d\n", repeate[i].start, repeate[i].end, repeate[i].interval, repeate[i].taskId);
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