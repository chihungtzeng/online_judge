#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using ipair = pair<int, int>;
class UndergroundSystem {
 public:
  unordered_map<string, int> station_id;
  map<ipair, int> travel_time, occr;                // key: {ss_id, es_id}
  unordered_map<int, ipair> checking_in_customers;  // id -> station, t

  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    auto it = station_id.find(stationName);
    int sid = 0;
    if (it == station_id.end()) {
      sid = station_id.size();
      station_id[stationName] = sid;
    } else {
      sid = it->second;
    }
    checking_in_customers[id] = {sid, t};
  }

  void checkOut(int id, string stationName, int t) {
    auto [sid, stime] = checking_in_customers[id];
    auto it = station_id.find(stationName);
    int es_id = 0;
    if (it == station_id.end()) {
      es_id = station_id.size();
      station_id[stationName] = es_id;
    } else {
      es_id = it->second;
    }
    ipair key{sid, es_id};
    travel_time[key] += t - stime;
    occr[key] += 1;
  }

  double getAverageTime(string startStation, string endStation) {
    int ss_id = station_id[startStation];
    int es_id = station_id[endStation];
    ipair key{ss_id, es_id};
    return double(travel_time[key]) / occr[key];
  }
};
