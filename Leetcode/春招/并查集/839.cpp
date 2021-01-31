#include <bits/stdc++.h>
using namespace std;

class Solution {    // 这个题属于智商题，看出来就很简单，看不出来完蛋；
private:
    class UnionFind{
        private:
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

            int length(){
                unordered_set<int> se;
                for(int i = 0; i < parent.size();++i){
                    find(i);
                    se.insert(parent[i]);
                }
                return se.size();
            }
    };
    bool check(const string& lhs, const string& rhs){
        int res = 0;
        for (size_t i = 0; i < lhs.size(); i++){
            if(lhs[i] == rhs[i]) ++res;
        }
        cout << lhs << " " << rhs << " " << lhs.size() - res << endl;
        return lhs.size() - res == 2 || res == lhs.size();
    }

public:
    int numSimilarGroups(vector<string>& strs) {
        int len = strs.size();
        UnionFind uf(len);
        for (size_t i = 0; i < len - 1; i++){
            for (size_t j = i + 1; j < len; j++){
                if(check(strs[i], strs[j])){
                    cout << i << " " << j << endl;
                    uf.Union(i, j); // 连通
                }
            }
        }
        return uf.length();
    }
};

int main(){
    Solution sol;
    vector<string> vec = {"abc", "abc"};
    cout << sol.numSimilarGroups(vec) << endl;
    return 0;
}