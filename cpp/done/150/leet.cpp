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

class Solution
{
public:
  int evalRPN(vector<string>& tokens)
  {
    vector<int64_t> st;
    for (auto& token : tokens)
    {
      if (isdigit(token))
      {
        st.push_back(stoi(token));
      }
      else
      {
        auto last = st.back();
        st.pop_back();
        auto second = st.back();
        st.pop_back();
        if (token[0] == '/')
        {
          st.push_back(second / last);
        }
        else if (token[0] == '*')
        {
          st.push_back(second * last);
        }
        else if (token[0] == '+')
        {
          st.push_back(second + last);
        }
        else if (token[0] == '-')
        {
          st.push_back(second - last);
        }
      }
    }
    return st.back();
  }
  bool isdigit(string& token)
  {
    if (token[0] >= '0' && token[0] <= '9')
      return true;
    else if (token[0] == '-' && token.size() > 1)
      return true;
    else
      return false;
  }
};
