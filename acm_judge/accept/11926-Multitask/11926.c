#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 125001
#define DEBUG 0
#define CONFLICT 1
#define NO_CONFLICT 0
#define MAX 1000000

struct Task{
	int start, end;
	int interval;
};

unsigned char timeline[LEN];
struct Task regular[101], repeate[101];
char nRegular, nRepeate;

int setInterval(int start, int end){
	/*
		start = 8*p + q
		end = 8*x + y
	*/
	int i, j, x, y, p, q; 
	p = start >> 3;
	q = start & 0x7;
	x = end >> 3;
	y = end & 0x7;
	unsigned char mask;
	
	
	for(i = p + 1; i < x; i++){
		if(timeline[i] != 0){
			if(DEBUG) printf("---conflict at timeline[%d], start=%d, end=%d\n", i, start, end);
			return CONFLICT;
		}
		else{
			timeline[i] = 0xff;
		}
	}
	
	for(i = q + 1; i<= 7; i++){
		if( (timeline[p] >> i) & 1 != 0){
			if(DEBUG) printf("***conflict at timeline[%d], start=%d, end=%d\n", p, start, end);
			return CONFLICT;
		}
		else{
			timeline[p] |=  (1 << i);
		}
	} 
	timeline[p] |= (1 << q);
	
	for(i = 0; i < y; i++){
		if( (timeline[x] >> i) & 1 != 0){
			if(DEBUG){
				printf("+++conflict at x=%d, y=%d, i=%d timeline[x] = %hhx\n", x, y, i, timeline[x]);
			}
			return CONFLICT;
		}
		else timeline[x] |= (1 << i); 
	}
	timeline[x] |= (1 << y);
	return NO_CONFLICT;
}

int checkConflict(){
	char i, done;
	int x, s, t;
	memset(timeline, 0, sizeof(unsigned char)*LEN);
	
	for(i=0; i<nRegular; i++){
		if(CONFLICT == setInterval(regular[i].start, regular[i].end)){
			return CONFLICT;
		}
	}
	for(i=0; i<nRepeate; i++){
		done = 0;
		s = repeate[i].start;
		t = repeate[i].end;
		if( t > MAX){
			t = MAX;
		}
		
		while(!done){
			if(CONFLICT == setInterval(s, t)){
				return CONFLICT;
			}
			s += repeate[i].interval;
			t += repeate[i].interval;
			if(s > MAX){
				done = 1;
			}		
			if( t > MAX){
				t = MAX;
			}
		}
	}
	return NO_CONFLICT;
}

int main(){
	char i;
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	while(2 == fscanf(fp, "%hhd %hhd", &nRegular, &nRepeate)){
		if( (0 == nRegular) && (0 == nRepeate)) return 0;
		
		for(i=0; i<nRegular; i++){
			fscanf(fp, "%d %d", &regular[i].start, &regular[i].end);
		}
		for(i=0; i<nRepeate; i++){
			fscanf(fp, "%d %d %d", &repeate[i].start, &repeate[i].end, &repeate[i].interval);
		}
		
		if(CONFLICT == checkConflict()){
			puts("CONFLICT");
		}
		else{
			puts("NO CONFLICT");
		}
	}
	return 0;
}