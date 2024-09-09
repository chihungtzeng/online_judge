#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100001
#define END NULL

struct Node {
	char ch;
	struct Node *next, *pre;
};

struct Node *newNode(char c){
	struct Node *node;
	node = (struct Node *) malloc(sizeof(struct Node));
	node->ch = c;
	node->pre = NULL;
	node->next = NULL;
	return node;
}

void freeNode(struct Node *head){
	struct Node *tmp;
	while(head != NULL){
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


void addChar(char ch, struct Node **head, struct Node **tail, struct Node **cur){
	struct Node *node;
	node = newNode(ch);
	if(cur == head){
		node->next = *head;
		(*head)->pre = node;
		*head = node;	
	} else if (cur == END){
		(*tail)->next = node;
		node->pre = *tail;
		*tail = node;
	} else{
		node->pre = (*cur)->pre;
		node->next = *cur;
		(*cur)->pre->next = node;
		(*cur)->pre = node;
	}
	
}

void output(struct Node *head){
	struct Node *node;
	char outline[LEN];
	size_t len = 0;
	node = head;
	while((node != NULL)){
		if(node->ch != '\0'){
			outline[len++] = node->ch;
		}
		node = node->next;
	}
	outline[len] = '\0';
	puts(outline);
}

void solve(char line[]){
	struct Node *head, *tail, *cur;
	struct Node *node;
	char *ch;
	head = newNode('\0');
	tail = head;
	cur = head;
	ch = line;
	while(*ch != '\0'){
		switch (*ch){
			case '[':
			cur = head;
			break;
			
			case ']':
			cur = END;
			break;
			
			default:
			node = newNode(*ch);
			if(cur == head){
				node->next = head;
				head->pre = node;
				head = node;	
			} else if (cur == END){
				tail->next = node;
				node->pre = tail;
				tail = node;
			} else{
				node->pre = cur->pre;
				node->next = cur;
				cur->pre->next = node;
				cur->pre = node;
			}
			break;
		}
		ch++;
	}
	output(head);
}

int main(){
	char line[LEN];
	FILE *fp = stdin;
	
	while(1 == fscanf(fp, "%s", line)){
		solve(line);
	}	
	return 0;
}