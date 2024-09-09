#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player{
	short attack, defense;
	char name[21];
};

int comparePlayer(const void *a, const void *b){
	struct Player *p, *q;
	p = (struct Player *) a;
	q = (struct Player *) b;
	if(p->attack != q->attack) return q->attack - p->attack;
	else if (p->defense != q->defense) return p->defense - q->defense;
	else return strcmp(p->name, q->name);
}

int compareString(const void *a, const void *b){
	char *x, *y;
	x = (char *)a;
	y = (char *)b;
	return strcmp(x, y);
}

int main(){
	
	char formation[5][21];
	
	short i, j, k = 1, nTest;
	struct Player player[10]; 
	
	scanf("%hd", &nTest);
	while(k <= nTest){
		for(i=0; i<10; i++){
			scanf("%s %hd %hd", player[i].name, &player[i].attack, &player[i].defense);
		}
		qsort(player, 10, sizeof(struct Player), comparePlayer);
		printf("Case %hd:\n",k++);
		for(j=0; j<2; j++){
			for(i=0;i<5;i++){	
				strcpy(formation[i], player[5*j+i].name);
			}
			qsort(formation, 5, sizeof(char)*21, compareString);
			printf("(%s", formation[0]);
			for(i=1; i<5; i++){
				printf(", %s", formation[i]);
			}
			printf(")\n");
		}
		
	}	
	return 0;
}