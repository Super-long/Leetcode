#include <bits/stdc++.h>
using namespace std; 

class Solution {
private:
    vector<int> parent;
    int find(int node){
        if(node != parent[node]){
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    void Union(int lhs ,int rhs){
        parent[find(lhs)] = find(rhs);
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        if(!grid.size()) return 0;
        parent.resize(grid.size() * grid[0].size() * 4);
        iota(parent.begin(), parent.end(), 0);

        size_t len = grid[0].size();
        for (size_t i = 0; i < grid.size(); i++){
            for (size_t j = 0; j < len; j++){
                auto get_index = [=](int x, int y){
                    return (x*len + y) * 4;
                };

                if(!i){ // 第0行
                    if(j) Union(get_index(0, j-1) + 1, get_index(0, j) + 3);
                } 
                if(!j){ // 第0列
                    if(i) Union(get_index(i-1, 0), get_index(i, 0) + 2);
                }
                if(i && j){ // 不是第0行也不是第0列
                    Union(get_index(i-1,j), get_index(i,j) + 2);
                    Union(get_index(i, j-1) + 1, get_index(i,j) + 3);
                }

/*                 if(i < grid.size() - 1){
                    Union(get_index(i, j), get_index(i + 1, j) + 2);
                }

                if(j < len - 1){
                    Union(get_index(i, j) + 1, get_index(i, j + 1) + 3);
                } */
                
                int temp = get_index(i, j);
                if(grid[i][j] == '/'){
                    Union(temp + 1, temp);
                    Union(temp + 2, temp + 3);
                } else if(grid[i][j] == '\\'){
                    Union(temp + 3, temp);
                    Union(temp + 2, temp + 1);
                } else {    // 空格的情况
                    Union(temp, temp + 1);
                    Union(temp + 1, temp + 2);
                    Union(temp + 2, temp + 3);
                }
            }
        }
        
        unordered_set<int> se;
        for(auto& item : parent){
            item = find(item);
            se.insert(item);
        }
        return se.size();
    }
};

int main(){
    Solution sol;
    vector<string> vec = {
        " /",
        "  "
    };
    cout << sol.regionsBySlashes(vec) << endl;
    return 0;
}