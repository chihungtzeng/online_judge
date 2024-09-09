#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  RandomizedCollection* obj = new RandomizedCollection();
  EXPECT_TRUE(obj->insert(1));
  EXPECT_FALSE(obj->insert(1));
  EXPECT_TRUE(obj->insert(2));
  auto ret = obj->getRandom();
  LOG(INFO) << "prob(1) = 2/3, prob(2) = 1/3";
  for (int i = 0; i < 10; i++) {
    LOG(INFO) << "getRandom: " << obj->getRandom();
  }
  EXPECT_TRUE(ret == 1 || ret == 2);
  EXPECT_TRUE(obj->remove(1));
  LOG(INFO) << "prob(1) = 1/2, prob(2) = 1/2";
  for (int i = 0; i < 10; i++) {
    LOG(INFO) << "getRandom: " << obj->getRandom();
  }

  delete obj;
}

TEST(kk, t2) {
  RandomizedCollection* obj = new RandomizedCollection();
  EXPECT_TRUE(obj->insert(1));
  EXPECT_TRUE(obj->insert(2));
  EXPECT_FALSE(obj->insert(2));
  EXPECT_TRUE(obj->cached_idx_.find(1)->second.size() == 1);
  EXPECT_TRUE(obj->cached_idx_.find(2)->second.size() == 2);
  LOG(INFO) << obj->vals_;
  EXPECT_TRUE(obj->remove(2));
  LOG(INFO) << obj->vals_;
  EXPECT_TRUE(obj->remove(2));
  LOG(INFO) << obj->vals_;
  EXPECT_TRUE(obj->cached_idx_.find(1)->second.size() == 1);
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(obj->getRandom(), 1);
  }

  delete obj;
}

void dump_cached_idx(unordered_map<int, unordered_set<int>>& cached_idx){
  for (auto &[key, idxes]: cached_idx){
    std::cout << "key: " << key << " idx: ";
    for(auto idx: idxes) {
      std::cout << idx << ' ';
    }
    std::cout << '\n';
  }
}

TEST(kk, t3) {
  RandomizedCollection* obj = new RandomizedCollection();
  LOG(INFO) << "insert 1";
  obj->insert(1);
  LOG(INFO) << obj->vals_;
  dump_cached_idx(obj->cached_idx_);
  EXPECT_TRUE(obj->cached_idx_.find(1)->second.size() == 1);

  LOG(INFO) << "remove 1";
  obj->remove(1);
  LOG(INFO) << obj->vals_;
  dump_cached_idx(obj->cached_idx_);
  EXPECT_EQ(obj->vals_.size(), 0);
  EXPECT_TRUE(obj->cached_idx_.find(1) == obj->cached_idx_.end());

  delete obj;
}

TEST(kk, t4) {
  RandomizedCollection* obj = new RandomizedCollection();
  LOG(INFO) << "insert 0 and 1";
  EXPECT_TRUE(obj->insert(0));
  EXPECT_TRUE(obj->insert(1));
  LOG(INFO) << obj->vals_;
  dump_cached_idx(obj->cached_idx_);

  EXPECT_TRUE(obj->cached_idx_.find(0)->second.size() == 1);
  EXPECT_TRUE(obj->cached_idx_.find(1)->second.size() == 1);

  LOG(INFO) << "rm 0";
  EXPECT_TRUE(obj->remove(0));
  LOG(INFO) << obj->vals_;
  dump_cached_idx(obj->cached_idx_);


  LOG(INFO) << "insert 0";
  EXPECT_TRUE(obj->insert(2));
  LOG(INFO) << obj->vals_;

  dump_cached_idx(obj->cached_idx_);
  EXPECT_TRUE(obj->cached_idx_.find(1)->second.size() == 1);
  EXPECT_TRUE(obj->cached_idx_.find(2)->second.size() == 1);

  EXPECT_TRUE(obj->remove(1));
  EXPECT_TRUE(obj->cached_idx_.find(2)->second.size() == 1);
  LOG(INFO) << obj->vals_;


  EXPECT_EQ(obj->getRandom(), 2);

  delete obj;
}

TEST(kk, t5) {
  RandomizedCollection* obj = new RandomizedCollection();
  EXPECT_TRUE(obj->insert(0));
  EXPECT_TRUE(obj->remove(0));
  EXPECT_TRUE(obj->insert(-1));
  EXPECT_FALSE(obj->remove(0));
  EXPECT_EQ(obj->getRandom(), -1);

  delete obj;
}

