// 计数二进制子串
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.size() < 2) return 0;
        vector<int> vec;
        int res = 0;
        int index = 1;

        for(size_t i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]){
                //cout << i << endl;
                index++;
            }else{
                vec.push_back(index);
                index = 1;
            }
        }
        //if(s.back() == s[s.size()-2])
        vec.push_back(index);
        for(auto x : vec){
            cout << x << endl;
        }
        for(size_t i = 1; i < vec.size(); i++){
            res += min(vec[i], vec[i-1]);
        }
        return res;        
    }
};

int main(){
    Solution sol;
    cout << sol.countBinarySubstrings("00110") << endl;
    return 0;
}