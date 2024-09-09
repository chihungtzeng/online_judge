#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b) do { (a) ^= (b); (b) ^= (a); (a) ^= (b); } while(0)
#define DEBUG 0

struct Point {
	int x, y;
};

struct Rect {
	struct Point leftTop, rightBottom;
};

struct Segment {
	struct Point point[2];
};

int MIN(int a, int b){
	return (a < b)? a : b; 
}

int MAX(int a, int b){
	return (a < b)? b : a; 
}



int calcSide(int x1, int y1, int xCoef, int yCoef, int x, int y){
	return xCoef * (y - y1) - yCoef * (x - x1);
}

int bInsideRect(struct Point p, struct Rect rect){
	if (p.x < rect.leftTop.x || p.x > rect.rightBottom.x) return 0;
	if (p.y > rect.leftTop.y || p.y < rect.rightBottom.y) return 0;
	return 1;
}

int isIntersect(struct Segment s1, struct Segment s2){
	int xCoef, yCoef;
	int side[2];
   int i;
   int possibleIntersect;
	xCoef = s1.point[0].x - s1.point[1].x;
	yCoef = s1.point[0].y - s1.point[1].y;
   for(i=0; i<2; i++){
	    side[i] = calcSide(s1.point[0].x, s1.point[0].y, 
            xCoef, yCoef, s2.point[i].x, s2.point[i].y);
   }
   #if DEBUG
   printf("first check side[2] = (%d %d)\n", side[0], side[1]);
   #endif
   if(side[0] * side[1] > 0) return 0;
   
	
	xCoef = s2.point[0].x - s2.point[1].x;
	yCoef = s2.point[0].y - s2.point[1].y;
    for(i=0; i<2; i++){
	    side[i] = calcSide(s2.point[0].x, s2.point[0].y, 
            xCoef, yCoef, s1.point[i].x, s1.point[i].y);
    }
   #if DEBUG
   printf("second check side[2] = (%d %d)\n", side[0], side[1]);
   #endif
   if(side[0] * side[1] > 0) return 0;

	if( (side[0] != 0) || (side[1] != 0)) return 1;   
   	
	return 0;
}

void solve(struct Point startPoint, struct Point endPoint, struct Rect rect){
	/*
	The linear equation for startPoint and endPoint is
	(x1 - x2)(y-y1) - (y1-y2)(x-x1) = 0;
	check if all the four points of rect are on the same side of the line equation.
	*/

	if(bInsideRect(startPoint, rect)){
		puts("T");
		return ;
	}	
	struct Point p[4];
	struct Segment target, seg[4];
	int bIntersect[4];
	int i;
	
	target.point[0] = startPoint;
	target.point[1] = endPoint;
	
	p[0].x = rect.leftTop.x;
	p[0].y = rect.leftTop.y;	
	p[1].x = rect.leftTop.x;
	p[1].y = rect.rightBottom.y;
	p[2].x = rect.rightBottom.x;
	p[2].y = rect.rightBottom.y;
	p[3].x = rect.rightBottom.x;
	p[3].y = rect.leftTop.y;

	#if DEBUG
	printf("Rect:\n");
	for(i=0; i<4; i++){
		printf("(%d %d)\n", p[i].x, p[i].y);
	}
	printf("line: (%d %d) -> (%d %d)\n", target.point[0].x, target.point[0].y, target.point[1].x, target.point[1].y);
	#endif
	for(i=0; i<4; i++){
		seg[i].point[0] = p[i];
		seg[i].point[1] = p[(i+1) & 3];
	}
	
	
	for(i=0; i<4; i++){
		bIntersect[i] = isIntersect(target, seg[i]);
	}
	#if DEBUG
	for(i=0; i<4; i++){
		printf("%d ", bIntersect[i]);
	}
	printf("\n");
	#endif
	
	for(i=0; i<4; i++){
		if(bIntersect[i]){
			puts("T");
			return ;
		}
	}
	puts("F");
} 

int main(){
	int nTest;
	struct Point startPoint, endPoint;
	struct Rect rect;
	scanf("%d", &nTest);
	while(nTest--){
		scanf("%d %d %d %d %d %d %d %d",
			&startPoint.x, &startPoint.y,
			&endPoint.x, &endPoint.y,
			&rect.leftTop.x, &rect.leftTop.y,
			&rect.rightBottom.x, &rect.rightBottom.y
		);
		/*
		if(startPoint.x > endPoint.x){
			SWAP(startPoint.x, endPoint.x);
			SWAP(startPoint.y, endPoint.y);
		}
		*/
		if(rect.leftTop.x > rect.rightBottom.x){
			SWAP(rect.leftTop.x, rect.rightBottom.x);
		}
		if(rect.leftTop.y < rect.rightBottom.y){
			SWAP(rect.leftTop.y, rect.rightBottom.y);
		}
		solve(startPoint, endPoint, rect);
	}
	return 0;
}
