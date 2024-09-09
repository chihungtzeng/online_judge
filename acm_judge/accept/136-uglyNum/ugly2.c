#include <stdio.h>
#include <stdlib.h>

struct node{
	long int value;
	struct node *next;
};

struct node *findtail(struct node *s){
	struct node *tail;
	tail = s;
	if(tail == NULL) {
		printf("shit!\n");
		exit(EXIT_FAILURE);
	}
	while (tail->next != NULL) {
		tail = tail->next;
	}
	return tail;
}

void printlist(struct node *s){
	struct node *t;
	t=s;
	while(t!=NULL){
		printf("%ld ", t->value);
		t = t->next;
	} 
}

int listlen(struct node *list){
	int n=0;
	struct node *t;
	t=list;
	while (t != NULL ){
		n++;
		t = t->next;
	}
	return n;
}

long int find1500(struct node *list){
	struct node *t;
	int n=1;
	t = list;
	while( (t != NULL) && (n<1500)){
		t= t->next;
		n++;
	}
	if(n<1500) return n;
	return t->value;
}

struct node *multiplylist(struct node *scr, int m){
	struct node *output,*t,*pre,*cur;
	t = scr;
	
	if(t!=NULL){
		output = (struct node *)malloc(sizeof(struct node));
		output->value = t->value * m;
		output->next = NULL;
		pre = output;
		t = t->next;
	}
	while(t!=NULL){
		cur = (struct node *)malloc(sizeof(struct node));
		cur->value = t->value * m;
		cur->next = NULL;
		pre->next = cur;
		pre=cur;
		t = t -> next;
	}
	return output;
}

struct node *insert2list(struct node *scr, struct node *new_element){
	struct node *tail;
	
	if (NULL == scr){
		scr = new_element;
		new_element -> next = NULL;
		return scr;
	}
	tail = findtail(scr);
	tail->next = new_element;
	new_element->next = NULL;
	return scr;
}



struct node *mergelist(struct node *s1, struct node *s2){
	struct node *t1, *t2, *tmp, *output;
	t1 = s1;
	t2 = s2;

	output = NULL;
	while ((t1 != NULL) && (t2 != NULL)){
		if (t1->value < t2->value){
			tmp = t1->next;
			output=insert2list(output,t1);
			t1 = tmp;
		}
		else if (t1-> value == t2->value){
			t1=t1->next;
		}
		else {
			tmp = t2->next;
			output=insert2list(output,t2);
			t2 = tmp;
		}
			
	}
	tmp = findtail(output);
	tmp->next = t1;
	tmp = findtail(tmp);
	tmp->next = t2;
	tmp = findtail(tmp);
	tmp->next = NULL;
	
		
	
	return output;
}



int main(int argc, char **argv){
	struct node *currentlist, *newlist;
	struct node *newlist2, *newlist3, *newlist5;
	struct node *tmplist;
	long int pre,cur;
	int done=0;
	
	currentlist = (struct node *) malloc(sizeof(struct node));
	currentlist -> next = NULL;
	currentlist -> value = 1;
	
	newlist = (struct node *) malloc(sizeof(struct node));
	newlist -> next = NULL;
	newlist -> value = 1;
	
	

	pre = -1;
	while (!done){
		

		newlist2 = multiplylist(newlist,2);
		newlist3 = multiplylist(newlist,3);
		newlist5 = multiplylist(newlist,5);
		
		
		tmplist = mergelist(newlist2,newlist3);
		newlist = mergelist(tmplist, newlist5);
		tmplist = mergelist(currentlist,newlist);
		cur = find1500(currentlist);
		if(cur == pre){
			done = 1;
		}
		currentlist=tmplist;
		pre=cur;
	}
	
	
	printf("The 1500'th ugly number is %ld.\n",cur);
	exit(0);
}