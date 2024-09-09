#include <stdio.h>
#define LEN 32
#define MAX(a, b) ((a) < (b)? (b) : (a))
#define MIN(a, b) ((a) < (b)? (a) : (b))

struct Segment {
	short left, right;
};

int getCommonLength(short nSegment, struct Segment seg[]){
	short i;
	short left = seg[0].left;
	short right = seg[0].right;

	for(i=1; i<nSegment; i++){
		left = MAX(left, seg[i].left);
		right = MIN(right, seg[i].right);
	}	
	if(left > right) return 0;
	else return right - left;
}


int main(){
	struct Segment x[LEN], y[LEN];
	int xCommonLength, yCommonLength;
	short nTest;
	short nRectangle;	
	short i, k = 1;
	
	scanf("%hd", &nTest);
	while(nTest--){
		scanf("%hd", &nRectangle);
		for(i=0; i<nRectangle; i++){
			scanf("%hd %hd %hd %hd", &x[i].left, &y[i].left, &x[i].right, &y[i].right);
		}
		xCommonLength = getCommonLength(nRectangle, x);
		yCommonLength = getCommonLength(nRectangle, y);
		printf("Case %hd: %d\n", k++, xCommonLength * yCommonLength);
		#if 0
		for(i=0; i<nRectangle; i++){
			printf("%hd %hd %hd %hd\n", x[i].left, y[i].left, x[i].right, y[i].right);
		}
		#endif
	} 	
	return 0;
}