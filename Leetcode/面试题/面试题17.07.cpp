// 婴儿名字
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  unordered_map<string, string> Tree; // 并查集数组，保存每个节点的父亲
public:
  string findRoot(string key) { // 构造并查集，通过父亲找祖先
    if (Tree.count(key) == 0) return key;
    auto ancestor = findRoot(Tree[key]);
    Tree[key] = ancestor; // 指定自己的父亲
    return ancestor;
  }

  vector<string> trulyMostPopular(vector<string>& names,
                                  vector<string>& synonyms) {
    for (auto& name_pair : synonyms) {
      int comma_ind = name_pair.find(',');
      string n1 = name_pair.substr(1, comma_ind - 1);
      string n2 = name_pair.substr(comma_ind + 1,
                                   int(name_pair.size()) - comma_ind - 2);
      n1 = findRoot(n1), n2 = findRoot(n2); // 这里需要注意，比较大小时不是直接比较 n1 和 n2，而是比较他们的根！否则就没有意义啦！
      if (n1 != n2) {
        if (n1 < n2)
          Tree[n2] = n1; //n1为n2的父亲
        else
          Tree[n1] = n2;
      }
    }

    unordered_map<string, int> hash_map;
    for (auto& name_str : names) {
      int t_ind = name_str.find('(');
      string name = name_str.substr(0, t_ind); // 解析出名字 
      int freq = atoi(
        name_str.substr(t_ind + 1, int(name_str.size()) - t_ind - 2).c_str()); // 解析出次数
      hash_map[findRoot(name)] += freq;
    }

    vector<string> ans;
    for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++) {
      string tmp = iter->first + "(" + to_string(iter->second) + ")";
      ans.push_back(tmp);
    }
    
    return ans;
  }
};