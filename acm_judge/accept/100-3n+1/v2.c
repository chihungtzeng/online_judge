#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<math.h>
#define MAX_LINE_LEN 1000
#define UB 1000001

void parseLine(int *start, int *end, char *line){
	char *tmp;
	
	tmp = (char *)malloc(sizeof(char)*MAX_LINE_LEN);
	strcpy(tmp,line);
	*start = atoi(strtok(tmp," "));
	*end = atoi(strtok(NULL, " "));
	
}

int find_cyclen(int n, int cyclen[]){
	int i,step;
	long long int x;
	if (n >= UB){
		x = n;
		step = 1;
		do {
			if (0 == x % 2) {
				step++;
				x=x/2;
			}
			else {
				step+=2;
				x=x+1 + (x >> 1);
			}			 
		}
		while (x > 1);
		return step;
	}
	if (-1 != cyclen[n]) return cyclen[n];
	else if (0 == n % 2) {
		i = find_cyclen(n/2,cyclen);
	}
	else {
		i = find_cyclen(3*n + 1, cyclen);
	}
	cyclen[n] = i+1;
	return cyclen[n];
}

int find_max_cyclen(int start, int end, int cyclen[]){
	int max=0,i,tmp;
	for (i=start; i<=end; i++){
		tmp = find_cyclen(i, cyclen);
		if (tmp > max) max = tmp;
	}
	return max;
}

int main(int argc, char *argv[]){
	FILE *fp;
	char *line;
	int cyclen[UB];
	int start,end,i;
	int left,right;	
	
	
	/*fp = fopen("3n+1.input","r");*/
	fp = stdin;
	if (NULL == fp) {
		printf("Open file failed\n");
		exit(EXIT_FAILURE);
	}
	for(i=2;i<UB;i++){
		cyclen[i] = -1;
	}
	cyclen[1]=1;


	line = (char *)malloc(sizeof(char)*MAX_LINE_LEN);
	while (NULL != (fgets(line,MAX_LINE_LEN,fp))){
		parseLine(&start, &end, line);
		if (start <= end){
			left = start;
			right = end;
		}
		else{
			left = end;
			right=start;
		}

		printf("%d %d %d\n",start,end,find_max_cyclen(left,right,cyclen));
	}
	return 0;
}