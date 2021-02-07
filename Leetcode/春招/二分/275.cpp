#include <bits/stdc++.h>
using namespace std;

/* class Solution {    // 很裸的一道答案二分
private:
    bool check(int mid, const vector<int>& citations){
        if(mid == 0) return false;
        int index = lower_bound(citations.begin(), citations.end(), mid) - citations.begin();
        if(mid >= citations.size() - index){    // 当mid大于时不一定 -> [1,1]
            return true;
        } else {
            return false;
        }
    }
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 1 && citations[0] == 0) return 0;
        if(citations.size() == 0) return 0;
        int lhs = 0;
        int rhs = citations.size() - 1;
        int ans = citations.size();
        while(lhs <= rhs){
            int mid = lhs + (rhs - lhs) / 2;
            if(check(mid, citations)){
                rhs = mid - 1;
                ans = mid;
            } else {
                lhs = mid + 1;
            }
        }
        return ans;
    }
}; */

class Solution {    // 和裸板子不一样
public:
    int hIndex(vector<int>& citations) {
        if(!citations.size()) return 0;
        int lhs = 0;
        int rhs = citations.size() - 1;
        int len = citations.size();
        while(lhs <= rhs){
            int mid = lhs + (rhs - lhs) / 2;
            if(len - mid == citations[mid]){
                return len - mid;
            } else if(len - mid > citations[mid]) {
                lhs = mid + 1;  // 显然lhs可能是答案
            } else {
                rhs = mid - 1;
            }
        }
        return len - lhs;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {100};
    cout << sol.hIndex(vec) << endl;
    return 0;
}