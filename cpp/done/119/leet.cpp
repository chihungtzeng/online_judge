#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> prev, cur;
    prev.reserve(34);
    cur.reserve(34);
    cur.push_back(1);
    for (int i = 1; i <= rowIndex; i++) {
      prev = std::move(cur);
      cur.clear();
      cur.push_back(1);
      for (int j = 1; j <= i - 1; j++) {
        cur.push_back(prev[j] + prev[j - 1]);
      }
      cur.push_back(1);
    }
    return cur;
  }
};
