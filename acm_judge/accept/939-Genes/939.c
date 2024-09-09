#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <string.h>
#define MAX_RECORD 3100
#define DEBUG 0

enum gene_type {dominant, recessive, non_existent, undecided};

struct person{
	char *name;
	char *parent[2];
	enum gene_type gene; 
};

struct qele{
	struct qele *next;
	struct person *key;
};

/*global variables*/
struct person people[MAX_RECORD];
int nPeople;

struct parenthood{
	char *name;
	char *pname;
};

void person_free(struct person *p){
	if(NULL == p) return ;
	if(NULL != p->name) free(p->name);
	if(NULL != p->parent[0]) free(p->parent[0]);
	if(NULL != p->parent[1]) free(p->parent[1]);
}

struct person *new_person(char *name, char *data){
	struct person *p;
	p = (struct person *) malloc(sizeof(struct person));
	if((NULL == name)||(NULL == data)){
		printf("init person failed: %s %s\n",name,data);
		return NULL;
	}
	p->name = strdup(name);
	if(!strcmp(data,"dominant")){
		p->gene = dominant;
	}
	else if (!strcmp(data,"recessive")){
		p->gene = recessive;
	}
	else if (!strcmp(data,"non-existent")){
		p->gene = non_existent;
	}
	else{
		/*parent name*/
		p->parent[0] = strdup(data);
		p->gene = undecided;
	}
	return p;
}

struct qele *new_qele(struct person *p){
	struct qele *q;
	if (NULL == p) {
		printf("insert null person struct into queue\n");
		return NULL;
	}
	q = (struct qele *) malloc(sizeof(struct qele));
	q->next = NULL;
	q->key = p;
	return q;
}

struct parenthood *new_parenthood(char *cn, char *pn){
	struct parenthood *p;
	p = (struct parenthood *) malloc(sizeof(struct parenthood));
	p->name = strdup(cn);
	p->pname = strdup(pn);
	return p;
}

struct qele *q_insert(struct qele *t, struct person *p){
	struct qele *newq;
	if (NULL == p) return;
	if (NULL == t){
		t = new_qele(p);
	}
	else{
		newq = new_qele(p);
		t->next = newq;
		t = newq;
	}
	return t;
}



void print_person(struct person *p){
	if(NULL != p){
		printf("%s (%s %s) %d\n",p->name,p->parent[0],p->parent[1],p->gene);
	}
}
void print_queue(struct qele *head){
	struct qele *tmp;
	tmp = head;
	while(NULL != tmp){
		print_person(tmp->key);
		tmp = tmp->next;
	}
}

int compare_string(const void *s1, const void *s2){
	char *t1, *t2;
	t1 = (char *)s1;
	t2 = (char *)t2;
	return strcmp(t1,t2);
}

int compare_person(const void *p1, const void *p2){
	struct person *t1, *t2;
	t1 = (struct person *)p1;
	t2 = (struct person *)p2;
	return strcmp(t1->name,t2->name);
}

int compare_parenthood(const void *s1, const void *s2){
	struct parenthood *p1, *p2;
	int result;
	p1 = (struct parenthood *)s1;
	p2 = (struct parenthood *)s2;
	if ((NULL == p1)||(NULL == p2)){
		printf("null parenthood\n");
	 	return 0;
	}
	if ((NULL == p1->name) || (NULL == p2->name) || (NULL == p1->pname) || (NULL == p2->pname)){
		printf("null name in parenthood\n");
		printf("p1->name: %s\n",p1->name); 
		printf("p1->pname: %s\n",p1->pname);
		printf("p2->name: %s\n",p2->name);
		printf("p2->pname: %s\n",p2->pname);
		return -1;
	}
	return strcmp(p1->name,p2->name);

}

void action(const void *nodep,const VISIT which,const int depth){
	struct person *p,*p2;
	p = *(struct person **) nodep;
	if ((preorder == which)||(leaf == which)){
		if (DEBUG) {printf("%s %d\n",p->name,p->gene);}
		people[nPeople].name = strdup(p->name);
		people[nPeople].gene = p->gene;
		nPeople++;
	} 
}

