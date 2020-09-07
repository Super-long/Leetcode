#include <bits/stdc++.h>
using namespace std;

unordered_map<pair<int,int>,int> mp;

int sum(int step, int wj, unordered_map<pair<int,int>,int>& dp){
    if(step < 1){
        return 0;
    }else if(dp[make_pair(step,wj)] != 0){
        return dp[make_pair(step,wj)];
    }else {
        int value = 0;
        if(wj == 0){
            value = sum(step-1,0,dp) + sum(step-2, 1, dp);
        }else {
            value = sum(step-1,0,dp);
        }
        dp[make_pair(step, wj)] = value;
        return value;
    }
}

int main(){
    int N = 4;
    mp[make_pair(1,0)] = 1;
    mp[make_pair(1,1)] = 1;
    int value = sum(N, 0, mp);
    cout << value << endl;
    return 0;
}
