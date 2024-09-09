#include <iostream>
#include <array>
#include <fstream>

#define MAX 1000001

void calc_cycle(std::array<short, MAX> &cycle, int n){
    int next = n >> 1;
    if (n & 1){
        next = (n << 1) + n + 1;
    }
    if (cycle[next] > 0){
        cycle[n] = cycle[next] + 1;
    }
    else {
        calc_cycle(cycle, next);
        cycle[n] = cycle[next] + 1;
    }
}

short find_max_cycle(int low, int high, std::array<short, MAX> &cycle){
    short max = 0;
    for (int i=low; i<=high; i++){
        if (cycle[i] == 0){
            calc_cycle(cycle, i);
        }
        max = std::max(max, cycle[i]);
    }
    return max;
}


int main(int argc, char *argv[]){
    int low, high;
    std::array<short, MAX> cycle = {0};
    cycle[1] = 1;
#ifndef ONLINE_JUDGE
    std::ifstream input("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());
#endif
    while(std::cin >> low >> high){
        if (low > high){
            std::swap(low, high);
        }
        int max_cycle = find_max_cycle(low, high, cycle);
        std::cout << low << " " << high << " " << max_cycle << std::endl;
    }
    return 0;
}
