#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 11
#define LINELEN 512 
#define ENDPOINT "9999.9"
#define EPSILON 1e-6


struct Point {
	double x, y;
};

struct Rectangle {
	struct Point ul, lr;
};

struct Circle {
	struct Point center;
	double radius;
	double radius2;
};

struct Triangle {
	struct Point corner[3];
	double area;
};

struct Shape {
	union {
		struct Rectangle rectangle;
		struct Circle circle;
		struct Triangle triangle;
	};
	int sType;
};

enum {
	RECTANGLE,
	CIRCLE,
	TRIANGLE
};

struct Shape shape[MAX];
int nShape;
int insideShape[MAX];

double triangleArea(struct Point a, struct Point b, struct Point c){
	double area;
	area = (a.x - c.x)*(b.y - a.y) - (a.x - b.x)*(c.y - a.y);
	
	return fabs(area);
}


int isInsideRectangle(struct Point query, struct Shape r){
	if(query.x <= r.rectangle.ul.x) return 0;
	if(query.x >= r.rectangle.lr.x) return 0;
	if(query.y <= r.rectangle.lr.y) return 0;
	if(query.y >= r.rectangle.ul.y) return 0;
	return 1;
}

int isInsideCircle(struct Point query, struct Shape s){
	double dist, tmp;
	tmp = query.x - s.circle.center.x;
	dist = tmp * tmp;
	tmp = query.y - s.circle.center.y;
	dist += tmp*tmp;
	if(dist >= s.circle.radius2) return 0;
	else return 1;  
}

int isInsideTriangle(struct Point query, struct Shape s){
	double area;
	int i;
	
	area = 0;
	for(i=0; i<3; i++){
		area += triangleArea(query, s.triangle.corner[i], s.triangle.corner[(i+1)%3]);
	}
	if(fabs(area - s.triangle.area) > EPSILON) return 0;
	else return 1; 
}

int inside(struct Point query){
	int nInside = 0;
	int i;
	for(i=1; i<=nShape; i++){
		if((shape[i].sType == RECTANGLE) && isInsideRectangle(query, shape[i])){
			insideShape[nInside++] = i;
		} else if((shape[i].sType == CIRCLE) && isInsideCircle(query, shape[i])){
			insideShape[nInside++] = i;
		} else if((shape[i].sType == TRIANGLE) && isInsideTriangle(query, shape[i])){
			insideShape[nInside++] = i;
		}
	}
	return nInside;
}

void solve(int pointIndex, struct Point query){
	int nOverlap, i;
	nOverlap = inside(query);
	for(i=0; i<nOverlap; i++){
		printf("Point %d is contained in figure %d\n", pointIndex, insideShape[i]);
	}
	if(nOverlap == 0){
		printf("Point %d is not contained in any figure\n", pointIndex);
	}
}

int main(){
	char token[2][32];
	int read = 1, nPoint = 1;
	struct Point query;
	/*read rectangle*/
	nShape = 1;
	while(read){
		scanf("%s", token[0]);
		if(token[0][0] == 'r'){
			scanf("%lf %lf %lf %lf", 
				&shape[nShape].rectangle.ul.x, &shape[nShape].rectangle.ul.y, 
				&shape[nShape].rectangle.lr.x, &shape[nShape].rectangle.lr.y);
			shape[nShape].sType = RECTANGLE;
			nShape++; 
		} else if (token[0][0] == 'c') {
			scanf("%lf %lf %lf",
				&shape[nShape].circle.center.x, &shape[nShape].circle.center.y, &shape[nShape].circle.radius);
			shape[nShape].circle.radius2 = shape[nShape].circle.radius * shape[nShape].circle.radius;
			shape[nShape].sType = CIRCLE;
			nShape++;
		} else if (token[0][0] == 't'){
			scanf("%lf %lf %lf %lf %lf %lf",
				&(shape[nShape].triangle.corner[0].x), &(shape[nShape].triangle.corner[0].y),
				&(shape[nShape].triangle.corner[1].x), &(shape[nShape].triangle.corner[1].y),
				&(shape[nShape].triangle.corner[2].x), &(shape[nShape].triangle.corner[2].y)
				);
			shape[nShape].sType = TRIANGLE;
			shape[nShape].triangle.area = triangleArea(shape[nShape].triangle.corner[0], 
				shape[nShape].triangle.corner[1], shape[nShape].triangle.corner[2]);
			nShape++;
		} else {
			read = 0;
		}
	}


	/*read point*/
	while(2 == scanf("%s %s", token[0], token[1])){
		if( (strcmp(token[0], ENDPOINT) == 0) && (strcmp(token[1], ENDPOINT) == 0)){
			break;
		}
		query.x = atof(token[0]);
		query.y = atof(token[1]);

		solve(nPoint, query);
		nPoint++;
	}	
	
	return 0;
}
