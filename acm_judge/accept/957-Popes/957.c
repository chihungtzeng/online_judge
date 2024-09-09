#include <stdio.h>
#include <stdlib.h>

int main(){
	int nPope;
	int interval;
	int i,j;
	int *eYear;
	int left,right,middle;
	int tYear; /*target*/
	int ansStartYear, ansEndYear,currentAns;
	int max,done,found,idx;
	
	
	while(1 == scanf("%d",&interval)){
		scanf("%d",&nPope);
		eYear = (int *) malloc(sizeof(int)*nPope);
		for(i=0;i<nPope;i++){
			scanf("%d",eYear+i);
		}
		done=0;
		i=0;
		max = 0;
		while(!done){
			
			tYear = eYear[i] + interval - 1;
			if(tYear > eYear[nPope - 1]){
				done = 1;
				continue;
			}
			
			left = i;
			right= nPope - 1;
			found = 0;
			while((left<=right)&&(!found)){
				middle = (left+right) >> 1;
				if(eYear[middle] > tYear){
					right = middle - 1;
				}
				else if (eYear[middle] < tYear){
					left = middle + 1;
				} 
				else{
					found = 1;
				}
			}
			
			idx = (left+right)/2;

			
			while ((idx < nPope -2) && (eYear[idx] == eYear[idx+1]) ){
				idx++;
			}
			
			currentAns = idx - i + 1;
			if(currentAns > max){
				max = currentAns;
				ansStartYear = eYear[i];
				ansEndYear = eYear[idx];
			}
			i++;
		}
		printf("%d %d %d\n",max, ansStartYear, ansEndYear);
		/**/
		
		
		free(eYear);
	}
	return 0;
}