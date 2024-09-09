
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM_WEEK 13
#define MAX_NUM_HOTEL 18


struct Hotel{
    short price;
    short nBed[MAX_NUM_WEEK];
};

int compareHotel(const void *a, const void *b){
    struct Hotel *x, *y;
    x = (struct Hotel *)a;
    y = (struct Hotel *)b;
    return x->price - y->price;
}

int compareShort(const void *a, const void *b){
    return *(short *)b - *(short *)a;
}

int solve(int nPeople, int budget, int nHotel, struct Hotel hotel[], int nWeek){
    int i;
    int found, ans;
    int avgBudget;
    
    avgBudget = budget / nPeople;
    ans = -1;
    for(i=0, found=0; (i<nHotel) && (!found); i++){
        if ((hotel[i].nBed[0] > nPeople) && (hotel[i].price <= avgBudget)){
            found = 1;
            ans = hotel[i].price; 
        }
    }
    return ans;
}

int main(){
    int nPeople, budget, nHotel, nWeek;
    int i,j, cheapestPrice;
    FILE *fp = stdin;
    struct Hotel hotel[MAX_NUM_HOTEL];
    
    
    while(4 == fscanf(fp, "%d %d %d %d", &nPeople, &budget, &nHotel, &nWeek)){
        for(i=0; i<nHotel; i++){
            fscanf(fp, "%hd", &hotel[i].price);
            for(j=0; j<nWeek; j++){
                fscanf(fp, "%hd", &(hotel[i].nBed[j]));
            }
            qsort(hotel[i].nBed, nWeek, sizeof(short), compareShort);
        }
        qsort(hotel, nHotel, sizeof(struct Hotel),compareHotel);
        cheapestPrice = solve(nPeople, budget, nHotel, hotel, nWeek);
        if(cheapestPrice <= 0){
            printf("stay home\n");
        }
        else{
            printf("%d\n", cheapestPrice * nPeople);
        }
    }    
    
    return 0;
}