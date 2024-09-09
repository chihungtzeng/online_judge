#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 0

void printArray(int *f, int s){
	int i;
	for(i=0;i<s;i++){
		printf("%d ",f[i]);
	}
	printf("\n");
}

int max(int a, int b){
	if (a<b) return b;
	if (a>b) return a;
	return a;
}

void lcs(int *s1,int *s2,int n){
	int **t;
	int i,j,tmp;	
	
	t = (int **)malloc(sizeof(int *)*(n+1));
	for(i=0;i<=n;i++){
		t[i] = (int *) malloc(sizeof(int)*(n+1));
	}
	
	t[0][0] = 0;
	for(i=1;i<=n;i++){
		t[0][i] = 0;
		t[i][0] = 0;
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(s1[i-1] == s2[j-1]){
				t[i][j] = t[i-1][j-1]+1;
			}
			else {
				t[i][j] = max(t[i-1][j], t[i][j-1]);  
			}
		}
	}
	if (DEBUG) {printArray(s1,n);}
	printf("%d\n",t[n][n]);
	if (DEBUG) {
		printArray(s2,n);
		printf("\n");
	}
	for(i=0;i<=n;i++){
		free(t[i]);
	}
	free(t);
}

int main(int argc, char *argv[]){
	int i,n,len,tmp;
	int *s0,*s1,*s2;
	char *line;
	
	line = (char *) malloc(sizeof(char)*1024);
	
	while(scanf("%d",&n)==1){
		s0 = (int *) malloc(sizeof(int)*n);
		s1 = (int *) malloc(sizeof(int)*n);
		s2 = (int *) malloc(sizeof(int)*n);
		tmp = 0;
		for(i=0;i<n;i++){
			scanf("%d",&tmp);
			s1[tmp-1] = i+1; 
		}
		/*
		for(i=0;i<n;i++){
			s1[s0[i]-1] = i+1;
		}
		*/
		
				
		while(1 == scanf("%d",&tmp)){
			s2[tmp-1] = 1;
			for(i=1;i<n;i++){
				scanf("%d",&tmp);
				s2[tmp-1] = i + 1;
			}
			
			lcs(s1,s2,n);	
		}
		
		

	}
	exit(0);
}