#include <algorithm>
#include <cstdint>
#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  string getHint(const string &secret, const string &guess) {
    int bulls = 0;
    int cows = 0;
    int len = secret.length();
    std::vector<int> sdigits(10, 0);
    std::vector<int> gdigits(10, 0);

    for(int i=0; i<len; i++)
    {
      if (secret[i] == guess[i])
      {
        bulls++;
      }
      else
      {
        sdigits[secret[i] - '0']++;
        gdigits[guess[i] - '0']++;
      }
    }
    for(int i=0; i<10;i++)
    {
      cows += min(sdigits[i], gdigits[i]);
    }
    return to_string(bulls) + 'A' + to_string(cows) + 'B';
  }
};
