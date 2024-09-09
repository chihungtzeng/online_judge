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

class WordDictionary
{
private:
  vector<WordDictionary*> kids;
  bool eow;

public:
  WordDictionary() : kids(26), eow(false)
  {
  }
  ~WordDictionary()
  {
    for (int i = 0; i < 26; i++)
    {
      if (kids[i])
      {
        delete kids[i];
        kids[i] = nullptr;
      }
    }
  }

  void addWord(string word)
  {
    auto cur = this;
    for (auto ch : word)
    {
      ch -= 'a';
      if (!cur->kids[ch])
      {
        cur->kids[ch] = new WordDictionary();
      }
      cur = cur->kids[ch];
    }
    cur->eow = true;
  }

  bool _search(const string& word, int pos = 0)
  {
    if (pos == word.size())
    {
      return eow;
    }
    char ch = word[pos];
    if (ch >= 'a' && ch <= 'z')
    {
      ch -= 'a';
      if (!kids[ch])
        return false;
      else
        return kids[ch]->_search(word, pos + 1);
    }
    else
    {
      bool found = false;
      for (int i = 0; i < 26 && !found; i++)
      {
        if (kids[i])
        {
          found = kids[i]->_search(word, pos + 1);
        }
      }
      return found;
    }
  }

  bool search(string word)
  {
    return _search(word);
  }
};

