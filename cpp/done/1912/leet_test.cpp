#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  int n = 3;
  vector<vector<int>> entries{ { 0, 1, 5 }, { 0, 2, 6 }, { 0, 3, 7 }, { 1, 1, 4 }, { 1, 2, 7 }, { 2, 1, 5 } };
  MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
  vector<int> expect{ 1, 0, 2 };
  EXPECT_EQ(obj->search(1), expect);

  obj->rent(0, 1);
  obj->rent(1, 2);

  vector<vector<int>> expect_2{ { 0, 1 }, { 1, 2 } };
  EXPECT_EQ(obj->report(), expect_2);

  obj->drop(1, 2);
  vector<int> expect2{ 0, 1 };

  EXPECT_EQ(obj->search(2), expect2);

  delete obj;
}

TEST(kk, t2)
{
  int n = 48;
  vector<vector<int>> entries{ { 4, 657, 2689 },   { 8, 8082, 9308 },  { 36, 8093, 3375 }, { 39, 2436, 5876 },
                               { 13, 2098, 1501 }, { 20, 2502, 5453 }, { 31, 9770, 3724 }, { 19, 9926, 1908 },
                               { 2, 3222, 9725 },  { 32, 6946, 3049 }, { 42, 9360, 3552 }, { 39, 1893, 327 },
                               { 38, 7490, 4119 }, { 33, 1903, 7618 }, { 5, 3658, 7669 },  { 2, 1714, 6884 },
                               { 25, 615, 5890 },  { 4, 9477, 5027 },  { 24, 9147, 3680 }, { 44, 3602, 8826 },
                               { 32, 2575, 120 },  { 14, 9926, 8095 }, { 21, 3653, 7166 }, { 30, 5684, 7950 },
                               { 32, 1610, 1584 }, { 35, 2355, 7358 }, { 45, 5575, 8235 }, { 2, 1684, 1911 },
                               { 26, 8860, 8316 }, { 36, 6275, 5118 }, { 9, 9770, 8928 },  { 9, 9954, 6629 },
                               { 43, 9926, 9738 }, { 6, 5431, 6661 },  { 16, 6774, 1165 } };
  MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
  auto a1 = obj->search(3223);
  vector<int> e1 = {};
  EXPECT_EQ(a1, e1);
  obj->rent(20, 2502);
  obj->drop(20, 2502);
  auto a4 = obj->report();
  vector<vector<int>> e4 = {};
  EXPECT_EQ(a4, e4);
  auto a5 = obj->report();
  vector<vector<int>> e5 = {};
  EXPECT_EQ(a5, e5);
  obj->rent(2, 1684);
  obj->rent(31, 9770);
  obj->rent(6, 5431);
  auto a9 = obj->search(1714);
  vector<int> e9 = { 2 };
  EXPECT_EQ(a9, e9);
  auto a10 = obj->report();
  vector<vector<int>> e10 = { { 2, 1684 }, { 31, 9770 }, { 6, 5431 } };
  EXPECT_EQ(a10, e10);
  obj->drop(2, 1684);
  obj->rent(2, 3222);
  auto a13 = obj->search(633);
  vector<int> e13 = {};
  EXPECT_EQ(a13, e13);
  auto a14 = obj->report();
  vector<vector<int>> e14 = { { 31, 9770 }, { 6, 5431 }, { 2, 3222 } };
  EXPECT_EQ(a14, e14);
  obj->rent(25, 615);
  auto a16 = obj->report();
  vector<vector<int>> e16 = { { 31, 9770 }, { 25, 615 }, { 6, 5431 }, { 2, 3222 } };
  EXPECT_EQ(a16, e16);
  obj->rent(19, 9926);
  obj->drop(6, 5431);
  obj->rent(38, 7490);
  obj->rent(16, 6774);
  auto a21 = obj->search(294);
  vector<int> e21 = {};
  EXPECT_EQ(a21, e21);
  obj->rent(14, 9926);
  auto a23 = obj->search(2375);
  vector<int> e23 = {};
  EXPECT_EQ(a23, e23);
  obj->drop(16, 6774);
  obj->drop(19, 9926);
  obj->drop(14, 9926);
  obj->drop(25, 615);
  obj->drop(38, 7490);
  obj->rent(13, 2098);
  auto a30 = obj->search(6231);
  vector<int> e30 = {};
  EXPECT_EQ(a30, e30);
  auto a31 = obj->report();
  vector<vector<int>> e31 = { { 13, 2098 }, { 31, 9770 }, { 2, 3222 } };
  EXPECT_EQ(a31, e31);
  obj->rent(5, 3658);
  auto a33 = obj->report();
  vector<vector<int>> e33 = { { 13, 2098 }, { 31, 9770 }, { 5, 3658 }, { 2, 3222 } };
  EXPECT_EQ(a33, e33);
  obj->rent(16, 6774);
  obj->rent(9, 9770);
  auto a36 = obj->search(9032);
  vector<int> e36 = {};
  EXPECT_EQ(a36, e36);
  obj->rent(20, 2502);
  auto a38 = obj->search(2402);
  vector<int> e38 = {};
  EXPECT_EQ(a38, e38);
  obj->drop(2, 3222);
  auto a40 = obj->report();
  vector<vector<int>> e40 = { { 16, 6774 }, { 13, 2098 }, { 31, 9770 }, { 20, 2502 }, { 5, 3658 } };
  EXPECT_EQ(a40, e40);
  auto a41 = obj->report();
  vector<vector<int>> e41 = { { 16, 6774 }, { 13, 2098 }, { 31, 9770 }, { 20, 2502 }, { 5, 3658 } };
  EXPECT_EQ(a41, e41);
  auto a42 = obj->search(5575);
  vector<int> e42 = { 45 };
  EXPECT_EQ(a42, e42);
  auto a43 = obj->report();
  vector<vector<int>> e43 = { { 16, 6774 }, { 13, 2098 }, { 31, 9770 }, { 20, 2502 }, { 5, 3658 } };
  EXPECT_EQ(a43, e43);
  obj->drop(13, 2098);
  auto a45 = obj->report();
  vector<vector<int>> e45 = { { 16, 6774 }, { 31, 9770 }, { 20, 2502 }, { 5, 3658 }, { 9, 9770 } };
  EXPECT_EQ(a45, e45);
  auto a46 = obj->search(4736);
  vector<int> e46 = {};
  EXPECT_EQ(a46, e46);
  auto a47 = obj->search(2575);
  vector<int> e47 = { 32 };
  EXPECT_EQ(a47, e47);
  auto a48 = obj->search(4233);
  vector<int> e48 = {};
  EXPECT_EQ(a48, e48);
  obj->rent(36, 8093);
  auto a50 = obj->search(6968);
  vector<int> e50 = {};
  EXPECT_EQ(a50, e50);
  auto a51 = obj->search(1684);
  vector<int> e51 = { 2 };
  EXPECT_EQ(a51, e51);
  auto a52 = obj->report();
  vector<vector<int>> e52 = { { 16, 6774 }, { 36, 8093 }, { 31, 9770 }, { 20, 2502 }, { 5, 3658 } };
  EXPECT_EQ(a52, e52);
  obj->rent(32, 6946);
  obj->drop(16, 6774);
  auto a55 = obj->search(6865);
  vector<int> e55 = {};
  EXPECT_EQ(a55, e55);
  obj->drop(20, 2502);
  auto a57 = obj->report();
  vector<vector<int>> e57 = { { 32, 6946 }, { 36, 8093 }, { 31, 9770 }, { 5, 3658 }, { 9, 9770 } };
  EXPECT_EQ(a57, e57);
  obj->rent(9, 9954);
  auto a59 = obj->search(6946);
  vector<int> e59 = {};
  EXPECT_EQ(a59, e59);
  obj->rent(2, 1684);
  obj->rent(32, 2575);
  obj->rent(44, 3602);
  obj->drop(9, 9954);
  auto a64 = obj->search(4074);
  vector<int> e64 = {};
  EXPECT_EQ(a64, e64);
  obj->rent(26, 8860);
  obj->drop(44, 3602);
  obj->rent(14, 9926);
  obj->drop(9, 9770);
  obj->drop(32, 6946);
  auto a70 = obj->search(6770);
  vector<int> e70 = {};
  EXPECT_EQ(a70, e70);
  obj->rent(32, 6946);
  obj->rent(4, 657);
  obj->drop(5, 3658);
  auto a74 = obj->search(2375);
  vector<int> e74 = {};
  EXPECT_EQ(a74, e74);
  auto a75 = obj->report();
  vector<vector<int>> e75 = { { 32, 2575 }, { 2, 1684 }, { 4, 657 }, { 32, 6946 }, { 36, 8093 } };
  EXPECT_EQ(a75, e75);
  obj->drop(31, 9770);
  auto a77 = obj->search(6732);
  vector<int> e77 = {};
  EXPECT_EQ(a77, e77);
  auto a78 = obj->search(5493);
  vector<int> e78 = {};
  EXPECT_EQ(a78, e78);
  auto a79 = obj->search(9213);
  vector<int> e79 = {};
  EXPECT_EQ(a79, e79);
  auto a80 = obj->report();
  vector<vector<int>> e80 = { { 32, 2575 }, { 2, 1684 }, { 4, 657 }, { 32, 6946 }, { 36, 8093 } };
  EXPECT_EQ(a80, e80);
  auto a81 = obj->report();
  vector<vector<int>> e81 = { { 32, 2575 }, { 2, 1684 }, { 4, 657 }, { 32, 6946 }, { 36, 8093 } };
  EXPECT_EQ(a81, e81);
  obj->drop(32, 2575);
  auto a83 = obj->search(2575);
  vector<int> e83 = { 32 };
  EXPECT_EQ(a83, e83);
  obj->rent(32, 1610);
  auto a85 = obj->report();
  vector<vector<int>> e85 = { { 32, 1610 }, { 2, 1684 }, { 4, 657 }, { 32, 6946 }, { 36, 8093 } };
  EXPECT_EQ(a85, e85);
  auto a86 = obj->report();
  vector<vector<int>> e86 = { { 32, 1610 }, { 2, 1684 }, { 4, 657 }, { 32, 6946 }, { 36, 8093 } };
  EXPECT_EQ(a86, e86);
  obj->drop(4, 657);
  obj->drop(36, 8093);
  obj->drop(2, 1684);
  obj->drop(26, 8860);
  auto a91 = obj->search(2574);
  vector<int> e91 = {};
  EXPECT_EQ(a91, e91);
  auto a92 = obj->search(9842);
  vector<int> e92 = {};
  EXPECT_EQ(a92, e92);
  auto a93 = obj->search(5431);
  vector<int> e93 = { 6 };
  EXPECT_EQ(a93, e93);
  obj->drop(14, 9926);
  auto a95 = obj->search(6865);
  vector<int> e95 = {};
  EXPECT_EQ(a95, e95);
  auto a96 = obj->search(8141);
  vector<int> e96 = {};
  EXPECT_EQ(a96, e96);
  obj->drop(32, 1610);
  auto a98 = obj->report();
  vector<vector<int>> e98 = { { 32, 6946 } };
  EXPECT_EQ(a98, e98);
  obj->rent(43, 9926);

  delete obj;
}

