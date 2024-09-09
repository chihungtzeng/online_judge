#include <stdio.h>
#include <stdlib.h>
#define MAXSTEP 101
#define DEBUG 0
#define MYINF 10000000.0


struct pluse{
	float value, start, end;
};

int comparePluseByValue(const void *a, const void *b){
	struct pluse *p1, *p2;
	p1 = (struct pluse *) a;
	p2 = (struct pluse *) b;
	return p1->value - p2->value;
} 

struct pluse f[MAXSTEP], g[MAXSTEP];
double h[2*MAXSTEP];
int nF, nG, nH;


int ifOverlap(float p1, float p2, float q1, float q2){
	if((q1 >= p2) || (q2 <= p1)) return 0;
	else return 1;
}

float rangeQuery(struct pluse *plusefnt, int nelem, float start, float end){
	/*query fx for findint the minimum value in the range [start..end]*/
	float result = MYINF;
	int i;
	for(i=0;i<nelem;i++){
		if( (ifOverlap(plusefnt[i].start, plusefnt[i].end, start, end)) && (plusefnt[i].value < result)){
			result = plusefnt[i].value;
		}
	}
	return result;
}

int main(){
	int i;
	float start, interval, horizon;
	float possibleAns;
	float minf, ming;
	FILE *fp;
	short found;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	
	while(1 == fscanf(fp, "%d", &nF)){
		start = 0.0;
		possibleAns = MYINF;
		for(i=0; i<nF; i++){
			fscanf(fp, "%f %f",&f[i].value, &interval);
			f[i].start = start;
			f[i].end = start + interval;
			
			if(f[i].value < possibleAns){
				possibleAns = f[i].value;
			}
			start = f[i].end;
			
		}		
		fscanf(fp, "%d",&nG);
		start = 0.0;
		for(i=0; i<nG; i++){
			fscanf(fp, "%f %f",&g[i].value, &interval);
			g[i].start = start;
			g[i].end = start + interval;
			start = g[i].end;
			
		}
		/*
		qsort(g, nG, sizeof(struct pluse), comparePluseByValue);
		qsort(f, nF, sizeof(struct pluse), comparePluseByValue);
		*/
		if(DEBUG){
			for(i=0;i<nG;i++){
				printf("(%f %f) -> %f\n",g[i].start, g[i].end, g[i].value);
			}
		}
		
		
		nH = 0;
		for(i=0; i< nG; i++){
			minf = rangeQuery(f, nF, g[i].start, g[i].end);
			if( g[i].value > minf){ 
				h[nH++] = g[i].value;
			}
		}
		for(i=0; i< nF; i++){
			ming = rangeQuery(g, nG, f[i].start, f[i].end);
			if( f[i].value > ming){ 
				h[nH++] = f[i].value;
			}
		}
		horizon = MYINF;
		for(i=0;i<nH;i++){
			if(h[i] < horizon){
				horizon = h[i];
			}
		}
		printf("%.3f\n",horizon);
	}
	
	return 0;
}