#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define LATE 2
#define YOUROWN 3

struct Subject{
	char name[32];
	short dueDay;
};

int compareSubject(const void *a, const void *b){
	struct Subject *x, *y;
	x = (struct Subject *)a;
	y = (struct Subject *)b;
	return strcmp(x->name, y->name);
}



int main(){
	short nTest, k = 1, i, j, nSubject;
	char name[32];
	short due, state;
	struct Subject subject[128], query, *match, *s;
	scanf("%hd",&nTest);
	while(k <= nTest){
		scanf("%hd", &nSubject);
		for(i=0; i<nSubject; i++){
			scanf("%s %hd", subject[i].name, &subject[i].dueDay);			
		}
		qsort(subject, nSubject, sizeof(struct Subject), compareSubject);
		
		scanf("%hd %s", &due, query.name);
		
		/*printf("target=%s due=%hd\n",name, due);*/
		
		match = bsearch(&query, subject, nSubject, sizeof(struct Subject), compareSubject);
		if(match == NULL){
			printf("Case %hd: Do your own homework!\n", k++);			
		}
		else{
			s = (struct  Subject *) match;
			if(s->dueDay <= due){
				printf("Case %hd: Yesss\n",k++);
			}
			else if (s->dueDay <= due + 5){
				printf("Case %hd: Late\n",k++);
			}
			else{
				printf("Case %hd: Do your own homework!\n", k++);
			}
		}
		
		
	}
	
	return 0;
}