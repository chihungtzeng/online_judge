#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t0)
{
  Bitset* obj = new Bitset(64);
  obj->fix(3);
  EXPECT_EQ(obj->count(), 1);
  obj->flip();
  EXPECT_EQ(obj->count(), 63);

  delete obj;
}


TEST(kk, t1)
{
  Bitset* obj = new Bitset(5);
  obj->fix(3);
  obj->fix(1);

  obj->flip();
  EXPECT_EQ(obj->all(), false);
  EXPECT_EQ(obj->one(), true);
  obj->unfix(0);
  obj->flip();
  EXPECT_EQ(obj->one(), true);
  obj->unfix(0);
  EXPECT_EQ(obj->count(), 2);
  EXPECT_EQ(obj->toString(), "01010");

  delete obj;
}

TEST(kk, t2)
{
  int size = 64 + 50;
  Bitset* obj = new Bitset(size);
  obj->fix(90);
  obj->fix(89);

  //LOG(INFO) << obj->toString();
  obj->flip();
  auto s = obj->toString();
  //LOG(INFO) << s;
  EXPECT_EQ(s.size(), size);
  EXPECT_EQ(obj->count(), size - 2);
  delete obj;
}

TEST(kk, t3)
{
  int size = 100000;
  Bitset* obj = new Bitset(size);
  obj->fix(90);
  obj->fix(89);

  int pos = 0;
  string s;
  for (int i = 0; i < 1000; i++)
  {
    pos = (pos + 1) % size;
    obj->fix(pos);
    pos = (pos + 1) % size;
    obj->unfix(pos);
    obj->flip();
    obj->count();
    obj->one();
    obj->all();
  s = obj->toString();
  }
  delete obj;
}

int num_one(string& s)
{
  int ans = 0;
  for(auto ch: s){
    ans += ch - '0';
  }
  return ans;
}

TEST(kk, t4)
{
  int size = 6720;
  Bitset* obj = new Bitset(size);
  string s;
  obj->fix(4182);
  s = obj->toString();
  EXPECT_EQ(s[4182], '1');
  EXPECT_EQ(num_one(s), 1);
  EXPECT_EQ(obj->count(), 1);

  obj->flip();
  s = obj->toString();
  EXPECT_EQ(s[4182], '0');
  EXPECT_EQ(num_one(s), size - 1);
  EXPECT_EQ(obj->count(), size-1);
  // LOG(INFO) << s;

  obj->fix(6507);
  EXPECT_EQ(obj->count(), size-1);

  obj->toString();
  obj->count();
  obj->toString();
  obj->fix(1947);
  obj->count();
  obj->one();
  obj->fix(6395);
  obj->count();
  obj->toString();
  obj->fix(1686);
  obj->unfix(1139);
  obj->unfix(2596);
  obj->flip();
  obj->fix(4483);
  obj->all();
  obj->one();
  obj->all();
  obj->unfix(1989);
  obj->one();
  obj->flip();
  obj->count();
  obj->fix(315);
  obj->all();
  obj->one();
  obj->fix(4498);
  obj->flip();
  obj->flip();
  obj->count();
  obj->one();
  obj->all();
  obj->flip();
  obj->all();
  obj->one();
  obj->all();
  obj->count();
  obj->unfix(629);
  obj->count();
  obj->fix(681);
  obj->one();
  obj->count();
  obj->all();
  obj->all();
  obj->fix(5561);
  obj->one();
  obj->flip();
  obj->fix(6293);
  obj->all();
  obj->one();
  obj->all();
  obj->unfix(2529);
  obj->all();
  obj->flip();
  obj->flip();
  obj->count();
  obj->count();
  obj->unfix(5715);
  obj->one();
  obj->unfix(3163);
  obj->unfix(3813);
  obj->fix(6012);
  obj->count();
  obj->one();
  obj->fix(4553);
  obj->all();
  obj->one();
  obj->flip();
  obj->unfix(5507);
  obj->all();
  obj->all();
  obj->fix(3195);
  obj->unfix(5580);
  obj->all();
  obj->fix(725);
  obj->unfix(3826);
  obj->flip();
  obj->one();
  obj->unfix(3952);
  obj->all();
  obj->count();
  obj->fix(3894);
  obj->flip();
  obj->flip();
  obj->flip();
  obj->all();
  obj->fix(3975);
  obj->fix(2095);
  obj->flip();
  obj->count();
  obj->fix(786);
  obj->flip();
  obj->count();
  obj->unfix(3945);
  obj->fix(428);
  obj->fix(2008);
  obj->fix(2414);
  obj->all();
  obj->all();
  obj->fix(4322);
  obj->count();
  obj->one();
  obj->count();
  obj->unfix(4519);
  obj->flip();
  obj->one();
  obj->fix(4949);
  obj->flip();
  obj->fix(4349);
  obj->unfix(5549);
  obj->one();
  obj->count();
  obj->count();
  obj->unfix(321);
  obj->fix(302);
  obj->fix(4894);
  obj->fix(4847);
  obj->count();
  obj->one();
  obj->unfix(6122);
  obj->unfix(3421);
  obj->count();
  obj->count();
  obj->one();
  obj->all();
  obj->one();
  obj->unfix(2348);
  obj->flip();
  obj->fix(2476);
  obj->one();
  obj->one();
  obj->flip();
  obj->count();
  obj->flip();
  obj->count();
  obj->unfix(4645);
  obj->unfix(4437);
  obj->fix(1225);
  obj->flip();
  obj->count();
  obj->flip();
  obj->unfix(6068);
  obj->unfix(3862);
  obj->flip();
  obj->all();
  obj->unfix(3613);
  obj->one();
  obj->fix(1627);
  obj->count();
  obj->fix(6093);
  obj->one();
  obj->count();
  obj->all();
  obj->unfix(3712);
  obj->flip();
  obj->flip();
  obj->all();
  obj->flip();
  obj->one();
  obj->all();
  obj->count();
  obj->unfix(4044);
  obj->all();

  delete obj;
}

