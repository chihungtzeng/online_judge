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

struct Person {
  string name_;
  int id_;
  bool dead_;
  vector<int> children_id;

  Person(string name, int id) : name_(name), id_(id), dead_(false) {}
};

class ThroneInheritance {
 public:
  unordered_map<string, int> name2id_;
  vector<Person> people;

  ThroneInheritance(string kingName) {
    name2id_[kingName] = 0;
    people.emplace_back(Person{kingName, 0});
  }

  void birth(string parentName, string childName) {
    int pid = name2id_[parentName];
    int cid = name2id_.size();

    name2id_[childName] = cid;
    people.emplace_back(Person{childName, cid});
    people[pid].children_id.push_back(cid);
  }

  void death(string name) {
    int id = name2id_[name];
    people[id].dead_ = true;
  }

  vector<string> getInheritanceOrder() {
    vector<int> ans;
    vector<int> stack;
    stack.push_back(0);
    while (!stack.empty()) {
      int id = stack.back();
      ans.push_back(id);
      stack.pop_back();
      for (int i = people[id].children_id.size() - 1; i >= 0; i--) {
        int cid = people[id].children_id[i];
        stack.push_back(cid);
      }
    }
    vector<string> order;
    const int n = ans.size();
    order.reserve(n);
    for (int i = 0; i < n; i++) {
      int id = ans[i];
      if (!people[id].dead_) {
        order.push_back(people[id].name_);
      }
    }
    return order;
  }
};

