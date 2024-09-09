#include <stdio.h>
#include <string.h>
#define MAX 32
#define WRONG 1
#define YES 0
#define PE 2

char user[MAX], judge[MAX];

char checkAns(){
	char *u, *j;
	char state = YES;
	u = user;
	j = judge;
	
	while( (*u != '\0') && (*j != '\0')){
		if(*u != *j){
			if((state == YES) && (*u == ' ')){
				state = PE;
				u++;
			}
			else if ((state == PE) && (*u == ' ')){
				u++;
			}			
			else if ((*u != ' ')){
				state = WRONG;
				return WRONG;
			}
		}
		else{
			u++;
			j++;
		}
	}
	return state;
}

int main(){
	char t, k=1;
	char state;
	size_t s, x;
	fgets(user, MAX, stdin);
	t = atoi(user);
	while(k <= t){
		fgets(user, MAX, stdin);
		fgets(judge, MAX, stdin);
		/*
		s = strlen(user);
		x = strlen(judge);
		if(user[s-1] == '\n'){
			s--;
			user[s] = '\0';
		}
		if(judge[x-1] == '\n'){
			x--;
			judge[x] = '\0';
		}
		*/
		/*printf("***user: %s judge: %s\n", user, judge);*/
		
		state = checkAns();
		if(state == YES){
			printf("Case %hhd: Yes\n", k);
		}
		else if(state == WRONG){
			printf("Case %hhd: Wrong Answer\n",k);
		}
		else {
			printf("Case %hhd: Output Format Error\n",k);
		}
		k++;
	}
	return 0;
}