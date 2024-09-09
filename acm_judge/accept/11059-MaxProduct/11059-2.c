#include <stdio.h>
#define MAX 20
#define NINF -1000000000000000000
#define DEBUG 0
char nNum, num[MAX];
short k=1;
long long product[MAX];

long long maxProduct(char nData, char data[]){
	/*data[] contains no zero*/
	long long result = NINF, tmp, down;
	char i, start, end;

	#if 0
	printf("find max product in:");
	for(i=0; i<nData; i++){
		printf("%hhd ", data[i]);
	}
	printf("\n");
	#endif
	
	product[0] = data[0];
	for(i=1; i<nData; i++){
		product[i] = product[i-1]*data[i];
	}
	for(start=0; start < nData; start++){
		down = ((start == 0))? 1 : product[start - 1];
		for(end = start; end < nData; end++){
			
			tmp = product[end] / down;
			if(tmp > result) result = tmp;
		}
	}
	
	return result;
}

long long solve(){
	char start, end;
	long long ans = 0, nRet; 

	#if 0
	char i;
	printf("input:");
	for(i=0; i<nNum; i++){
		printf("%hhd ", num[i]);
	}
	printf("\n");
	#endif

	start = 0;
	if(num[start] == 0){
		do{
			start++;
		} while((num[start] == 0) && (start < nNum));
	}
	while(start < nNum){
		end = start + 1;
		while((num[end] != 0) && (end < nNum)){
			end++;
		}
		
		nRet =  maxProduct(end - start, num + start);
		start = end + 1;
		if(nRet > ans) ans = nRet;
	}
	
	return ans;
}

int main(){
	
	char i;
	long long ans;
	FILE *fp;
	fp = (DEBUG)? fopen("in4.txt", "r") : stdin;
	while(1 == fscanf(fp, "%hhd", &nNum)){
		for(i=0; i<nNum; i++){
			fscanf(fp, "%hhd", num + i);
		}
		ans = solve(nNum, num);
		printf("Case #%hd: The maximum product is %lld.\n\n", k++, ans);
	}
	return 0;
}