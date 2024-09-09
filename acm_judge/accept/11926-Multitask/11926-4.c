#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 125001
#define CONFLICT 1
#define NO_CONFLICT 0
#define BOUND 1000001
#define MASK(j) (1 << ((j) & (7)))
#define BYTEPOS(j) ((j) >> 3) 
#define BITPOS(j) ((j) & 7)
#define DEBUG 0

struct Task{
	int start, end;
	int interval;
};

unsigned char timeline[LEN];

struct Task regular[102], repeat[102];
unsigned char nRegular, nRepeat;
unsigned char mask[8];

int setRange(int start, int end){
	int i, sBytePos, eBytePos;
	int j;
	
	eBytePos = BYTEPOS(end);
	sBytePos = BYTEPOS(start);
	if(DEBUG){
		printf("sByte=%d eBytePos=%d\n", sBytePos, eBytePos);
	}
	for(i = sBytePos + 1; i < eBytePos; i++){
		if(timeline[i] != 0){
			if(DEBUG){
				printf("conflict at byte %d, timeline=%hhx\n", i, timeline[i]);
			}
			return CONFLICT;
		}
		
		else timeline[i] = 0xff; 
	}	
	if(eBytePos > sBytePos){
		for(j = start & 0x07; j < 8; j++){
			if( (timeline[sBytePos] & mask[j]) != 0){
				if(DEBUG){
					printf("conflict at byte %d bit=%d\n", sBytePos, j);
				}
				return CONFLICT;
			}
			else{
				timeline[sBytePos] |=  mask[j];
			}
		} 
		if(end >= start){
			for(j = end & 0x07; j >= 0; j--){
				if((timeline[eBytePos] & mask[j]) != 0){
					if(DEBUG){
						printf("conflict at byte %d bit=%d\n", sBytePos, j);
					}
					return CONFLICT;
				}
				else{
					timeline[eBytePos] |= mask[j];
				}
			} 
		}
	}
	else if(eBytePos == sBytePos){
		for(; start <= end ; start++){
			j = start & 7;
			if((timeline[eBytePos] & mask[j]) != 0){
				if(DEBUG){
					printf("conflict at byte %d bit=%d\n", sBytePos, j);
				}
				return CONFLICT;
			}
			else{
				timeline[eBytePos] |= mask[j];
			}
		}
	}
	return NO_CONFLICT;
}	

int checkConflict(){
	unsigned char i;
	int j;
	int s, e;
	memset(timeline, 0, LEN);
	for(i=1; i<=nRegular; i++){
		if(CONFLICT == setRange(regular[i].start, regular[i].end - 1)){
			return CONFLICT;
		}
	}
	for(i=1; i<=nRepeat; i++){
		s = repeat[i].start;
		e = repeat[i].end;
		e = 1000001 ^ ((e ^ 1000001) & -(e < 1000001));
		while(s < 1000000){
			if(CONFLICT == setRange(s, e - 1)){
				if(DEBUG){
					printf("failed at s=%d e=%d\n", s, e);
				}
				return CONFLICT;
			}
			s += repeat[i].interval;
			e += repeat[i].interval;
			/*
			r = x ^ ((x ^ y) & -(x < y)); // max(x, y)
			r = y ^ ((x ^ y) & -(x < y)); // min(x, y)
			*/
			e = 1000001 ^ ((e ^ 1000001) & -(e < 1000001));
			/*if(e > 1000001) e = 1000001;*/
		}
	}
	return NO_CONFLICT;
}

int main(){
	unsigned char i;
	FILE *fp;
	for(i=0; i<8; i++){
		mask[i] = 1 << (7-i);
		if(DEBUG) {printf("%hhx\n", mask[i]);}
	}
	fp = (DEBUG)? fopen("in5.txt", "r") : stdin;
	while(2 == fscanf(fp, "%hhu %hhu", &nRegular, &nRepeat)){
		if( (0 == nRegular) && (0 == nRepeat)) return 0;
		
		for(i=1; i<=nRegular; i++){
			fscanf(fp, "%d %d", &regular[i].start, &regular[i].end);
		}
		for(i=1; i<=nRepeat; i++){
			fscanf(fp, "%d %d %d", &repeat[i].start, &repeat[i].end, &repeat[i].interval);
		}
		
		if(CONFLICT == checkConflict()){
			puts("CONFLICT");
		}
		else{
			puts("NO CONFLICT");
		}
		if(DEBUG){
			for(i=0; i<4; i++){
				printf("%02hhx ", timeline[i]);
			}
			printf("\n");
		}
		
	}
	return 0;
}