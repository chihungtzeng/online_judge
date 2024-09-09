#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLOOP 406
#define DIVERGE -1
#define UNKNOWN 0
#define MAXNUM 100000

struct queue {
	int value[MAXLOOP];
	int head,tail;
};

int nextInt(int n){
	int r,sum;
	sum = 0;
	while(n>0){
		r = n % 10;
		n = n / 10;
		sum = sum + r*r;
	}
	return sum;
}
void push(struct queue *s, int v){
	if(s->tail < MAXLOOP){
		s->value[s->tail] = v;
		s->tail++;
	}
}
int deque(struct queue *s){
	int v;
	if(s->head <= s->tail){
		v = s->value[s->head];
		s->head++;
		return v;
	}
	return -1;
}
int empty(struct queue s){
	if(s.head > s.tail) return 1;
	else return 0;
}

int main(){
	int happy[MAXLOOP];
	int indeg[MAXLOOP],next[MAXLOOP];
	int toposort[MAXLOOP];

	int i,j,cur,nexti,pos;
	struct queue qq; 
	int count,first;	
	int left,right,tmp;
	
	qq.head = 0;
	qq.tail = 0;
	
	for(i=0;i<MAXLOOP;i++){
		happy[i] = DIVERGE;
		indeg[i] = 0;
	}
		
	happy[0] = DIVERGE;
	next[0] = 0;
	
	happy[1] = 0;
	next[1] = 1;
	
	for(i=2;i<MAXLOOP;i++){
		nexti = nextInt(i);
		next[i] = nexti;
		indeg[nexti]++;
	}
	for(i=2;i<MAXLOOP;i++){
		if(0 == indeg[i]){
			push(&qq, i);
		}
	}
	pos = MAXLOOP-1;
	while(!empty(qq)){
		cur = deque(&qq);
		toposort[pos] = cur;
		pos--;
		nexti = next[cur];
		indeg[nexti]--;
		if(indeg[nexti] == 0){
			push(&qq,nexti);
		}
	}
	for(i=pos+1;i<MAXLOOP;i++){
		cur = toposort[i];
		nexti = next[cur];	
		if(happy[nexti] != DIVERGE){
			happy[cur] = happy[nexti] + 1;
		}
	}
	first = 1;
	while (2 == scanf("%d %d",&left,&right)){
		if(!first){
			printf("\n");
		}
		first=0;
		if(left>right){
			tmp = left;
			left =right;
			right = tmp;
		}
		for(i=left;i<=right;i++){
			if(i<MAXLOOP){
				if(happy[i] != DIVERGE){
					printf("%d %d\n",i,happy[i]);
				}
			}
			else{
				nexti = nextInt(i);
				if(happy[nexti] != DIVERGE){
					printf("%d %d\n",i,happy[nexti]+1);
				}
			}
		}
		
	}
	
	
	exit(0);
}