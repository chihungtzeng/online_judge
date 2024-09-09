#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 0
#define MAX 10000
#define OPERATOR 1
#define NUMBER 0

struct stack{
	long ele[20];
	int head;
};

int push(struct stack *s, long e){
	s->ele[s->head++] = e;
	return 0;
}

long pop(struct stack *s){
	if(s->head < 0){
		printf("stack is empty");
	}
	s->head -= 1;
	return s->ele[s->head];
}

long isEmpty(struct stack *s){
	if(s->head <= 0) return 1;
	else return 0;
}

char *nextOp(char *line){
	char *c;
	c = line;
	while(*c != '\0'){
		if((*c == '+') || (*c == '*')){
			return c;
		}
		c++;
	}
	return c;
}

long nextNumber(char line[]){
	 long num = 0;
	 char *c;
	 c = line;
	 while((*c != '\0') && isdigit(*c)){
	 	num =  num*10 + (*c - '0');
	 	c++;
	 }
	 return num;
}

long findMax(char line[]){
	struct stack st;
	char *sb;
	char operator, nextOperator;
	char *chop, *num1, *num2;
	long op1 = 0, op2 = 0;
	
	st.head = 0;
	
	sb = strdup(line);
	chop = nextOp(sb);
	op1 = nextNumber(sb);
	
	while(*chop != '\0'){
		if(*chop == '+'){
			op2 = nextNumber(chop + 1);
			op1 = op1 + op2;
		}
		else if (*chop == '*'){
			push(&st, op1);
			op1 = nextNumber(chop + 1);
		}
		chop = nextOp(chop + 1);
	}
	 
	while(!isEmpty(&st)){
		op2 = pop(&st);
		op1 = op1 * op2;
	}	
	free(sb);
	return op1;
}

long findMin(char line[]){
	struct stack st;
	char *sb;
	char operator, nextOperator;
	char *chop, *num1, *num2;
	long op1 = 0, op2 = 0;
	
	st.head = 0;
	
	sb = strdup(line);
	chop = nextOp(sb);
	op1 = nextNumber(sb);
	
	while(*chop != '\0'){
		if(*chop == '*'){
			op2 = nextNumber(chop + 1);
			op1 = op1 * op2;
		}
		else if (*chop == '+'){
			push(&st, op1);
			op1 = nextNumber(chop + 1);
		}
		chop = nextOp(chop + 1);
	}
	 
	while(!isEmpty(&st)){
		op2 = pop(&st);
		op1 = op1 + op2;
	}	
	free(sb);
	return op1;
}

int main(){
	short nTest;
	char line[MAX];
	long min, max;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	
	fscanf(fp,"%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		fscanf(fp,"%s",line);
		max = findMax(line);
		min = findMin(line);
		printf("The maximum and minimum are %ld and %ld.\n",max,min);
	}
	return 0;
}