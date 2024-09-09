#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_LEN 1000
#define DEBUG 0



struct stack{
	int n;
	int element[25];
};

void push(struct stack *t,int value){
	if (DEBUG){
		printf("push %d to stack\n",value); 
	}	
	if(t->n == 25){
		printf("stack is full\n");
		exit(EXIT_FAILURE) ;
	}
	t->element[t->n]=value;
	t->n++;
	return ;
}
int pop(struct stack *s){
	int value;
	
	if(s->n <= 0){
		printf("No element can be popped\n");
		return EXIT_FAILURE;
	}
	value=s->element[s->n - 1];
	s->n--;
	return value;
}

char *itoa(int n){
	
	 
	char *out,tmp;
	int i,r,j,len;
	out=(char *)malloc(sizeof(char)*100);
	i=0;
	do{
		r = n % 10;
		out[i]= r +'0';
		i++;
		n = n/10;
	} while (n>0);
	out[i]='\0';

	
	len = strlen(out);
	j = len -1;
	for(i=0;i<len/2;i++,j--){
		tmp = out[i];
		out[i] = out[j];
		out[j] = tmp;
	}
	return out;
}

char *stack2string(struct stack t){
	char *out;
	int i;
	out = (char *)malloc(sizeof(char)*100);
	out[0]='\0';
	for(i=0;i<t.n;i++){
		strcat(out, itoa(t.element[i]));
		strcat(out," ");
	}
	return out;
}




void moveonto(struct stack *s, int *pos, int scr, int target){
	int scrpos,targetpos;
	int popout;
	if (DEBUG){
		printf("call function move %d onto %d \n",scr,target);
	}
	
	scrpos=pos[scr];
	targetpos=pos[target];
	
	popout=pop(&s[scrpos]);
	while (popout != scr){
		push(&s[popout],popout);
		pos[popout]=popout;
		popout = pop(&s[scrpos]);		
	}	
	push(&s[scrpos],popout);
	
	
	popout=pop(&s[targetpos]);
	while (popout != target){
		push(&s[popout],popout);
		pos[popout]=popout;
		popout = pop(&s[targetpos]);		
	}
	push(&s[targetpos],target);
	
	
	popout=pop(&s[scrpos]);
	push(&s[targetpos],popout); 
	pos[popout]=targetpos;
	
	if (DEBUG){
		printf("source stack %d: %s\n",scrpos,stack2string(s[scrpos]));
		printf("target stack %d: %s\n",targetpos,stack2string(s[targetpos]));
	}
}

void moveover(struct stack *s, int *pos, int scr, int target){
	int scrpos,targetpos;
	int popout;
	if (DEBUG){
		printf("call function move %d over %d \n",scr,target);
	}
	
	scrpos=pos[scr];
	targetpos=pos[target];
	
	popout=pop(&s[scrpos]);
	while (popout != scr){
		push(&s[popout],popout);
		pos[popout]=popout;
		popout = pop(&s[scrpos]);		
	}	
	
	push(&s[targetpos],scr);
	pos[scr]=targetpos;
	if (DEBUG){
		printf("source stack %d: %s\n",scrpos,stack2string(s[scrpos]));
		printf("target stack %d: %s\n",targetpos,stack2string(s[targetpos]));
	}
	return ;
}

void pileonto(struct stack *s, int *pos, int scr, int target){
	int scrpos,targetpos;
	int popout;
	struct stack tmpstack;
	if (DEBUG){
		printf("call function pile %d onto %d \n",scr,target);
	}
	scrpos=pos[scr];
	targetpos=pos[target];
	
	
	tmpstack.n=0;
	popout=pop(&s[scrpos]);
	while (popout != scr){
		push(&tmpstack, popout);
		popout = pop(&s[scrpos]);
	}
	push(&tmpstack,popout);
	
	
	popout = pop(&s[targetpos]);
	while(popout!=target){
		push(&s[popout],popout);
		pos[popout]=popout;
		popout=pop(&s[targetpos]);
	}
	push(&s[targetpos],popout);
	
	
	
	while(tmpstack.n >0){
		popout=pop(&tmpstack);
		push(&s[targetpos],popout);
		pos[popout] = targetpos;
	}
	if (DEBUG){
		printf("source stack %d: %s\n",scrpos,stack2string(s[scrpos]));
		printf("target stack %d: %s\n",targetpos,stack2string(s[targetpos]));
	}
}

void pileover(struct stack *s, int *pos, int scr, int target){
	int scrpos,targetpos;
	int popout;

	
	
	if (DEBUG){
		printf("call function pile %d over %d \n",scr,target);
		
	}
	scrpos=pos[scr];
	targetpos=pos[target];
	
	
	struct stack tmpstack; 
	tmpstack.n=0;
	
	
	
	
	popout=pop(&s[scrpos]);
	while (popout != scr){
		push(&tmpstack, popout);
		popout=pop(&s[scrpos]);
	}
	push(&tmpstack,popout);
	
	
	while(tmpstack.n >0){
		popout=pop(&tmpstack);
		push(&s[targetpos],popout);
		pos[popout] = targetpos;
	}
	if (DEBUG){
		printf("source stack %d: %s\n",scrpos,stack2string(s[scrpos]));
		printf("target stack %d: %s\n",targetpos,stack2string(s[targetpos]));
	}
}

int main(int argc, char *argv[]){
	FILE *fp;
	char line[LINE_LEN],*cmd, *type;
	struct stack s[25];
	int pos[25]; 
	int n;
	int i,j,k;
	int done;
	int src, target;
	
	/*fp = fopen("input.txt","r");*/
	fp = stdin;
	if(NULL == fp) {
		printf("open file failed\n");
		exit(EXIT_FAILURE);
	}	
	
	fgets(line,LINE_LEN,fp);

	n=atoi(line); 
	
	for(i=0;i<n;i++){
		s[i].n=0;
		push(&s[i],i);
		pos[i]=i;
	} 

	done = 0;
	cmd = (char *)malloc(sizeof(char)*5);
	type = (char *)malloc(sizeof(char)*5);
	while(!done){
		fscanf(fp,"%s",cmd);
		printf("reading: %s\n",cmd);
		if (!strcmp(cmd,"quit")){
			done = 1;
			continue;
		}
		else {
			fscanf(fp,"%d",&src);
			fscanf(fp,"%s",type);
			fscanf(fp,"%d",&target);
			printf("doing %s %s %d to %d",cmd,type,src,target);
		}
		if ((pos[src] == pos[target])&&(src == target)){
			continue;
		}
	 	if ((!strcmp(cmd,"move")) && (!strcmp(type,"onto"))){
			moveonto(s,pos,src,target);
			continue;
		}
		else if ((!strcmp(cmd,"move")) && (!strcmp(type,"over"))){
			moveover(s,pos,src,target);
			continue;
		}
		else if ((!strcmp(cmd,"pile")) && (!strcmp(type,"onto"))){
			pileonto(s,pos,src,target);
			continue;
		}
		else if ((!strcmp(cmd,"pile")) && (!strcmp(type,"over"))){
			pileover(s,pos,src,target);
			continue;
		}
	}	
	
	for (i=0;i<n;i++){
		printf("%d: %s\n",i,stack2string(s[i]));
	}
	/*
	printf("position: ");
	for (i=0;i<n;i++){
		printf("%d ",pos[i]);
	}
	*/
	return 0;
}
