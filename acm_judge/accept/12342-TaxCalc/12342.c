#include <stdio.h>


double rate[] = {0.1, 0.15, 0.20};
int gap[] = {300000, 400000, 300000};

#if 0
long long calcTax(int income){
	long long remain;
	long long result = 0;
	long long curTax;
	
	int i;
	if(income <= 180000) return 0;
	
	remain = income - 180000; 
	for(i=0; (i<3) && (remain > 0); i++){
		curTax = (remain > gap[i])? gap[i] : remain;
		curTax = (curTax * rate[i]) / 100;
		result += curTax;
		remain -= gap[i];
	} 
	if(remain > 0){
		result += (remain / 4);
	}
	
	if(result < 2000) result = 2000;
	return result;
}
#endif

#if 1
int calcTax(int income){
	double remain;
	double result = 0;
	int finalTax;
	int i;
	if(income <= 180000) return 0;
	
	remain = income - 180000; 
	for(i=0; (i<3) && (remain > 0); i++){
		result += (remain > gap[i])? gap[i]*rate[i] : remain *rate[i];
		remain -= gap[i];
	} 
	if(remain > 0){
		result += remain * 0.25;
	}
	finalTax = (int) result;
	if(result - finalTax > 0) finalTax++;
	
	if(finalTax < 2000) finalTax = 2000;
	return finalTax;
}
#endif

int main(){
	int nTest;
	int income;
	int tax;
	int k=1;
	scanf("%d", &nTest);
	while(nTest--){
		scanf("%d", &income);
		tax = calcTax(income);
		printf("Case %d: %d\n", k++, tax);
	}
	return 0;
}