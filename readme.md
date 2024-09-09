This is a collection of the code while I was studying programming.
Most of the code is for leetcode. 

- [UVA online judge](https://onlinejudge.org/)
- [Leetcode](https://leetcode.com/)

For leetcode problems solved by C++, I used cmake and glog (for debugging) to make the process quick.
Typically I would write code in leet.cpp and put test cases in leet_test.cpp, and run

```
mkdir -p out && cd out
cmake ..
make -j
./leet
```

If all test cases are passed, then submit the solution.

