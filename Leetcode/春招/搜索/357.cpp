#include <bits/stdc++.h>
using namespace std;

class Solution {    // 9的时候超时;答案为5611771，跑了9秒。需要数位dp
private:
    unordered_set<int> se;
    string s;
    int sum = 0;    // 记录有重复数字的个数
    int head = 0;
    void dfs(int depth, int n){
        if(depth == n){
            sum++;
            return;
        }
        for (size_t i = 0; i < 10; i++){
            if(depth == 0){
                head == i;
            }
            if(!se.count(i) || (se.size() == 1 && i == 0)){ // 前导零也算进去
                se.insert(i);
                s += to_string(i);
                dfs(depth+1, n);
                s.pop_back();
                se.erase(i);
            }
        }
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        dfs(0, n);
        return sum; // 加上0
    }
};

int main(){
    Solution sol;
    cout << sol.countNumbersWithUniqueDigits(9) << endl;
    return 0;
}