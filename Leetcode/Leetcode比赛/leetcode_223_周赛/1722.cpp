#include <bits/stdc++.h>
using namespace std;

class Solution {    // 样例都过，但是leetcode提示溢出，难受
private:
    class UnionFind{
        public:
            vector<int> parent;
            int find(int node){
                if(node != parent[node]){
                    parent[node] = find(parent[node]);
                }
                return parent[node];
            }
        public:
            explicit UnionFind(int len){
                parent.resize(len);
                iota(parent.begin(), parent.end(), 0);
            }

            void Union(int lhs, int rhs){
                if(!isUnion(lhs, rhs)){
                    parent[find(lhs)] = parent[find(rhs)];
                }
            }

            bool isUnion(int lhs, int rhs){
                int x = find(lhs);
                int y = find(rhs);
                if(x != y) return false;    // 不连通返回false
                return true;
            }
    };

    int check_not_equal(const vector<int>& source, const vector<int>& target){
        int lhs = 0;
        int rhs = 0;
        int len = source.size();
        int res = 0;
        while(lhs < len){
            if(source[lhs] == target[rhs]){
                lhs++;
                rhs++;
                res++;
            } else if(source[lhs] < target[rhs]){
                lhs++;
            } else {
                rhs++;
            } 
        }
        cout << "相同的下标为 : " << res << endl;
        return len - res;
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        UnionFind uf(source.size());
        for(auto item : allowedSwaps) {
            uf.Union(item[0], item[1]);
        }
        
        auto& parent = uf.parent;
        unordered_map<int, vector<int>> vis;
        for (size_t i = 0; i < source.size(); i++){
            uf.find(i);
            cout << parent[i] << endl;
            vis[parent[i]].push_back(i);
        }   // vis中存在这所有的集合；再创建一个无法被交换的特殊集合

        cout << "集合数 ： " << vis.size() << endl;
        
        unordered_map<int, vector<int>> compare;
        vector<int> one;
        for (auto& item : vis){
            cout << " size : "<< item.second.size() << endl;
            if(item.second.size() > 1){
                for (auto& x : item.second){    // 每个区间的下标
                    compare[item.first].push_back(source[x]);
                    x = target[x]; // 把vis中改为存储值
                    cout << "vis中数据: " << item.first << " " << x << endl;
                }
            } else {    // 独立的结点
                one.push_back(item.first);    // 插入独立结点的下标
            }
        }

        cout << "开始输出两个map比较的结果\n";
        int result = 0;
        for(auto item : vis){
            if(item.second.size() == 1) continue;
            sort(item.second.begin(), item.second.end());
            sort(compare[item.first].begin(), compare[item.first].end());
            
            result += check_not_equal(item.second, compare[item.first]);
        }

        for (size_t i = 0; i < one.size(); i++){
            int temp = one[i]; // 独立结点的下标
            if(target[temp] != source[temp]) result++;
        }
        
        return result;
    }
};
// [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
// source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
// [71,13,6,60,22,31] [66,57,2,60,22,73] [[4,5],[0,4]]
int main(){
    Solution sol;
    vector<int> source = {71,13,6,60,22,31};
    vector<int> target = {66,57,2,60,22,73};
    vector<vector<int>> allowedSwaps = {
        {4,5},
        {0,4},
    };
    int res = sol.minimumHammingDistance(source, target, allowedSwaps);
    cout << res << endl;
    return 0;
}

/*
class Solution {
public:
    int getf(vector<int>& f, int x) {
        if (f[x] == x) return x;
        int nf = getf(f, f[x]);
        f[x] = nf;
        return nf;
    }
    
    void add(vector<int>& f, int x, int y) {
        int fx = getf(f, x);
        int fy = getf(f, y);
        f[fx] = fy;
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> f(n);
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
        for (const auto& e: allowedSwaps) {
            add(f, e[0], e[1]);
        }
        
        unordered_map<int, unordered_multiset<int>> s, t; // 为每个联通分支维护位置的集合
        for (int i = 0; i < n; i++) {
            int fa = getf(f, i);
            s[fa].insert(source[i]);
            t[fa].insert(target[i]);
        }
        
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (s.find(i) == s.end()) continue;
            for (int x: s[i]) {
                if (t[i].find(x) == t[i].end()) {
                    ret++;
                } else {
                    // 不能使用 t[i].erase(x)，不然会删掉所有的 x
                    t[i].erase(t[i].find(x));
                }
            }
        }
        return ret;
    }
};
*/