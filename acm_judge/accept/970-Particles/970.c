#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 0
#define NOTRY 15
#define MAX 101

struct quarkSeq{
	short qs[MAX];
	short len;
};


int rTable[][3] ={ {1, 0, 2}, {0, 1, 1}, {2, 1, 0}};
int qCount[3];
short nX, nY, nZ;

void reduceString(char *seq){
	/*
		ZXZ -> ZZ XYX->XX YYY->YY YZY->YY
	*/
	char reduceStr[4][4] = { {'Z', 'X', 'Z', '\0'}, {'X', 'Y', 'X', '\0'},
				{'Y', 'Y', 'Y', '\0'}, {'Y','Z', 'Y', '\0'}};
	char *head, *ch;
	short idx, done;
	done = 0;
	
	
	while(!done){
		head = NULL;
		idx = 0;
		while((head == NULL) && (idx <= 3)){
			head = strstr(seq, reduceStr[idx++]);
		}
		if(head == NULL){
			done = 1;
		}
		else {
			ch = head + 2;
			if(idx == 0){
				head[1] = 'Z'; 
			}
			else if (idx == 1){
				head[1] = 'X';
			}
			else if (idx == 3){
				head[1] = 'Y';
			}
			while(*ch != '\0'){
				*ch = *(ch+1);
				ch++;
			} 
		}
	}
}

void react(struct quarkSeq *qSeq){
	struct quarkSeq *out1;
	
	if(qSeq == NULL){
		printf("NULL pointer detected\n");
		return ;
	}


	if( (nZ > 0) && (qCount[2] > 0)){
		return ;
	}
	else if ((nZ == 0) && (nY > 0) && (qCount[1] >0)){
		return ;
	}
	else if ((nZ == 0) && (nY == 0) && (nX > 0) && (qCount[0] >0)){
		return ;
	}
	
	if(qSeq->len == 1){
		qCount[qSeq->qs[0]] += 1;
		return ;
	}


	/*
	if(qSeq->len > NOTRY){
		int r;
		srand(time(NULL));

		if((nZ == 0)){
			if(rand() % 2 == 0){
				qCount[0] += 1;
			}
			else{
				qCount[1] += 1;
			}
		}
		else {
			r = rand() % 9;
			if(r <= 2){
				qCount[0] += 1;
			}
			else if (r <= 6){
				qCount[1] += 1;
				
			}
			else {
				qCount[2] += 1;
			}
		}
	}	*/
	
		/*q[len - 2] reacts with q[len-1]*/
		out1 = (struct quarkSeq *) malloc(sizeof(struct quarkSeq));
		memcpy(out1, qSeq, sizeof(struct quarkSeq));
		out1->qs[out1->len - 2] = rTable[out1->qs[out1->len - 1]][out1->qs[out1->len - 2]];
		out1->len -= 1;
		react(out1);	
		
		/*q[len - 2] reacts with q[len-3]*/
		if(qSeq->len >= 3){
			memcpy(out1, qSeq, sizeof(struct quarkSeq));
			out1->qs[out1->len - 3] = rTable[out1->qs[out1->len - 2]][out1->qs[out1->len - 3]];
			out1->qs[out1->len - 2] = out1->qs[out1->len - 1];
			out1->len -= 1; 
			react(out1);
		}
		free(out1);
	
}



int main(){
	int nTest,i;
	char seqStr[MAX];
	
	short nReduceStr = 4;
	char *substring;
	struct quarkSeq *qSeq;	
	
	scanf("%d", &nTest);
		
	while(nTest >= 1){
		short qs[MAX];
		nTest--;
		scanf("%s",seqStr);
		if(DEBUG){
			printf("string length before reducing:%ld\n",strlen(seqStr));
		}
		reduceString(seqStr);

		qSeq = (struct quarkSeq *)malloc(sizeof(struct quarkSeq));
		qSeq->len = strlen(seqStr);
		if(DEBUG){
			printf("string length after:%d\n",qSeq->len);
		}
		nZ= 0;
		nY= 0;
		nX=0;
		for(i = qSeq->len - 1; i >= 0;i--){
			if(seqStr[i] == 'Z'){
				nZ++;
			}
			else if(seqStr[i] == 'Y'){
				nY++;
			}
			else {
				nX++;
			}
			qs[i] = seqStr[i] - 'X';
		}
		if(DEBUG){
			printf("nX:%d nY:%d nZ:%d\n",nX,nY,nZ);
		}
		
		
		memcpy(qSeq->qs, qs, sizeof(short)*MAX);
		memset(qCount, 0 , sizeof(int)*3);


		if( (nX == qSeq->len) && (qSeq->len > NOTRY)){
			if(nX % 2 == 1){
				qCount[0] += 1;
			}
			else {
				qCount[1] += 1;
			}
		}
		else if ((nY == qSeq->len)&& (qSeq->len > NOTRY)){
			qCount[1] += 1;
		}
		else {
			react(qSeq);
		}
		
		int idx;
		if(qCount[2] > 0){
			idx = 2;
		} 
		else if (qCount[1] > 0){
			idx = 1;
		}
		else {
			idx = 0;
		}
		if(DEBUG){
			printf("X:%d Y:%d Z:%d\n",qCount[0], qCount[1], qCount[2]);
		}
		printf("%c\n",idx+'X');		
		free(qSeq);
	}
	return 0;
}