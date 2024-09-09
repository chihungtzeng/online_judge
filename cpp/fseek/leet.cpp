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
#include <stdio.h>
#include <unistd.h>
using namespace std;

class FR {
  public:
  FILE *fp;
  FR(const string& fname) {
    fp = fopen(fname.c_str(), "r");
  }
  int read(char* buf, size_t len) {
    int nread = fread(static_cast<void *>(buf), sizeof(char), len, fp);
    return nread;
  }
  ~FR() {
    if (fp) {fclose(fp);}
  }
};
