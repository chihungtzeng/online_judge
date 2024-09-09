#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101
#define LEFT 0
#define RIGHT 1
#define DEBUG 1

short findBestMove(int num[], short left, short right, int *sum, short *endPos){
	short i, sumLeft, sumRight, endLeft, endRight;
	int tmpSum = 0;	
	
	/*calculate sum from left and right*/
	sumLeft = num[left];
	endLeft = left;
	tmpSum = sumLeft;
	for(i = left + 1; i<=right; i++){
		tmpSum += num[i];
		if(tmpSum > sumLeft){
			sumLeft = tmpSum;
			endLeft = i;
		}
	}
	
	sumRight = num[right];
	endRight = right;
	tmpSum = sumRight;
	for(i=right - 1; i>=left; i--){
		tmpSum += num[i];
		if(tmpSum > sumRight){
			sumRight = tmpSum;
			endRight = i;
		}
	}
	
	if(sumLeft < sumRight){
		*sum = sumRight;
		*endPos = endRight;
		return RIGHT;
	}
	else{
		*sum = sumLeft;
		*endPos = endLeft;
		return LEFT;
	}
}

int main(){
	int num[MAX];
	short nNum, player;
	short left, right, pos;
	short direction, i;
	int getScore;
	int score[2];
	
	while(1 == scanf("%hd",&nNum)){
		if(nNum == 0){
			break;
		}
		for(i=0; i<nNum; i++){
			scanf("%d",&num[i]);
		}
		score[0] = 0;
		score[1] = 0;
		left = 0;
		right = nNum - 1;
		player = 0;
		while(left <= right){
			direction = findBestMove(num, left, right, &getScore, &pos);
			score[player] += getScore;
			if(DEBUG){
				printf("player %d choose %d, getscore %d, end at %d\n", player, direction, getScore, pos);
			}
			if(direction == LEFT){
				left = pos + 1;
			}
			else {
				right = pos - 1;
			}
			player = 1 - player;
		}
		if(DEBUG){
			printf("player 0: %d player 1: %d\n",score[0], score[1]);
		}
		printf("%d\n", abs(score[0] - score[1]));
	}
	return 0;
}