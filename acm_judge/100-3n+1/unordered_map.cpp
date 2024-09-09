#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <assert.h>

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#define MAX 1000001

void calc_cycle(
    std::unordered_map<unsigned int, short> &umap, 
    std::vector<short> &cycle_vector,
    unsigned int n)
{
    unsigned int next = n >> 1;
    if (n & 1){
        next = (n << 1) + n + 1;
    }
    if ((next < MAX) && (n < MAX)) {
        if (cycle_vector[next]){
            cycle_vector[n] = cycle_vector[next] + 1;
        }
        else {
            calc_cycle(umap, cycle_vector, next);
            cycle_vector[n] = cycle_vector[next] + 1;
        }
    }
    else if ((next < MAX) && (n >= MAX)){
        if (cycle_vector[next]){
            umap[n] = cycle_vector[next] + 1;
        }
        else {
            calc_cycle(umap, cycle_vector, next);
            umap[n] = cycle_vector[next] + 1;
        }
    }
    else if ((next >= MAX) && (n < MAX)){
        if (umap.count(next)){
            cycle_vector[n] = umap[next] + 1;
        }
        else {
            calc_cycle(umap, cycle_vector, next);
            cycle_vector[n] = umap[next] + 1;
        }
    }
    else {
        if (umap.count(next)){
            umap[n] = umap[next] + 1;
        }
        else {
            calc_cycle(umap, cycle_vector, next);
            umap[n] = umap[next] + 1;
        }
    }
}

short find_max_cycle(
        unsigned int low, 
        unsigned int high, 
        std::unordered_map<unsigned int, short> &umap,
        std::vector<short> &cycle_vector
        )
{
    short max = 0;
    while(low <= high){
        if (!cycle_vector[low]){
            calc_cycle(umap, cycle_vector, low);
        }
        if (max < cycle_vector[low]){
            max = cycle_vector[low];
        }
        ++low;
    }
    return max;
}

int main(int argc, char *argv[]){
    unsigned int low, high, clow, chigh;
    // init umap with size 2168442, which is derived from the field test
    // It improves performance by 14% (0.342s -> 0.295s)
    std::unordered_map<unsigned int, short> umap(2168442);
    std::vector<short> cycle_vector;
    cycle_vector.reserve(MAX*2);
    cycle_vector[1] = 1;
#ifndef ONLINE_JUDGE
    std::ifstream input("in.txt");
    //std::streambuf *cinbuf = std::cin.rdbuf(); //save the cin buffer
    std::cin.rdbuf(input.rdbuf());
#endif
    while(std::cin >> clow >> chigh){
        if (clow > chigh){
            high = clow;
		    low = chigh;
        }
        else {
            high = chigh;
            low = clow;
        }
        short max = find_max_cycle(low, high, umap, cycle_vector);
        std::cout << clow << " " << chigh << " " << max << std::endl;
    }
#ifndef ONLINE_JUDGE
    short max = 0;
    for(auto i = 0; i< MAX; i++){
        max = std::max(max, umap[i]);
    }
    std::cout << "max = " << max << std::endl;
    std::cout << "unordered map size: " << umap.size() << std::endl;
#endif
    return 0;
}
