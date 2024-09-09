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

using ipair = pair<int, int>;
using ituple = tuple<int, int, int>;
class MovieRentingSystem
{
public:
  unordered_map<int, unordered_map<int, int>> prices;
  unordered_map<int, unordered_map<int, bool>> is_rented;
  unordered_map<int, set<ipair>> movies;
  set<ituple> rented;

  MovieRentingSystem(int n, vector<vector<int>>& entries)
  {
    for (int i = 0, n=entries.size(); i < n; i++)
    {
      int shop = entries[i][0];
      int movie = entries[i][1];
      int price = entries[i][2];
      prices[movie][shop] = price;
      is_rented[movie][shop] = false;
      movies[movie].insert({ price, shop });
    }
  }

  vector<int> search(int movie)
  {
    vector<int> shops;
    shops.reserve(5);
    for (const auto& [price, shop] : movies[movie])
    {
      if (!is_rented[movie][shop])
      {
        shops.push_back(shop);
      }
      if (shops.size() == 5)
      {
        break;
      }
    }
    return shops;
  }

  void rent(int shop, int movie)
  {
    is_rented[movie][shop] = true;
    rented.insert({ prices[movie][shop], shop, movie });
  }

  void drop(int shop, int movie)
  {
    is_rented[movie][shop] = false;
    rented.erase({ prices[movie][shop], shop, movie });
  }

  vector<vector<int>> report()
  {
    vector<vector<int>> res;
    res.reserve(5);

    for (const auto& [price, shop, movie] : rented)
    {
      res.emplace_back(vector<int>{ shop, movie });
      if (res.size() == 5)
      {
        break;
      }
    }
    return res;
  }
};
