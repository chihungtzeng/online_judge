#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 0
#define MAXC 120
#define MAXCNAME 21
#define WHITE 0
#define BLACK 1

struct course {
	unsigned short sn;
	char cname[MAXCNAME];
	unsigned short isSource;	
	unsigned short nPre;
	unsigned short pre[MAXC];
	unsigned short nNext;
	unsigned short next[MAXC];
	unsigned short min_nDep;
	unsigned short min_dep[MAXC];
	
	unsigned short ancestor[MAXC];
	unsigned short nAncestor;
};

int nCourse, nPrerequisite;
struct course cSet[MAXC];



int compareCourse(const void *a, const void *b){
	struct course *c1, *c2;
	c1 = (struct course *) a;
	c2 = (struct course *) b;
	return strcmp(c1->cname, c2->cname);
}

int compareUShort(const void *a, const void *b){
	return *(unsigned short *)a - *(unsigned short *)b; 
}

int compareCourseBySn(const void *a, const void *b){
	struct course *c1, *c2;
	c1 = (struct course *) a;
	c2 = (struct course *) b;
	return c1->sn - c2->sn;
}

void toposort(unsigned short *trank){
	unsigned short i,j, target, cur, head, tail;	
 	unsigned short indegree[MAXC];
	
	
	if(!trank){
		printf("sinklist not initialized\n");
		return ;
	}
	memset(indegree, 0, sizeof(unsigned short)*MAXC);
	for(i=0;i<nCourse;i++){
		for(j=0; j<cSet[i].nNext; j++){
			target = cSet[i].next[j];
			indegree[target]++;
		}
	}
	head = 0;
	tail = 0;
	for(i=0;i<nCourse;i++){
		if(indegree[i] == 0){
			trank[tail++] = i;
		}
	}
	while(head < tail){
		cur = trank[head++];
		for(j=0;j<cSet[cur].nNext;j++){
			target = cSet[cur].next[j];
			indegree[target]--;
			if(indegree[target] == 0){
				trank[tail++] = target;
			}
		}
	}
	if(DEBUG){
		printf("topo sort:");
		for(i=0; i<tail; i++){
			printf("%d ", trank[i]);
		}
		printf("\n");
	}
}

void findAncestor(unsigned short *trank){
	unsigned short tmpArray[MAXC*2];
	unsigned short nTmp;
	unsigned short i,j,k;
	unsigned short cur, target, idx;
	
	for(i = 0; i<nCourse; i++){
		cur = trank[i];
		nTmp = 0;
		for(j = 0; j < cSet[cur].nPre; j++){
			target = cSet[cur].pre[j];
			memcpy(tmpArray + nTmp, cSet[target].ancestor, sizeof(unsigned short)*cSet[target].nAncestor);
			nTmp += cSet[target].nAncestor;
			tmpArray[nTmp++] = target;
			qsort(tmpArray, nTmp, sizeof(unsigned short), compareUShort);
			idx = 1;
			for(k=1;k<nTmp;k++){
				if(tmpArray[k] != tmpArray[k-1]){
					tmpArray[idx++] = tmpArray[k];
				}
			}
			nTmp = idx;
		}
		memcpy(cSet[cur].ancestor, tmpArray, sizeof(unsigned short)*nTmp);
		cSet[cur].nAncestor = nTmp;
	}	
}

void findAns(){
	unsigned short trank[MAXC];
	unsigned short i, j, k, matchCount;
	unsigned short *match, key, target;
	

	toposort(trank);
	findAncestor(trank);
	if(DEBUG){
		for(i=0; i<nCourse; i++){
			printf("ancestor of %d: ",cSet[i].sn);
			for(j=0;j<cSet[i].nAncestor;j++){
				printf("%d ",cSet[i].ancestor[j]);
			}
			printf("\n");
		}
	}
	for(i=0;i<nCourse;i++){
		for(j=0;j<cSet[i].nPre;j++){
			key = cSet[i].pre[j];
			matchCount = 0;
			for(k=0; k<cSet[i].nPre;k++){
				target = cSet[i].pre[k];
				match = bsearch(&key, cSet[target].ancestor, 
					cSet[target].nAncestor, sizeof(unsigned short), compareUShort);
				if(match){
					matchCount++;
				}
			}
			if(matchCount == 0){
				cSet[i].min_dep[cSet[i].min_nDep++] = key;
			}
		}
		qsort(cSet[i].min_dep, cSet[i].min_nDep, sizeof(unsigned short), compareUShort);
	}
}

int main(){
	int nTest;
	char cname[MAXCNAME];
	struct course *match, ctmp;
	
	int i, j;
	int curSn, nDep, target;
	FILE *fp;
	
				
	if(DEBUG){
		fp = fopen("in2.txt","r");
	}
	else{
		fp = stdin;
	}
	
	fscanf(fp, "%d",&nTest);
	while(nTest >= 1){
		memset(cSet, 0, sizeof(struct course)*MAXC);
		fscanf(fp, "%d", &nCourse);
		
		
		for(i=0; i<nCourse; i++){
			fscanf(fp, "%s", cname);
			strcpy(cSet[i].cname, strdup(cname));
		}
		qsort(cSet, nCourse, sizeof(struct course), compareCourse);
		for(i=0;i<nCourse; i++){
			cSet[i].sn = i;
			cSet[i].isSource = 1;
			cSet[i].min_nDep = 0;
		}		
		/*start to scan the prerequisite tree*/
		fscanf(fp, "%d", &nPrerequisite);
		for(i=0; i<nPrerequisite; i++){
			fscanf(fp, "%s", cname);
			strcpy(ctmp.cname, cname);
			match = (struct course *) bsearch(&ctmp, cSet, nCourse, sizeof(struct course), compareCourse);
			
			if(match){
				curSn = match->sn;
				cSet[i].isSource = 0;
			}
			else {
				if(DEBUG) {
					printf("No such course: %s\n",cname);
				}
				exit(0);
			}
			fscanf(fp, "%d", &nDep);
			for(j = 0; j < nDep; j++){
				fscanf(fp, "%s", cname);
				strcpy(ctmp.cname, cname);
				match = (struct course *) bsearch(&ctmp, cSet, nCourse, sizeof(struct course), compareCourse);
				
				if(match){
					int predecessor;
					predecessor =  match->sn;
					cSet[curSn].pre[cSet[curSn].nPre++] = predecessor;
					cSet[predecessor].next[cSet[predecessor].nNext++] = curSn;
				}
			}
			
		}
		/*End of reading input*/
		if(DEBUG){
			for(i=0;i<nCourse;i++){
				printf("course %d (%s) depends on: ",cSet[i].sn, cSet[i].cname);
				for(j = 0 ;j < cSet[i].nPre; j++){
					printf("%d ", cSet[ cSet[i].pre[j] ].sn);
				}
				printf("\n");
			}		
			for(i=0;i<nCourse;i++){
				printf("course %d (%s) points to: ",cSet[i].sn, cSet[i].cname);
				for(j = 0 ;j < cSet[i].nNext; j++){
					printf("%d ", cSet[ cSet[i].next[j] ].sn);
				}
				printf("\n");
			}		
		}
		
		
		findAns();
		
		for(i=0; i< nCourse; i++){
			if(cSet[i].min_nDep > 0){
				printf("%s %d", cSet[i].cname, cSet[i].min_nDep);
				for(j = 0; j < cSet[i].min_nDep; j++){
					target = cSet[i].min_dep[j];
					printf(" %s", cSet[target].cname);
				}
				printf("\n");
			}
		}
		nTest--;
	}	
	


	return 0;	
}