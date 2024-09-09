#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#define MAXN 1000000

int gcd(int a, int b){
	if (0 == b) return a;
	else return gcd(b,a%b);
}

int gcd2(int a,int b){
	int temp;
	while (a%b != 0){
		temp = a;
		a = b;
		b = temp%a;
	}
	return b;
}

void find_ans(int n){
	int i,j,a,b,c;
	int x,y,z;
	int astop, bstop;
	int count=0;
	int ans2=0;
	int *flag;
	
	flag=(int *)malloc(sizeof(int)*MAXN);
	memset(flag,-1,sizeof(int)*MAXN);

	for(a=1;a<1000;a++){
		if(a*a>n) break;
		for(b=a+1;b<1000;b++){
			x=b*b-a*a;
			y=(a*b)<<1;
			z=a*a+b*b;
			if(z>n){
				continue;
			}
			if(1 == gcd(x,y)){
				count++;
				c=n/z;
				for(i=1;i<=c;i++){
					flag[i*x] = 1;
					flag[i*y] = 1;
					flag[i*z] = 1;
				}
			}
		}
	} 
	for(i=1;i<=n;i++){
		if(1 == flag[i]) ans2++;
	}
	printf("%d %d\n",count,n-ans2); 
}


int main(int argc, char *argv[]){
	int n;
	FILE *fp;
	char *line;
	
	/*fp = fopen("input.txt","r");*/
	fp = stdin;
	if (NULL == fp){
		exit(EXIT_FAILURE);
	}
	
	line = (char *) malloc(sizeof(char)*10);
	while (NULL !=(fgets(line,10,fp))){
		n = atoi(line);
		find_ans(n);
	}
	exit(EXIT_SUCCESS);
}
