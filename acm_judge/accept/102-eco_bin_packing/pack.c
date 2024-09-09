#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nColor 3
#define B 0
#define G 1
#define C 2

struct solinst {
	char *bcolor;
	long int cost;
};

void parseLine(char *line, long int move[nColor][nColor]){
	int i,j,sum;
	
	
	move[0][0] = atol(strtok(line," "));
	for(i=0;i<nColor;i++){
		for(j=0;j<nColor;j++){
			if(0 != i+ j){
				move[i][j] = atoi(strtok(NULL," "));
			}
		}
	}
	for(i=0;i<nColor;i++){
		sum=0;
		for(j=0;j<nColor;j++){
			sum += move[i][j];
		}
		for(j=0;j<nColor;j++){
			move[i][j] = sum-move[i][j];
		}
	}
	for(i=0;i<nColor;i++){
		for(j=0;j<nColor;j++){
			printf("%ld ",move[i][j]);
		}
		printf("\n");
	}
	printf("damn!\n");
}

void findoptsol(char *ava_color, char *bin_color,struct solinst *optsol, int ccost, long int move[nColor][nColor]){
	int len,i,j,index,current_bin;
	char ch;
	char head[nColor+1],tail[nColor+1];
	char tmp_ava_color[nColor+1],tmp_bin_color[nColor+1];


	len = strlen(ava_color);
	if (0 == len){
		//leaf 
		if (ccost < optsol-> cost){
			strcpy(optsol->bcolor, bin_color);
			optsol->cost = ccost; 
		} 
		else if (ccost == optsol->cost){
			if (strcmp(bin_color,optsol->bcolor) <0)
				strcpy(optsol->bcolor,bin_color);
		}
		return ;
	}
	
	for(i=0;i<len;i++){
		current_bin=strlen(bin_color);
		ch=ava_color[i];
		strcpy(tmp_ava_color,ava_color);
		strcpy(tmp_bin_color,bin_color);

		for(j=i;j<len;j++){
			ava_color[j] = ava_color[j+1];
		}
		/*
		strcpy(head,"");
		strcpy(tail,"");
		strncpy(head,ava_color,i);
		strncpy(tail,ava_color+i+1,len-i-1);		
		strcpy(ava_color, strcat(head,tail));
		*/
		
		
		bin_color[strlen(bin_color)+1]='\0';
		bin_color[strlen(bin_color)] =ch;
		switch(ch){
			case 'B': index=B; 
				break;
			case 'G': index=G; 
				break;
			case 'C': index=C; 
				break;
			default:
				printf("wrong color %c",ch);
				break;
		} 
		findoptsol(ava_color,bin_color,optsol,ccost+move[current_bin][index],move);
		strcpy(ava_color,tmp_ava_color);
		strcpy(bin_color,tmp_bin_color);
	}
}

int main(int argc, char *argv[]){
	long int move[nColor][nColor];
	char line[1024],ava_color[nColor+1],bin_color[nColor+1];
	FILE *fp;
	struct solinst optsol;
	

	
	fp = fopen("input.txt","r");
	if (NULL==fp){
		exit(EXIT_FAILURE);
	}
	
	
	while (NULL != (fgets(line,1024,fp))){
		parseLine(line,move);
		optsol.bcolor = (char *)malloc(sizeof(char)*(nColor+1));
		optsol.cost= (1<<30);
		strcpy(ava_color,"BGC");
		strcpy(bin_color,"");
		//printf("avacolor: %s bin_color: %s, ccost:%d",ava_color,bin_color,0);
		findoptsol(ava_color,bin_color,&optsol,0,move);
		printf("%s %ld\n",optsol.bcolor,optsol.cost);	
	}
	
}