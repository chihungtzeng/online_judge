#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool validUtf8(vector<int>& data) {
    vector<uint8_t> bytes(data.size());
    for (size_t i = 0; i < data.size(); i++) {
      bytes[i] = data[i] & 0xff;
    }
    size_t pos = 0, len = 1;
    while (pos < bytes.size()) {
      len = calc_len(bytes[pos]);
      /*
      for(size_t i=pos; i<pos+len; i++){
        cout << std::hex << "0x" << static_cast<int>(bytes[i]) << ' ';
      }
      cout << '\n';
      */
      if (len == 0) {
        //        LOG(INFO) << "len == 0";
        return false;
      }
      if (pos + len - 1 >= bytes.size()) {
        //        LOG(INFO) << "OOB";
        return false;
      }
      if (!valid(bytes, pos, len)) {
        //        LOG(INFO) << "invalid seq";
        return false;
      }
      pos += len;
    }
    return true;
  }
  size_t calc_len(uint8_t val) {
    if ((val >> 7) == 0) {
      return 1;
    }
    if ((val >> 5) == 6) {
      return 2;
    }
    if ((val >> 4) == 14) {
      return 3;
    }
    if ((val >> 3) == 0x1e) {
      return 4;
    }
    return 0;
  }
  bool valid(vector<uint8_t>& bytes, size_t pos, size_t len) {
    if (len == 1) {
      return bool(bytes[pos] <= 0x7f);
    }
    if (len == 2) {
      return bool((bytes[pos] >> 5) == 6 && (bytes[pos + 1] >> 6) == 2);
    }
    if (len == 3) {
      return bool((bytes[pos] >> 4) == 0xe && (bytes[pos + 1] >> 6) == 2 &&
                  (bytes[pos + 2] >> 6) == 2);
    }
    if (len == 4) {
      return bool((bytes[pos] >> 3) == 0x1e && (bytes[pos + 1] >> 6) == 2 &&
                  (bytes[pos + 2] >> 6) == 2 && (bytes[pos + 3] >> 6) == 2);
    }
    return false;
  }
};
