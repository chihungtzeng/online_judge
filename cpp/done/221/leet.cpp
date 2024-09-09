#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return 0;
    int cols = matrix[0].size();
    if (cols == 0) return 0;
    vector<int> height(cols);
    int res = 0;
    for(int r=0; r<rows; r++)
    {
      for(int c=0; c<cols; c++){
        if (matrix[r][c] == '0') {
          height[c] = 0;
        }
        else {
          height[c] += 1;
        }

      }
      res = std::max(res, max_rect(height));
    }

  return res; 
  }
  int max_rect(const vector<int>& height)
  {
    int cols = height.size();
    vector<int> left(cols), right(cols);
    vector<int> stack;
    stack.reserve(cols);
    left[0] = -1;
    stack.push_back(0);
    for(int c=1; c< cols; c++){
      while(!stack.empty() && height[c] <= height[stack.back()]){
        stack.pop_back();
      }
      if (stack.empty()) {
        left[c] = -1;
      }
      else {
        left[c] = stack.back();
      }
      stack.push_back(c);
    }
    stack.clear();
    right[cols-1] = cols;
    stack.push_back(cols-1);
    for(int c=cols-2; c>=0; c--)
    {
      while(!stack.empty() && height[c]<=height[stack.back()])
      {
        stack.pop_back();
      }
      if (stack.empty()){
        right[c] = cols;
      } else {
        right[c] = stack.back();
      }
      stack.push_back(c);
    }
    int area = 0;
    for(int c=0; c<cols;c++)
    {
      auto len = std::min(height[c], right[c] - left[c] - 1);
      area = std::max(area, len * len);
    }
    return area;
  }
};
