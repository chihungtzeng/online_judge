#include "benchmark/benchmark_api.h"
#include "10706-NumSeq.cpp"

void Number_Bench_Digit_Count(benchmark::State& state)
{
    Number n = 0;
    while(state.KeepRunning()){
        n=12345;
        n.digit_count();
        n=1234;
        n.digit_count();
        n=123;
        n.digit_count();
        n=12;
        n.digit_count();
        n=1;
        n.digit_count();
    }
}

BENCHMARK(Number_Bench_Digit_Count);

BENCHMARK_MAIN()