int main(){
	int nPeople_undecided,nRecord;
	struct parenthood phood[MAX_RECORD];
	void *root,*list_of_people;
	struct qele *head,*tail,*tmp;
	struct person *p,*match1,*match2,*ptmp1,*ptmp2;
	
	char s_in1[21], s_in2[21];
	char *s;
	int i;
	FILE *fp;
	
	if (DEBUG){
		fp = fopen("input.txt","r");
	}
	else{
		fp = stdin;
	}
	head = NULL;
	tail = NULL;
	root = NULL;
	nPeople_undecided = 0;
	fscanf(fp,"%d",&nRecord);
	while(1 <= nRecord ){
		nRecord--;
		fscanf(fp,"%s %s",s_in1, s_in2);
		/*if gene is recessive, or dominant or non-existent
			insert the person into the tree; 
		*/		
		if( (!strcmp(s_in2,"dominant")) || 
			(!strcmp(s_in2,"recessive")) || 
			(!strcmp(s_in2,"non-existent"))){
			p = new_person(s_in1, s_in2);
			if(DEBUG) printf("insert %s with gene %s into the tree\n",s_in1,s_in2);
			tsearch((void *)p,&root,compare_person);
		}
		else {
			/*The gene of the person is to be decieded*/
			phood[nPeople_undecided].name = strdup(s_in2);
			phood[nPeople_undecided].pname = strdup(s_in1);
			nPeople_undecided++;		
		}
	}
	if(nPeople_undecided % 2 != 0){
		printf("wrong input\n");
		exit(EXIT_FAILURE);
	}
	qsort(phood,nPeople_undecided,sizeof(struct parenthood),compare_parenthood);
	if(DEBUG){
		printf("--- parenthood---\n");
		for(i=0;i<nPeople_undecided;i++){
			printf("%s with parent %s\n",phood[i].name,phood[i].pname);
		}
	}
	for(i=0;i<nPeople_undecided;i++){
		p = new_person(phood[i].name,phood[i].pname);
		p->parent[1] = strdup(phood[i+1].pname);
		i++;
		if(NULL == tail){
			tail = q_insert(tail,p);
			head = tail;
		}
		else {
			tail = q_insert(tail,p);
		}
		
	}
	
	/*print_queue(head);*/
	/*free parenthood
	for(i=0;i<nPeople_undecided;i++){
		free(phood[i]->name);
		free(phood[i]->pname); 
	}
	*/

	
	while(NULL != head){
		tmp = head;
		p = head->key;		
		head = head->next;
		free(tmp);
		ptmp1 = new_person(p->parent[0],"t");
		
		match1 = *(struct person **) tsearch((void *)ptmp1,&root,compare_person);
		if(match1 == ptmp1){
			tdelete((void *)ptmp1,&root,compare_person);
			tail = q_insert(tail,p);
			person_free(ptmp1);
			
			continue;
		}
		ptmp2 = new_person(p->parent[1],"t");
		match2 = *(struct person **) tsearch((void *) ptmp2,&root,compare_person);
		if(match2 == ptmp2){
			tdelete((void *)ptmp2,&root,compare_person);
			tail = q_insert(tail,p);
			person_free(ptmp1);
			person_free(ptmp2);
			continue;
		}


		if(dominant == match1->gene){
			p->gene = ((dominant == match2->gene)|| (recessive == match2->gene))?
				dominant : recessive;
		}
		else if (recessive == match1->gene){
			if (dominant == match2->gene){
				p->gene = dominant;
			}
			else if (recessive == match2->gene){
				p->gene = recessive;
			}
			else if (non_existent == match2->gene){
				p->gene = non_existent;
			}
		}
		else if (non_existent == match1->gene){
			p->gene = (dominant == match2->gene)? recessive : non_existent;
		}
		tsearch(p,&root,compare_person);

	}
	nPeople=0;
	twalk(root,action);
	tdestroy(root,person_free);
	
	qsort(people,nPeople,sizeof(struct person),compare_person);
	for(i=0;i<nPeople;i++){
		switch(people[i].gene){
			case dominant:
				printf("%s %s\n",people[i].name,"dominant");
				break;
			case recessive:
				printf("%s %s\n",people[i].name,"recessive");
				break;
			default:
				printf("%s %s\n",people[i].name,"non-existent");
				break;
		}
	}
	

	return 0;
}