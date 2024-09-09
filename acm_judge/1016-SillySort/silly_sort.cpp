#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <memory>
#include <vector>


class SillySorter {
    public:
        int nElement;
        std::vector<short> vNumbers;

    private:
        short global_min;
        std::unordered_map<short, short> position;

    public:
        SillySorter(int n): nElement(n), vNumbers(n) {}
        int min_swap_cost();
        void sort();
        friend std::ostream & operator<<(std::ostream &, const SillySorter *);

};

int SillySorter::min_swap_cost(){
    int result = 0;
    std::vector<bool> visited(nElement, false);
    sort();

    for(int i=0; i<nElement; i++){
        if(!visited[i]){
            std::vector<short> cycle;
            int cur = i;
            int next = -1;
            int cycle_cost = 0;
            int cycle_size = 0;
            int use_local_min_cost = 0;
            int use_global_min_cost = 0;
            short ele = 0;
            short local_min = 32767;
            bool done = false;
            
            while(!done){
                ele = vNumbers[cur];
                local_min = std::min(local_min, ele);
                cycle.push_back(ele);
                visited[cur] = true;
                next = position[ele];
                if (!visited[next]){
                    cur = next;
                }
                else {
                    done = true;
                }
            }
            cycle_size = cycle.size();
            for(auto it: cycle){
                cycle_cost += it;
            }
            cycle_cost -= local_min;
            
            // we might borrow the global min(g_min) to swap elements in the cycle.
            // swap(local_min, g_min), using g_min in the cyles to swap 
            // and swap(local_min, g_min) again
            use_local_min_cost = (cycle_size - 1) * local_min;
            use_global_min_cost = (global_min + local_min) * 2 + (cycle_size - 1) * global_min;
            if (use_local_min_cost < use_global_min_cost){
                cycle_cost += use_local_min_cost;
            }
            else {
                cycle_cost += use_global_min_cost;
            }

            result += cycle_cost;
        }
    }

    return result;
}

void SillySorter::sort(){
    std::vector<short> vSortedNumbers = vNumbers;
    std::sort(vSortedNumbers.begin(), vSortedNumbers.end());
    for(int i=0; i<nElement; i++){
        position[vSortedNumbers[i]] = i;
    }
    global_min = vSortedNumbers[0];
}

int main(int argc, char *argv[]){
    int nTest = 0;
    int nElement = 0;
#ifndef ONLINE_JUDGE
    std::ifstream input("in.txt");
    std::cin.rdbuf(input.rdbuf());
#endif
    while(std::cin >> nElement){
        if (0 == nElement){
            break;
        }
        std::unique_ptr<SillySorter> sillySorter(new SillySorter(nElement));
        ++nTest;
        for(int i = 0; i < nElement; ++i){
            std::cin >> sillySorter->vNumbers[i];
        }
        std::cout << "Case " << nTest << ": " << sillySorter->min_swap_cost() << "\n\n";
    }

    return 0;
}

