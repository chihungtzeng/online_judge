#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	if(a<b) return b;
	else return a;
}

int main(){
	short nTest;
	int i, middle, mintime, maxtime;
	int leftest, rightest, middleleft, middleright;
	int *pos;
	int pole, nAnt;
	scanf("%hd", &nTest);
	
	pos = (int *) malloc(sizeof(int)*1000001);
	while(nTest >= 1){
		nTest--;
		scanf("%d %d", &pole, &nAnt);
		middle = pole / 2;
		
		leftest = pole;
		middleleft = 0;
		middleright = pole;
		rightest = 0;
		for(i=0; i<nAnt; i++){
			scanf("%d", pos + i);
		}
		for(i=0; i<nAnt; i++){
			if(pos[i] < leftest) leftest = pos[i];
			if(pos[i] > rightest) rightest = pos[i];
			if((pos[i] <= middle) && (pos[i] > middleleft)) middleleft = pos[i];
			if((pos[i] >= middle) && (pos[i] < middleright)) middleright = pos[i];
		}			
		mintime = max(middleleft, pole - middleright);
		maxtime = max(pole - leftest, rightest);
		printf("%d %d\n", mintime, maxtime);
	}
	free(pos);
	return 0;
}