#include <cstdint>
class Solution {
public:
  int trailingZeroes(int n) {
    int64_t ans = 0;
    int64_t base = 5;
    int64_t n2 = n;
    while (n2 >= base) {
      ans += n2 / base;
      base = (base << 2u) + base;
    }

    return static_cast<int>(ans);
  }
};
