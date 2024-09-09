#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  int n = 3, discount = 50;
  vector<int> products = {1, 2, 3, 4, 5, 6, 7},
              prices = {100, 200, 300, 400, 300, 200, 100};
  Cashier* obj = new Cashier(n, discount, products, prices);
  vector<int> product = {1, 2}, amount = {1, 2};
  EXPECT_EQ(abs(obj->getBill(product, amount) - 500.0) <= 0.00001, true);
  product = {3, 7};
  amount = {10, 10};
  EXPECT_EQ(abs(obj->getBill(product, amount) - 4000.0) <= 0.00001, true);

  product = {1, 2, 3, 4, 5, 6, 7};
  amount = {1, 1, 1, 1, 1, 1, 1};
  EXPECT_EQ(abs(obj->getBill(product, amount) - 800.0) <= 0.00001, true);

  product = {4};
  amount = {10};
  EXPECT_EQ(abs(obj->getBill(product, amount) - 4000.0) <= 0.00001, true);


  delete obj;
}

