#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCUR 20
#define LEN 1024
#define DEBUG 0

struct stack {
	int seq[MAXCUR];
	int size;
};

void stack_copy(struct stack *from, struct stack *to){
	int i;
	for(i=0; i < from->size; i++){
		to->seq[i] = from->seq[i];
	}
	to->size = from->size;
}
void push(struct stack *target, int x){
	target->seq[target->size] = x;
	target->size += 1;
}

void dumpArray(double a[MAXCUR][MAXCUR],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%4.5f ", a[i][j]);
		}
		printf("\n");
	}
}

int intcmp(int a[MAXCUR], int b[MAXCUR]){
	int i;
	for(i=0;i<MAXCUR;i++){
		if (a[i] < b[i]) return -1;
		if (a[i] > b[i]) return 1;
	}
	return 0;
}

int *findanswer(double exchange[MAXCUR][MAXCUR], int nCur){
/*
for each row i in current_ans
current_ans[i][j] is the arbitrage sequence from i to j 
if current_ans[i][j]*exchnage[j][i] > 1.01, 
the we find a arbitrage sequenece.

pre[i][j] indicates that, for an arbitrage asequence starting from i,
current_ans[i][j] = current_ans[i][pre[i][j]] * exchange[pre[i][j]][j].
That is, current_ans[i][j] is derived from pre[i][j]
When producing the arbitrage sequence, simply trace pre[i][j].
Initially every pre[i][j] is set to i; 
 

*/
	double current_ans[MAXCUR][MAXCUR];
	double bestanswer;
	int pre[MAXCUR][MAXCUR];
	int answer[MAXCUR][MAXCUR], *min_answer;
	int i,j,k,p,l,m,seqlen,nans;
	double temp_ans[MAXCUR], temp_pre[MAXCUR];
	struct stack ans[MAXCUR][MAXCUR],temp_org[MAXCUR];	
	
	min_answer = (int *) malloc(sizeof(int)*MAXCUR);
	memset(min_answer,-1,sizeof(int)*MAXCUR);
	
	for(i=0;i<MAXCUR;i++){
		for(j=0;j<MAXCUR;j++){
			answer[i][j]=-1;
		}
	}
	
	for(i=0;i<nCur;i++){
		for(j=0;j<nCur;j++){
			current_ans[i][j]=exchange[i][j];
			
			ans[i][j].size=0;
			push(&ans[i][j],i);
			push(&ans[i][j],j);
		}
	}
	
	for(seqlen=2;seqlen<nCur;seqlen++){
	/*
		test arbitrage sequeneces of length seqlen
		note, here a sequence 1,2,1 has length 2

		test if we get the desired arbitrage sequence
	*/
		nans=0;
		for(i=0;i<nCur;i++){
			
			for(j=0;j<nCur;j++){
				if (current_ans[i][j]*exchange[j][i] >= 1.01){
					for(k=0;k<ans[i][j].size;k++){
						answer[nans][k] = ans[i][j].seq[k];
					}
					answer[nans][k]=i;
					nans++;
				}
			}
		}
		if(nans>0) {
			/*refine answer*/
			m=0;
			for(i=0;i<nans;i++){
				if (intcmp(answer[m],answer[i]) > 0){
					m=i;
				}
			}
			for(i=0;i<nCur;i++){
				min_answer[i] =answer[m][i];
			}
			return min_answer;
		}
		
		/*update the sequence for each current_ans[i][j],
		where i is the beginning of an arbitrage sequence
		*/
		for(i=0;i<nCur;i++){
			for(j=0;j<nCur;j++){
				temp_ans[j]=current_ans[i][j];
				stack_copy(&ans[i][j],&temp_org[j]);
				for(k=0;k<nCur;k++){
					if (current_ans[i][k]*exchange[k][j] > temp_ans[j]){
						temp_ans[j]=current_ans[i][k]*exchange[k][j];
						stack_copy(&ans[i][k],&temp_org[j]);
						push(&temp_org[j],j);
						
						if(DEBUG){
							printf("i=%d j=%d k=%d ",i,j,k);
							printf("c_ans[i][k]=%f exchange[k][j]=%f\n",current_ans[i][k], exchange[k][j]);
							printf("c_ans[i][k]*exchange[k][j]=%f\n",current_ans[i][k]*exchange[k][j]);
							printf("temp_ans[j] = %f, temp_pre[j]=%f\n",temp_ans[j],temp_pre[j]=k);
							printf("\n");
						}
						
					}
				}
			}
			for(j=0;j<nCur;j++){
				current_ans[i][j] = temp_ans[j];
				stack_copy(&temp_org[j], &ans[i][j]);				
			}

		}
	}
	return min_answer;
}

void output(int answer[MAXCUR]){
	int i,count;
	i=0;
	count=0;
	
	while(answer[count] != -1){
		count++;
	}

	if (count==0) {
		printf("no arbitrage sequence exists\n");
	}
	else {
		
		for(i=0;i<count;i++){
			
				printf("%d ", answer[i]+1);
			
			
		}
		printf("\n");
	}
	
	
}

int main(int argc, char *argv[]){
	FILE *fp;
	int nCur,i,j;
	double exchange[MAXCUR][MAXCUR];
	float fl;
	char *line, firsttok[MAXCUR];
	
	if(DEBUG){
		fp = fopen("input.txt","r");
		if (NULL == fp) exit(EXIT_FAILURE);
	} 
	else {
		fp =stdin;
	}
	
	
	while(1 == (fscanf(fp,"%d",&nCur))){
		for(i=0;i<nCur;i++){
			
			 
			for(j=0;j<nCur;j++){
				if(i==j) {
					exchange[i][j]=1.0;
				}
				else {
					fscanf(fp,"%f",&fl);
					exchange[i][j] = (double)fl;
				}
			}
		}
		
		
		if(DEBUG) {dumpArray(exchange,nCur);} 
		output(findanswer(exchange,nCur));
	}
	
	return 0;
}