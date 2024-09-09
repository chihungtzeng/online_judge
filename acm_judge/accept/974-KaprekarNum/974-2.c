#include <stdio.h>

int main(){
	int nInput,nTest;
	int ll,rr,left,right;
	int i;
	int nAns;
	int ans[20];
	int xxx[] = {9, 45, 55, 99, 297, 703, 999, 2223, 2728, 4879, 4950, 5050, 5292, 7272, 7777, 9999, 17344, 22222, 38962};
	FILE *fp;
	
	fp = stdin;

	
	fscanf(fp,"%d",&nInput);
	nTest = 1;
	while(nTest <= nInput){
		printf("case #%d\n",nTest);
		nTest++;
		fscanf(fp,"%d %d",&ll,&rr);
		if(ll<rr){
			left = ll;
			right = rr;
		}
		else{
			left=rr;
			right=ll;
		}
		
		nAns=0;
		for(i=0;i<19;i++){
			if((xxx[i] >= left)&&(xxx[i]<=right)){
				ans[nAns] = xxx[i];
				nAns++;
			}
		}
		if(nAns == 0){
			printf("no kaprekar numbers\n");
		}
		else{
			for(i=0;i<nAns;i++){
				printf("%d\n",ans[i]);
			}
		}
		if(nTest <= nInput){
			printf("\n");
		}
	}
	return 0;
}