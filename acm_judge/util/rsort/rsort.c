#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 30000

void rsort(unsigned int *,int,int);

void rsort(unsigned int *base, int nelem, int bitpos){
	unsigned int pivot;
	int i,j,k;
	
	if ((bitpos < 0)||(nelem <= 1)) return ;
	
	pivot = (1 << bitpos);
	i = 0;
	j = nelem - 1;
	while(i < j){
		while( (i < nelem ) && ((base[i] & pivot)==0) ){
			i++;
		}
		while( (j>0) && ((base[j] & pivot) > 0)){
			j--;
		}
		if(i < j){
			base[i] = base[i] ^ base[j];
			base[j] = base[i] ^ base[j];
			base[i] = base[i] ^ base[j];
		}
	}

	rsort(base,i,bitpos-1);
	rsort(base+i,nelem-i,bitpos-1); 
}

void rsort2(unsigned int *base, int nelem, int bitpos){
/*OK, but need an auxilary array*/
	unsigned int pivot;
	int i,j,k;
	unsigned int *tmp;
	
	tmp = (unsigned int *) malloc(sizeof(unsigned int)*nelem);
	
	if ((bitpos < 0)||(nelem <= 1)) return ;
	
	pivot = (1 << bitpos);
	i = 0;
	j = nelem - 1;
	for(k=0;k<nelem;k++){
		if ((base[k] & pivot) == 0){
			tmp[i] = base[k];
			i++;
		}
		else{
			tmp[j] = base[k];
			j--;
		}
	}
	for(k=0;k<nelem;k++){
		base[k] = tmp[k];
	}
	free(tmp);
	rsort(base,i,bitpos-1);
	rsort(base+i,nelem-i,bitpos-1); 
}

int main(){
	int i,inc,nNum;
	unsigned int *r;
	unsigned int input;
	struct timespec st,et;
	long int elapse;
	FILE *fp;
	
	fp = fopen("num.txt","r");
	fscanf(fp,"%d",&nNum);	

	
	r = (int *) malloc(sizeof(unsigned int)*nNum);
	
	
	for(i=0;i<nNum;i++){
		fscanf(fp,"%d",r+i);
	}


	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&st);	
	rsort(r,nNum,14);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&et);
	elapse = (et.tv_nsec >= st.tv_nsec)?
		et.tv_nsec - st.tv_nsec : 
		1000000000+et.tv_nsec-st.tv_nsec;

	printf("rsort takes %ld and 0.%ld mini seconds\n",et.tv_sec - st.tv_sec, elapse/1000000);
	
	if(nNum<100){
	for(i=0;i<nNum;i++){
		printf("%5d ",r[i]);
	}
	printf("\n");
	}
	inc=1;
	for(i=0;i<nNum-1;i++){
		
		if(r[i] > r[i+1]){
			inc = 0;
		}
	}
	if(inc){
		printf("Radix Sort Succ!\n");
	}	
	else{
		printf("!!!!!Shit!!!!!\n");
	}
	free(r);
	exit(0);
}