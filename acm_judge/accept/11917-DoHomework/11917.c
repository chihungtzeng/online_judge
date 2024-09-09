#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
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

struct Subject *newSubject(char *name, short due){
	struct Subject *s;
	s = (struct Subject *) malloc(sizeof(struct Subject));
	strcpy(s->name, name);
	s->dueDay = due;
	return s;
}

int main(){
	short nTest, k = 1, i, j, nSubject;
	char name[32];
	short due, state;
	void *root, *match;
	struct Subject *s;
	scanf("%hd",&nTest);
	while(k <= nTest){
		root = NULL;
		scanf("%hd", &nSubject);
		for(i=0; i<nSubject; i++){
			scanf("%s %hd", name, &due);
			s = newSubject(name, due);
			
			tsearch(s, &root, compareSubject);
		}
		scanf("%hd %s", &due, name);
		/*printf("target=%s due=%hd\n",name, due);*/
		s = newSubject(name, 0);
		match = tfind(s, &root, compareSubject);
		if(match == NULL){
			printf("Case %hd: Do your own homework!\n", k++);			
		}
		else{
			s = *(struct  Subject **) match;
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
		
		tdestroy(root, free);
	}
	
	return 0;
}