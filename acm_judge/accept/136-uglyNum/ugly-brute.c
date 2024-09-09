#include <stdio.h>
#include <stdlib.h>
#define TARGET 1500
#define TRUE 1
#define FALSE 0

int binary_search(int key,int u[],int left, int right){
	int middle;
	
	if(right < left) return FALSE;
	
	middle=(left+right)/2;
	if (u[middle] == key) {
		return TRUE;
	}
	else if (u[middle] > key) {
		return binary_search(key,u,left,middle-1);
	}
	else {
		return binary_search(key,u,middle+1,right);
	}
}

int main(int argc, char **argv){
	int u[TARGET];
	int n,nUgly;
	u[0]=1; u[1]=2; u[2]=3;u[3]=4;u[4]=5;
	nUgly=5;
	n=5;
	while (nUgly < TARGET){
		n++;
		
		if ( 
				((0 == n % 2) && (binary_search(n/2,u,1,nUgly-1) == TRUE)) | 
				((0 == n % 3) && (binary_search(n/3,u,1,nUgly-1) == TRUE)) | 
				((0 == n % 5) && (binary_search(n/5,u,1,nUgly-1) == TRUE)) 
			){
			printf("find %dth ugly number %d\n",nUgly,n);
			u[nUgly] = n;
			nUgly++;
		} 
	}
	printf("The 1500'th ugly number is %d.\n",u[TARGET-1]);
	for(n=0;n<20;n++){
		printf("%d ",u[n]);
	}
}



