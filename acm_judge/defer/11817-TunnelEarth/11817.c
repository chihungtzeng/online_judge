#include <stdio.h>
#include <math.h>

int main(){
	double latitude[2], longitude[2];
	double point[2][3]; /*x, y, z coordinates for the two points*/
	const int r = 6371009;
	double dist;
	short nTest, i, j;
	
	
	scanf("%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%lf %lf %lf %lf", latitude, longitude, latitude + 1, longitude + 1);
		printf("%lf %lf %lf %lf\n", latitude[0], longitude[0], latitude[1], longitude[1]);
		for(i=0; i<2; i++){
			latitude[i] = latitude[i]*M_PI / 180;
			if(longitude[i] < 0){
				longitude[i] += 360;
			}
			longitude[i] = longitude[i] *M_PI / 180;
		}
		for(i=0; i<2; i++){
			point[i][0] = fabs(cos(latitude[i]))*cos(longitude[i]);
			point[i][1] = fabs(cos(latitude[i]))*sin(longitude[i]);
			point[i][2] = sin(latitude[i]);
		}
		dist = 0;
		for(i=0; i<3; i++){
			dist += (point[1][i] - point[0][i])*(point[1][i] - point[0][i]);
		}
		dist = r * sqrt(dist);
		printf("%d\n", (int)nearbyint(dist));
	}
	
	return 0;
}