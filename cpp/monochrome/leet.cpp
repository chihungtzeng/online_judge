#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <queue>
using namespace std;

vector<uint8_t> get_monochrome()
{
  vector<uint32_t> vals{ 0xa26302ae, 0x32b8d305, 0x49e001d5 };
  int width = 4 * 8;  // 32 bits
  int height = 3;
  vector<uint8_t> monochrome;

  for (auto val : vals)
  {
    vector<uint8_t> temp;
    for (int i = 0; i < 4; i++)
    {
      uint8_t byte = val & 0xff;
      val = val >> 8;
      temp.push_back(byte);
    }
    for (int i = 3; i >= 0; i--)
    {
      monochrome.push_back(temp[i]);
    }
  }
  return monochrome;
}

uint32_t rev_uint32(uint32_t val)
{
  uint32_t ret = 0;
  for(int i=0; i<32; i++){
    ret |= ((val >> i) & 1) << (31 - i);
  }
  return ret;
}

uint8_t rev_byte_simple(uint8_t byte)
{
  uint8_t ret = 0;
  for(int i=0; i<8; i++){
    ret |= ((byte >> i) & 1) << (7 - i);
  }
  return ret;
}

uint8_t rev_byte(uint8_t byte)
{
  byte = ((byte & 0xf0) >> 4) | ((byte & 0x0f) << 4);
  byte = ((byte & 0xcc) >> 2) | ((byte & 0x33) << 2);
  byte = ((byte & 0xaa) >> 1) | ((byte & 0x55) << 1);
  return byte;
}

void flip(vector<uint8_t>& monochrome, int width, int height) {
  int cols = width / 8;
  for(int r = 0; r < height; r++){
    int from = r * cols;
    int to = (r+1) * cols - 1;
    while (from < to) {
      swap(monochrome[from], monochrome[to]);
      monochrome[from] = rev_byte(monochrome[from]);
      monochrome[to] = rev_byte(monochrome[to]);
      from++;
      to--;
    }
  }
}
