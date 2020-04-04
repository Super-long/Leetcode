// 有效括号的嵌套深度
#include <bits/stdc++.h>
using namespace std;

// 思路是有问题的 最小的应该是最大的括号组除以2加1
/* class Solution { //返回递归括号最小深度 
public:
    int maxDepthAfterSplit(string seq) {
        priority_queue<int, vector<int>, less<int>> que;
        int sum = 1;
        bool flag = true;
        for(size_t i = 1; i < seq.size(); i++){
            if(flag && seq[i] == '('){
                ++sum;
            } else if(flag && seq[i] == ')'){
                que.push(sum);
                sum = 0;
                flag = false;
            } else if(!flag && seq[i] == '('){
                sum = 1;
                flag = true;
            }
        }
        int first = que.top(); que.pop();
        int second = -1;
        if(!que.empty()) second = que.top();
        return second == -1 ? first : (first == second ? first : first -1);
    }
}; */

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        int deepth = 0;
        for(auto x : seq){
            if(x == '('){
                //++sum; 其实这里应该是一个栈 但是并没有必要 使用数字即可 而且deepth与sum行为相同
                ++deepth;
                res.push_back(deepth%2);
            } else {
                res.push_back(deepth%2);
                --deepth;
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    string str = "()(())()";
    auto x = sol.maxDepthAfterSplit(str);
    for(auto item : x){
        cout << item << " ";
    }
    return 0;
}