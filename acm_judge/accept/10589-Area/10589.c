#include <stdio.h>

#define HYPOT(x, y) ((x)*(x) + (y)*(y))

int isInside(double x, double y, int width, int radiusSquare){
	int i;
	double xx, yy;
	/*lower-left*/
	if(HYPOT(x, y) > radiusSquare) return 0;
	
	

	/*up-left*/
	yy = y - width;
	if(HYPOT(x, yy) > radiusSquare) return 0;
	
	/*lower-right*/
	xx = x - width;
	if(HYPOT(xx, y) > radiusSquare) return 0;
	
	/*up-right*/
	xx = x - width;
	yy = y - width;
	if(HYPOT(xx, yy) > radiusSquare) return 0;	
	
	return 1;
}

int main(){
	double area;
	double xx, yy, x, y;
	int nPoint, width, radiusSquare;
	int nInside, i;
	
	while(2 == scanf("%d %d", &nPoint, &width)){
		if((0 == nPoint) && (0 == width)) {
			break;
		}
	
		radiusSquare = width * width;
		nInside = 0;
		for(i=0; i<nPoint; i++){
			scanf("%lf %lf", &x, &y);
			nInside += isInside(x, y, width, radiusSquare);
		}
		area = width*width*nInside;
		area = (double) area / nPoint;
		printf("%.5lf\n", area);
	}
	return 0;
	
}