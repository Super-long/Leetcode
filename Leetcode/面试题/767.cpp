#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) { // 写法有问题，但是可以过，标准答案还是更好一点
        array<int, 26> items = {0};
        items.fill(0);
        for(auto x : S){
            items[x - 'a']++;
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> que;
        char index = 'a'; 
        for(auto x : items){
            if(x > 0){
                que.emplace(std::make_pair(x, index));
            }
            index++;
        }
        auto len = que.size();
        
        string res;
        res.reserve(S.size());

        pair<int, char> lhs = {0,0}; // lhs.first大于等于rhs
        pair<int, char> rhs;

        while(!que.empty()){
            if(lhs.first == 0){
                lhs = std::move(que.top());
                que.pop();
            }
            if(que.empty()){
                //cout << " --------- " << lhs.first << endl;
                if(lhs.first <= 1){
                    return res + lhs.second;
                } else {
                    return "";
                }
            }
            rhs = std::move(que.top()); // rhs一定等于零
            que.pop();
            //cout << lhs.first << " " << lhs.second << " " << rhs.first<< " " << rhs.second << " "  << res << endl;
            if(rhs.first > lhs.first){
                swap(lhs, rhs);
            }
            string temp;
            temp += lhs.second;
            temp += rhs.second;
            lhs.first -= rhs.first;
            while(rhs.first > 0){
                res += temp;
                rhs.first--;
            }
        }
        if(lhs.first == 1) res.push_back(lhs.second);
        //cout << lhs.first << " " << lhs.second << endl;
        if(lhs.first == 2){  // 错误的写法
            if(len > 2)
            return lhs.second + res + lhs.second;
        }
        if(lhs.first > 1) return "";
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.reorganizeString("aaaakl") << endl;
    return 0;
}