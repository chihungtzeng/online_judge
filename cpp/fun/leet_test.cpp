#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  string s;
  s.push_back('b');
  s.push_back('\1');
  s.push_back('a');
  s += "中文";
  s.push_back('z');
  LOG(INFO) << s << "**size: " << s.size();
  LOG(INFO) << "++" << s[1] << "--";
}

TEST(kk, t2)
{
  double pi = 3.14;
  double e = 2.78;
  double minus_pi = -pi;
  double minus_e = -e;
  double f = 0.77;
  LOG(INFO) << pi << "-> " << int(pi) << ", " << minus_pi << " -> " << int(minus_pi);
  LOG(INFO) << e << "-> " << int(e) << ", " << minus_e << " -> " << int(minus_e);
  LOG(INFO) << f << "-> " << int(f) << ", " << -f << " -> " << int(-f);
}

TEST(kk, t3)
{
  std::shared_ptr<int> ptr{ new int(17) };
  ptr = ptr;
  LOG(INFO) << "*ptr = " << *ptr;
}

using ituple = tuple<int, int, int>;
TEST(kk, t4)
{
  ituple a{ 1, 3, 6 };
  LOG(INFO) << get<2>(a);
}

TEST(kk, t5)
{
  string in = "x+5-3+x=6+x-2";
  istringstream iss(in);
  vector<string> tokens;
  string token;
  while (getline(iss, token, '='))
  {
    tokens.push_back(token);
  }
  LOG(INFO) << tokens;
}

TEST(kk, t6)
{
  //               0   1  2  3  4  5  6  7  8  9  10 11 12 13
  vector<int> vs{ -1, -1, 0, 0, 0, 1, 2, 3, 3, 3, 3, 3, 4, 5 };
  auto it = lower_bound(vs.begin(), vs.end(), 3);
  int dist = it - vs.begin();
  auto it2 = lower_bound(vs.begin() + 2, vs.end(), 3);
  int dist2 = it2 - vs.begin();
  LOG(INFO) << "dist: " << dist << ", " << dist2;
  auto it3 = upper_bound(vs.begin(), vs.end(), 3);
  int dist3 = it3 - vs.begin();
  LOG(INFO) << "dist3: " << dist3;
}

TEST(kk, t7)
{
  vector<int> vs{ 3, 1, 4, 5 };
  vector<double> rvs{ vs.begin(), vs.end() };
  LOG(INFO) << rvs[2] / 3;
}

TEST(kk, t8)
{
  vector<int> vs{ 1, 5, 4 };
  vector<int> vs2{ 3, 1, 333, 5 };
  vector<int> vs3{ 1, 5, 4, 1 };
  EXPECT_EQ(vs < vs2, true);
  EXPECT_EQ(vs < vs3, true);
}

TEST(kk, t9)
{
  int a = 7, b = -3, c = 0, r = 0;
  c = a / b;
  r = a % b;
  LOG(INFO) << a << " / " << b << " = " << c << "; " << a << " % " << b << " = " << r;
  a = -7;
  b = 3;
  c = a / b;
  r = a % b;
  LOG(INFO) << a << " / " << b << " = " << c << "; " << a << " % " << b << " = " << r;

  a = -7;
  b = -3;
  c = a / b;
  r = a % b;
  LOG(INFO) << a << " / " << b << " = " << c << "; " << a << " % " << b << " = " << r;
}

TEST(kk, t10)
{
  CarState cs1(1), cs2(2);
  priority_queue<CarState, vector<CarState>, greater<>> pq;
  pq.push(cs2);
  pq.push(cs1);
  while (!pq.empty())
  {
    auto cs = pq.top();
    pq.pop();
    LOG(INFO) << "car state: steps: " << cs.steps;
  }
}

TEST(kk, t11)
{
  using ituple = tuple<int, int, int, int>;
  map<ituple, int> cache;
  // unordered_map<CarState, int> cache2; // TODO
}

TEST(kk, memcpy_v1)
{
  const int n = (1 << 20) + 6;
  uint8_t* dest = new uint8_t[n];
  uint8_t* src = new uint8_t[n];
  for (int i = 0; i < n; i++)
  {
    src[i] = i & 0xff;
  }
  for (int i = 0; i < 100; i++)
  {
    my_memcpy_v1(dest, src, n);
  }

  /*
    for(int i=0; i<n; i++){
      EXPECT_EQ(dest[i], i & 0xff);
    }
  */
  delete[] dest;
  delete[] src;
}

TEST(kk, memcpy_v2)
{
  const int n = (1 << 20) + 6;
  uint8_t* dest = new uint8_t[n];
  uint8_t* src = new uint8_t[n];
  for (int i = 0; i < n; i++)
  {
    src[i] = i & 0xff;
  }
  for (int i = 0; i < 100; i++)
  {
    my_memcpy_v2(dest, src, n);
  }

  /*
    for(int i=0; i<n; i++){
      EXPECT_EQ(dest[i], i & 0xff);
    }
  */
  delete[] dest;
  delete[] src;
}

