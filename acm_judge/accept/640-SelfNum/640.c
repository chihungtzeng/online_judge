#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SELF 0
#define GENR 1
#define MAX 1000001
#define DEBUG 0

int nextSelf(int n){
	int i;
	int sum=n;
	
	while(n>0){
		sum = sum + (n%10);
		n = n/10;
	}
	return sum;
}


int main(){
	int cur,next,start,i;
	short *state,done;
	state = (short *) malloc(sizeof(short)*MAX);		
	memset(state,SELF,sizeof(short)*MAX);
	
	start = 1;
	cur = 1;
	while(start < MAX){
		if(DEBUG){
			printf("Generate non-self numbers for %d\n",start);
		}
		cur = nextSelf(cur);
		done=0;
		while((cur<MAX)&&(!done)){
			switch (state[cur]){
				case SELF:
					state[cur]=GENR;
					break;
				case GENR:
					done = 1;
					break;
				default:
					printf("Wrong state!\n");
					break; 
			}
			cur = nextSelf(cur);
		}
		start++;
		while(state[start] != SELF){
			start++;
		}
		cur = start;
	}
	
	for(i=1;i<MAX;i++){
		if(state[i] == SELF){
			printf("%d\n",i);
		}
	}
	exit(0);
}