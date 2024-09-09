#include <iostream>
#include <assert.h>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      uint32_t nl = 0;
      uint32_t nr = 0;
      uint32_t pos = 0;
      uint32_t lmask = 1 << (31 - pos);
      uint32_t rmask = 1;
      while (lmask > rmask)
      {
        nl = (n & lmask) >> (31 - pos);
        nr = (n & rmask) >> pos;
        nl = nl ^ nr;
        nr = nl ^ nr;
        nl = nl ^ nr;
        nr = nr << pos;
        nl = nl << (31 - pos);
        n = (n & ~(lmask | rmask)) | nr | nl;
        lmask >>= 1;
        rmask <<= 1;
        pos += 1;
      }
      return n;
    }
};

int main()
{
  Solution sol;
  uint32_t ret = 0;
  ret = sol.reverseBits(1 << 31);
  std::cout << ret << "\n";
  assert(ret == 1);

  ret = sol.reverseBits(43261596);
  std::cout << ret << "\n";
  assert(ret == 964176192U);
  ret = sol.reverseBits(4294967293);
  std::cout << ret << "\n";
  assert(ret == 3221225471);
  return 0;
}
