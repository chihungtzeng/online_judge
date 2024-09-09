#include <stdio.h>
#include <stdlib.h>
#define MAX 51
#define DEBUG 0

int main(){
	long int f[MAX];
	long int choose[MAX][MAX];
	int i,j,done;
	int input;
	int x,y;
	int m,n;
	
	FILE *fp;
	
	for(m=0;m<MAX;m++){
		choose[m][0] = 1;
	}
	for(m=0;m<MAX;m++){
		for(n=m+1;n<MAX;n++){
			choose[m][n] = 0;
		}
	}

	for(m=1;m<MAX;m++){
		for(n=0;n<=m;n++){
			choose[m][n] = choose[m-1][n]+choose[m-1][n-1];
		}
	}	
	
	
	f[0] = 0;
	f[1] = 1;
	f[2] = 2;
	f[3] = 3;
	for(i=4; i< MAX; i++){
	/* 
		x + 2*y = i
		for all possible x,y -> sum (choose(x+y,x))
	*/
		
		f[i] = 0;
		for(y=0;y<=i/2;y++){
			x = i - 2*y;
			f[i] = f[i] + choose[x+y][x];
		}

		
	}
	if(DEBUG){
		for(i=0;i<MAX;i++){
			printf("%ld ", f[i]);
		}
		printf("--------------\n");
	}
	
	
	
	if(DEBUG){
		fp = fopen("in.txt","r");
		if(fp == NULL) {
			printf("open file failed\n");
		}
	}
	else {
		fp =stdin;
	}
	done = 0;
	while(1==fscanf(fp,"%d",&input)&& (!done)){
		if (0 == input){ 
			done = 1;
		}
		else {
			printf("%ld\n",f[input]);
		}
	}
	return 0;
}