TEST(kk, memcpy_v3)
{
  const int n = (1 << 20) + 6;
  uint8_t* dest = new uint8_t[n];
  uint8_t* src = new uint8_t[n];
  for (int i = 0; i < n; i++)
  {
    src[i] = i & 0xff;
  }
  for (int i = 0; i < 100; i++)
  {
    my_memcpy_v3(dest, src, n);
  }

  /*
    for(int i=0; i<n; i++){
      EXPECT_EQ(dest[i], i & 0xff);
    }
    */
  delete[] dest;
  delete[] src;
}

TEST(kk, memcpy_v4)
{
  const int n = (1 << 20) + 6;
  uint8_t* dest = new uint8_t[n];
  uint8_t* src = new uint8_t[n];
  for (int i = 0; i < n; i++)
  {
    src[i] = i & 0xff;
  }
  for (int i = 0; i < 100; i++)
  {
    my_memcpy_v4(dest, src, n);
  }

  /*
    for(int i=0; i<n; i++){
      EXPECT_EQ(dest[i], i & 0xff);
    }
    */
  delete[] dest;
  delete[] src;
}

TEST(kk, memcpy_builtin)
{
  const int n = (1 << 20) + 6;
  uint8_t* dest = new uint8_t[n];
  uint8_t* src = new uint8_t[n];
  for (int i = 0; i < n; i++)
  {
    src[i] = i & 0xff;
  }
  for (int i = 0; i < 100; i++)
  {
    memcpy(dest, src, n);
  }

  /*
    for(int i=0; i<n; i++){
      EXPECT_EQ(dest[i], i & 0xff);
    }
    */
  delete[] dest;
  delete[] src;
}

TEST(kk, memmove_builtin)
{
  char buf[100] = "hellokitty+leetcode";
  for (int i = 0; i < 10000000; i++)
  {
    memmove(buf + 8, buf, 11);
  }
  LOG(INFO) << "buf: " << buf;
  LOG(INFO) << "buf + 8: " << buf + 8;
}

TEST(kk, memmove_v1)
{
  char buf[100] = "hellokitty+leetcode";
  for (int i = 0; i < 10000000; i++)
  {
    my_memmove_v1(buf + 8, buf, 11);
  }
  LOG(INFO) << "buf: " << buf;
  LOG(INFO) << "buf + 8: " << buf + 8;
}

TEST(kk, memmove_v2)
{
  char buf[100] = "hellokitty+leetcode";
  for (int i = 0; i < 10000000; i++)
  {
    my_memmove_v2(buf + 8, buf, 11);
  }
  LOG(INFO) << "buf: " << buf;
  LOG(INFO) << "buf + 8: " << buf + 8;
}

TEST(kk, mymalloc2d)
{
  const int row = 3, col = 4;
  int** ptr = mymalloc2d(row, col);
  int val = 0;
  for (int r = 0; r < row; r++)
  {
    for (int c = 0; c < col; c++)
    {
      ptr[r][c] = val++;
    }
  }
  for (int r = 0; r < row; r++)
  {
    for (int c = 0; c < col; c++)
    {
      printf("%d ", ptr[r][c]);
    }
    printf("\n");
  }
  myfree2d(ptr);
}

TEST(kk, perf_mymalloc2d)
{
  const int row = 1024, col = 64;
  for (int i = 0; i < 1000; i++)
  {
    int** ptr = mymalloc2d(row, col);
    myfree2d(ptr);
  }
}

TEST(kk, mymalloc2d_v2)
{
  const int row = 3, col = 4;
  int** ptr = mymalloc2d_v2(row, col);
  int val = 0;
  for (int r = 0; r < row; r++)
  {
    for (int c = 0; c < col; c++)
    {
      ptr[r][c] = val++;
    }
  }
  for (int r = 0; r < row; r++)
  {
    for (int c = 0; c < col; c++)
    {
      printf("%d ", ptr[r][c]);
    }
    printf("\n");
  }
  myfree2d_v2(ptr);
}

TEST(kk, perf_mymalloc2d_v2)
{
  const int row = 1024, col = 64;
  for (int i = 0; i < 1000; i++)
  {
    int** ptr = mymalloc2d_v2(row, col);
    myfree2d_v2(ptr);
  }
}

TEST(kk, kth_element)
{
  int prime = 19;
  int val = 15;
  vector<int> nums;
  for (int i = 0; i < prime; i++)
  {
    val = (val + 7) % prime;
    nums.push_back(val);
  }
  LOG(INFO) << "before: " << nums;

  int k = 10;
  nth_element(nums.begin(), nums.begin() + k, nums.end());
  LOG(INFO) << "after:  " << nums;
  LOG(INFO) << k << "th number: " << nums[k];
}

