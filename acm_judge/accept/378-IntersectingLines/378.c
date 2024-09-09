#include <stdio.h>

struct Point {
	int x, y;
};

int isParallel(struct Point point[4]){	
	if ((point[0].x - point[1].x)*(point[2].y - point[3].y) == (point[2].x - point[3].x)*(point[0].y - point[1].y)){
		return 1;
	}
	else {
		return 0;
	}
}

int isOverlap(struct Point point[4]){	
	if( (point[0].x - point[1].x)*(point[2].y-point[0].y) - (point[0].y - point[1].y)*(point[2].x - point[0].x) == 0){
		return 1;
	}
	else {
		return 0;
	}
}

void solve(struct Point point[4]){
	int a[2], b[2], c[2];
	int i, j;
	double x, y;
	if(isParallel(point)){
		if(isOverlap(point)){
			printf("LINE\n");
		}
		else{
			printf("NONE\n");
			
		}
		return ;
	}
	for(i=0; i<2; i++){
		j = i << 1;
		a[i] = point[j].y - point[j+1].y;
		b[i] = -point[j].x + point[j+1].x;
		c[i] = point[j].y * (point[j].x - point[j+1].x) - point[j].x * (point[j].y - point[j+1].y);
	}
	#if 0
	for(i=0; i<2; i++){
		printf("i=%d: a[i]= %d, b[i]=%d, c[i]=%d\n", i, a[i], b[i], c[i]);
	}
	#endif
	x = (c[1]*b[0] - c[0]*b[1])/ (0.0 + a[0]*b[1] - a[1]*b[0]) ;
	if(b[0] == 0){
		y = (-c[1] - a[1]*x)/b[1];
	}
	else{
		y = (-c[0] - a[0]*x)/b[0];
	}
	printf("POINT %.2lf %.2lf\n", x, y);
}

int main(){
	struct Point point[4];
	int nTest;
	int i, j;
	
	printf("INTERSECTING LINES OUTPUT\n");
	scanf("%d", &nTest);
	while(nTest--){
		for(i=0; i<4; i++){
			scanf("%d %d", &point[i].x, &point[i].y);
		}
		solve(point);
	}
	printf("END OF OUTPUT\n");
	
	return 0;
}
