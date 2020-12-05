#include <bits/stdc++.h>
using namespace std;

/* class Solution { // 这道题写错了，不知道错在哪里。
private:
    unordered_map<int, int> mp;
    set<int> se;
public:
    bool isPossible(vector<int>& nums) {
        for(auto x : nums){
            mp[x]++;
            se.insert(x);
        }
        while(!se.empty()){
            int sum = 0;
            bool flag = true;
            int prev = *se.begin() - 1;  // 这样其实有问题，因为题目没有限定数字范围，这样可能超范围
            for(auto x : se){

                if(x - prev != 1) {
                    if(sum < 3){
                        return false;
                    } else {
                        break;
                    }
                }

                if(flag && mp[x] == 1){
                    sum++;
                    mp[x]--;
                    se.erase(x);
                } else if(!flag && mp[x] >= 2){
                    sum++;
                    mp[x]--;
                } else if(flag && mp[x] >= 2){
                    flag = false;
                    sum++;
                    mp[x]--;
                } else {
                    break;
                }
                prev = x;
            }
            if(sum < 3){
                return false;
            }
        }
        return true;
    }
}; */

class Solution {    // md，不想写这个题了
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int ,int> countMap;
        unordered_map<int, int> visMap;
        for(auto x : nums){
            countMap[x]++;
        }
        
        for(auto& x : nums){
            int count = countMap[x];
            if(count > 0){
                int prevCount = visMap[x - 1];
                if(prevCount > 0){
                    visMap[x-1] --;
                    visMap[x] ++;
                } else {
                    if(countMap[x + 1] == 0 || countMap[x + 2] == 0){
                        return false;
                    }
                    visMap[x] ++;
                }
                countMap[x]--;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> countMap;
        unordered_map<int, int> endMap;
        for (auto& x : nums) {
            int count = countMap[x] + 1;
            countMap[x] = count;
        }
        for (auto& x : nums) {
            int count = countMap[x];
            if (count > 0) {
                int prevEndCount = endMap[x - 1];
                if (prevEndCount > 0) {
                    countMap[x] = count - 1;
                    endMap[x - 1] = prevEndCount - 1;
                    endMap[x] = endMap[x] + 1;
                } else {
                    int count1 = countMap[x + 1];
                    int count2 = countMap[x + 2];
                    if (count1 > 0 && count2 > 0) { //  这里需要直接减，因为可能出现countx为1，而count有很多
                        countMap[x] = count - 1;
                        countMap[x + 1] = count1 - 1;
                        countMap[x + 2] = count2 - 1;
                        endMap[x + 2] = endMap[x + 2] + 1;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};