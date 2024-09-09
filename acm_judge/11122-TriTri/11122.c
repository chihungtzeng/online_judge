#include <stdlib.h>
#include <stdio.h>


struct Point {
	int coordinate[2];
};

struct Triangle {
	struct Point vertice[3];
};

void printTriange(struct Triangle t){
    int i, j;
    printf("triangle: ");
    for(i=0; i<3; i++){
        printf("(%d %d) ", t.vertice[i].coordinate[0], t.vertice[i].coordinate[1]);
    }
    printf("\n");
}

int calcTriangleArea2(struct Triangle ABC){
    /*find the area of ABC and returns 2*area */
    int vector[2][2];
    int i, j;
    int area2;
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            vector[i][j] = ABC.vertice[2].coordinate[j] - ABC.vertice[i].coordinate[j];
        }
    }
    area2 = vector[0][0]*vector[2][2] - vector[0][1]*vector[1][0];
    return abs(area2);
}

int main(){
    struct Triangle t[2];
    int nTest;
    int i, j, vidx, xory;
    
    scanf("%d", &nTest);
    while(nTest--){
        for(i=0; i<2; i++){
            for(j=0; j<6; j++){
                vidx = j / 2;
                xory = j % 2;
                scanf("%d", &(t[i].vertice[vidx].coordinate[xory]));
            }
        }
        for(i=0; i<2; i++){
            printTriange(t[i]);
            printf("area of t[%d]=%d\n", i, calcTriangleArea2(t[i]));
        }
    }    


	return 0;
}