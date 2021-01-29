#include <bits/stdc++.h>
using namespace std;

/* class Solution { // 写的是个jb
private:
    int res = 0;
    void dfs(vector<int>& nums, int lhs, int rhs, int lhsx, int rhsy){
        //if(rhsy - lhsx < 1 && rhs - lhs < 3) return;   // 区间内小于4个值
        if(!(rhsy - lhsx >= 1 && rhs - lhs >= 3)) return;
        int x = nums[lhs] * nums[rhs];
        int y = nums[lhsx] * nums[rhsy];
        if(x == y){
            cout << lhs << " " << rhs << " " << lhsx << " " << rhsy << endl;
            cout << nums[lhs] << " " << nums[rhs] << " " << nums[lhsx] << " " << nums[rhsy] << endl;
            res++;
            dfs(nums, lhs + 1, rhs, lhsx + 1, rhsy);
            dfs(nums, lhs, rhs - 1, lhsx, rhsy - 1);
        } else if(x > y){
            dfs(nums, lhs, rhs, lhsx+1, rhsy);
        } else {
            dfs(nums, lhs, rhs, lhsx, rhsy - 1);
        }
    }
public:
    int tupleSameProduct(vector<int>& nums) {
        int lhs = 0;
        int rhs = nums.size() - 1;
        sort(nums.begin(), nums.end());
        dfs(nums, lhs, rhs, lhs + 1, rhs - 1);
        return res * 8;
    }
}; */

/* class Solution {
private:
    int get(int x){
        if(x == 0) return 1;
        int res = 1;
        for(int i=1;i<=x;++i){
            res*=i;
        }
        return res;
    }
    int check(int param){
        return get(param)/(get(2)*(get(param-2)));
    }
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> vis;
        for (size_t i = 0; i < nums.size(); i++){
            for (size_t j = i + 1; j < nums.size(); j++){
                vis[nums[i]*nums[j]]++;
            }
        }
        cout << get(3) << " " << get(2) << " " << get(1) << endl;
        int res = 0;
        for(auto x : vis){
            if(x.second >= 2){
                cout << x.second << " " << check(x.second)<< endl;
                //res += check(x.second);   // 阶乘会爆
                res += x.second * (x.second - 1) / 2;   // 真没看懂这个式子
            }
        }
        return res*8;
    }
}; */

class Solution {    // 这样写效率太低
public:
    int tupleSameProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i++){
            for (int j = nums.size() - 1; j >= i+3; j--){
                int lhs = i;
                int rhs = j;
                int lhsx = i + 1;
                int rhsy = j - 1;
                int sum = nums[lhs] * nums[rhs];
                while(lhsx < rhsy){
                    int temp = nums[lhsx] * nums[rhsy];
                    if(temp < sum){
                        lhsx++;
                    } else if(temp > sum){
                        rhsy--;
                    } else {
                        res++;
                        lhsx++;
                        rhsy--;
                    }
                }
            }
        }
        return res*8;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1,2,4,5,10};
    cout << sol.tupleSameProduct(vec) << endl;
    return 0;
}