// 最大数
#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b){    // 保证a的长度小于等于b
/*     if(b.size() < a.size()) swap(a, b);
    for(size_t i = 0; i < a.size(); i++){
        if(a[i] < b[i]) return false;
        else if(a[i] > b[i]) return true;
    }
    if(a.size() == b.size()) return true;  //长度和每一项都相同，没必要交换
    return true; */
    string resa = a + b;
    string resb = b + a;
    if(resa >= resb) {
        return true;
    } else {
        return false;
    }
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        bool flag = false;
        for(auto x : nums){
            if(x != 0) flag = true;
            vec.push_back(std::move(to_string(x)));
        }
        if(!flag) return "0";   // 全零 
        sort(vec.begin(), vec.end(), compare);
        string res;
        res.reserve(200);
        for(auto x : vec){
            res += x;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {3,30,34,5,9};
    cout << sol.largestNumber(vec) << endl;
    return 0;
}