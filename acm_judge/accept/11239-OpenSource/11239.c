#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <search.h>
#define LEN 512

struct Student{
	char name[128];
	char doubleProject;
	char pName[128];
};

struct Project{
	char pName[128];
	short nMember;
};

struct Project proj[101];
char nProj = 0;

struct Student *newStudent(char name[], char pName[]){
	struct Student *s;
	s = calloc(1, sizeof(struct Student));
	strcpy(s->name, name);
	strcpy(s->pName, pName);
	return s;
}

int compareStudent(const void *a, const void *b){
	struct Student *x, *y;
	x = (struct Student *)a;
	y = (struct Student *)b;
	return strcmp(x->name, y->name);
}


int compareProjectByName(const void *a, const void *b){
	struct Project *x, *y;
	x = (struct Project *)a;
	y = (struct Project *)b;
	return strcmp(x->pName, y->pName);
}

int compareProjectByDefault(const void *a, const void *b){
	struct Project *x, *y;
	x = (struct Project *)a;
	y = (struct Project *)b;
	if(x->nMember != y->nMember) return y->nMember - x->nMember;
	else return strcmp(x->pName, y->pName);
}


void twalkAction(const void *rootp, const VISIT which, const int depth){
	struct Student *s;
	struct Project *p, query;
	
	if ((which == leaf) || (which == postorder)){
		s = *(struct Student **)rootp;
		if(!s->doubleProject){
			strcpy(query.pName, s->pName);
			p = (struct Project *) bsearch(&query, proj, nProj, sizeof(struct Project), compareProjectByName);
			p->nMember += 1;
		}
	}
}

void solve(void *sroot){
	short i;
	qsort(proj, nProj, sizeof(struct Project), compareProjectByName);
	twalk(sroot, twalkAction);
	qsort(proj, nProj, sizeof(struct Project), compareProjectByDefault);
	for(i=0; i<nProj; i++){
		printf("%s %hd\n", proj[i].pName, proj[i].nMember);
	}
}


int main(){
	char line[LEN];
	int len;
	FILE *fp = stdin;
	char pName[128], sname[128];
	void *sroot = NULL, *match;
	struct Student *student, *smatch;
	struct Proejct *project;
	while(fgets(line, LEN, fp)){
		if(line[0] == '0'){
			return 0;
		}
		else if (line[0] == '1'){
			twalk(sroot, twalkAction);
			solve(&sroot);
			tdestroy(sroot, free);
			nProj = 0;
			sroot = NULL;
			
		}
		else if (isupper(line[0])){
			len = strlen(line);
			line[len - 1] = '\0';
			strcpy(pName, line);
			strcpy(proj[nProj].pName, pName);
			proj[nProj].nMember = 0;
			nProj++;
		}
		else if (islower(line[0])){
			len = strlen(line);
			line[len - 1] = '\0';
			strcpy(sname, line);
			student = newStudent(sname, pName);
			match =  tsearch(student, &sroot, compareStudent);
			if(*(struct Student **) match != student){
				free(student);
				student = *(struct Student **) match;
				if(strcmp(student->pName, pName)){
					student->doubleProject = 1;
				}
			}
		}
	}
	return 0;
}