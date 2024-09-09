#include <stdio.h>
#include <stdlib.h>
#define MAXBOX 101
#define YES 1
#define NO 0
#define DEBUG 0

struct box{
	int width;
	int height;
	struct box *insideBox[MAXBOX];
	short nInside;
};

struct box *newBox(int width){
	struct box *b;
	b = (struct box *) malloc(sizeof(struct box));
	b->width = width;
	b->height = width;
	b->nInside = 0;
}

void freeBox(struct box *target){
	short i;
	if(target == NULL){
		return;
	}
	for(i=0;i<target->nInside;i++){
		freeBox(target->insideBox[i]);
	}
	free(target);
}

int ableContain(struct box *target, struct box *newbox){
	short i;
	if((NULL == target) || (NULL == newbox)){
		printf("cannot compare null boxes\n");
	}
	if(target->width < newbox->width){
		return NO;
	}
	if(target->height >= newbox->width){
		return YES;
	}

	if(target->nInside >= 1){
		return ableContain(target->insideBox[target->nInside - 1], newbox);
	}
	return NO;
}


int insertBox(struct box *target, struct box *newbox){
	short i, j;
	if((target == NULL) || (target == NULL)){
		printf("Never insert null box\n");
		return NO;
	}
	if(ableContain(target, newbox) == NO){
		printf("unable to insert box %d into %d\n", newbox->width, target->width);
		return NO;
	}

	
	j = target->nInside - 1;
	while((j >= 0) && (ableContain(target->insideBox[j], newbox) == YES)){
			j--;
	}
	if(j != target->nInside - 1){
		insertBox(target->insideBox[j+1], newbox);
		return YES;
	}
	else {
	/*The new box cannot fall into the smaller boxes 
	contained by the target box, so we put the new
	box above the other inside boxes*/
		target->insideBox[target->nInside] = newbox;
		target->nInside += 1;
		target->height = target->height - newbox->width;
		if(DEBUG){
			printf("box %d is inserted into box %d\n",newbox->width, target->width);
		}
		return YES;
	}
	return NO;
	
}

int main(){
	struct box *boxList[MAXBOX];
	struct box *newbox;
	int width;
	short nBox, i;
	short boxListLen;
	short first;	
	int ans;
	FILE *fp;
	

	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	while(1 == fscanf(fp,"%hd", &nBox)){

		if(nBox <= 0){
			printf("0\n");
			continue;
		}
		fscanf(fp,"%d", &width);
		boxList[0] = newBox(width);
		boxListLen = 1;
		for(i=1;i<nBox;i++){
			int j;
			fscanf(fp,"%d", &width);
			newbox = newBox(width); 
			
			if(ableContain(boxList[boxListLen-1], newbox) == NO){
				boxList[boxListLen++] = newbox;
			}
			else{
				j = boxListLen - 1;
				while((j >= 0) && (ableContain(boxList[j], newbox) == YES)){
					j--;
				}
				insertBox(boxList[j+1], newbox);
			}
			
		}
		if(DEBUG){
			printf("boxListLen = %hd\n", boxListLen);
		}
		ans = 0;
		for(i=0;i<boxListLen;i++){
			ans += boxList[i]->width;
		}
		printf("%d\n",ans);
		for(i=0; i < boxListLen; i++){
			freeBox(boxList[i]);
		}
	}	
	return 0;
}