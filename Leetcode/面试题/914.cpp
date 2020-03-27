//卡牌分组
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(!deck.size()) return false;
        unordered_map<int,int> mp;
        for(auto x : deck){
            mp[x]++;
        }
        set<int> se;
        int Min = 0x3f3f3f3f, lastMin = 0x3f3f3f3f;
        for(auto& entry : mp){
            if(entry.second<=Min){
                lastMin = Min;
                Min = entry.second;
            }else if(entry.second<=lastMin){
                lastMin = entry.second;
            }
        }
        if(lastMin == Min){
            set<int> se;
            for(auto& entry : mp){
                se.insert(entry.second);
            }
            auto x = upper_bound(se.begin(), se.end(), Min);
            lastMin = *x;
        }
        if(lastMin == 0x3f3f3f3f && Min>1) return true; //等于1会归到gcd为1的情况
        int GCD = gcd(Min, lastMin);
        if(GCD == 1) return false;
        for(auto& entry : mp){
            if(entry.second%GCD){
                return false;
            }
        }
        return true;
    }
    int gcd(int a, int b){
        return b==0?a:gcd(b,a%b);
    }
};

int main(){
    vector<int> vec = {1,1,2,2,2,2};
    Solution sol;
    cout << sol.hasGroupsSizeX(vec) << endl;
    return 0;
}