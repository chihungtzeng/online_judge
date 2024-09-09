#include <iostream>
#include <unordered_map>
#include <fstream>
#include <tuple>
#include <vector>

#define MAX 1000001

typedef short cycle_type;

class Oracle {
    public:
        cycle_type get_max_cycle(unsigned int low, unsigned int high);
        Oracle();

    private:
        void calc_cycle(unsigned int n);
        std::tuple<unsigned int, cycle_type> calc_next(unsigned int n);
        std::vector<cycle_type> m_cycle_vector;
};

Oracle::Oracle() {
    m_cycle_vector.reserve(MAX >> 1);
    for(int i=1 + (MAX>>1); i>=0; --i){
        m_cycle_vector[i] = 0;
    }
    m_cycle_vector[1] = 1;
}

std::tuple<unsigned int, cycle_type> Oracle::calc_next(unsigned int n){
    unsigned int next = n;
    cycle_type offset = 0;
    do {
        if (next & 1){
            next = (next << 1) + next + 1;
        }
        else {
            next = (next >> 1);
        }
        ++offset;
    } while(next >= MAX);
    return std::tuple<unsigned int, cycle_type>(next, offset);
}

void Oracle::calc_cycle(unsigned int n) {
    unsigned int next = 0;
    cycle_type offset = 0;

    std::tie(next, offset) = calc_next(n);
    if (!m_cycle_vector[next]){
        calc_cycle(next);
    }
    m_cycle_vector[n] = m_cycle_vector[next] + offset;
}

cycle_type Oracle::get_max_cycle(unsigned int low, unsigned int high) {
    cycle_type max = 0, offset = 0;
    unsigned int next=0, cur=low;
    while(cur <= high){
        unsigned int n = cur;
        cycle_type k = 0;
        while(!(n & 1)){
            ++k;
            n = n >> 1;
        }
        std::tie(next, offset) = calc_next(n);

        if (!m_cycle_vector[n]){
            calc_cycle(next);
            m_cycle_vector[n] = m_cycle_vector[next] + offset;
        }
        if (max < m_cycle_vector[n] + k){
            max = m_cycle_vector[n] + k;
        }
        ++cur;
    }
    return max;
}

int main(int argc, char *argv[]){
    unsigned int low, high, clow, chigh;
    Oracle oracle;
#ifndef ONLINE_JUDGE
    std::ifstream input("in.txt");
    //std::streambuf *cinbuf = std::cin.rdbuf(); //save the cin buffer
    std::cin.rdbuf(input.rdbuf());
#endif
    while(std::cin >> clow >> chigh){
        high = clow + chigh - std::min(clow, chigh);
        low = clow + chigh - high;
        cycle_type max = oracle.get_max_cycle(low, high);
        std::cout << clow << " " << chigh << " " << max << std::endl;
    }
    return 0;
}
