#include <stdio.h>
#include <stdlib.h>
#define DEBUG 0
#define NR 500

int partition(int pivot,int *arr, int nelem){
	int i, j;
	i = 0;
	j = nelem - 1;

	while (i < j){
		while((i < nelem) && (arr[i] <= pivot)){ i++;}
		while((j > 0) && (arr[j] > pivot)) { j--;}
		if(i < j){
			arr[i] = arr[i] ^ arr[j];
			arr[j] = arr[i] ^ arr[j];
			arr[i] = arr[i] ^ arr[j];
		}
	}
	return i;
}

int find_kth(int *base, int nelem, int k){
	int rsep,lsep,pivot;

	if ( nelem == 1){
		return base[0];
	}

	pivot = base[0];
	rsep = partition(pivot, base, nelem);
	lsep = partition(pivot - 1, base, rsep);

	
	
	/*base[0..lsep-1] <pivot, 
		base[lsep..rsep-1]==pivot
		base[rsep..nelem-1] > pivot
		*/
	if ( k < lsep ){
		return find_kth(base, lsep, k);
	}
	else if ((k >= lsep) &&(k < rsep)){
		return pivot; 
		
	}
	else{
		return find_kth(base + rsep, nelem - rsep , k - rsep );
	}
}


int main(){
	int r[NR];
	int nTest,nR,i,sep,target;
	int median,middle,done;
	long int dist;
	int left,right;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in4.txt","r") : stdin;
	
	fscanf(fp,"%d",&nTest);
	while(1 <= nTest){
		nTest--;
		
		fscanf(fp,"%d",&nR);
		for(i=0;i<nR;i++){
			fscanf(fp,"%d",r+i);
		}
		middle = nR/2;
		median = find_kth(r,nR,middle);
		dist = 0;
		/*
		for(i=0;i<nR;i++){
			dist += (median > r[i])? median - r[i] : r[i] - median;
		}*/
		for(i=middle+1;i<nR;i++){
			dist += r[i] - median;
		}
		for(i=0;i<middle;i++){
			dist += median - r[i]; 
		}

		
		/*printf("median: %d\n",median);*/
		printf("%ld\n",dist);
	} 
	
	return 0;
}
