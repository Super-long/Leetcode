#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        auto str = to_string(K);
        vector<int> Kvec(str.size()); 
        int index = str.size() - 1;
        for (size_t i = 0; i < str.size(); i++){
            Kvec[i] = str[index--] - '0';
        }

        reverse(A.begin(), A.end());
        vector<int> res;
        int len = max(A.size(), Kvec.size());

        if(A.size() < len){
            for(int i = A.size(); i < len; ++i){
                A.push_back(0);
            }
        } else if(Kvec.size() < len){
            for(int i = Kvec.size(); i < len; ++i){
                Kvec.push_back(0);
            }
        }

        int carry = 0;
        for (size_t i = 0; i < len; i++){
            int temp = Kvec[i] + A[i] + carry;
            carry = 0;
            if(temp >= 10){
                carry += 1;
                temp %= 10;  
            }
            res.push_back(temp);
        }
        if(carry) res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1,2,0,0};
    auto res = sol.addToArrayForm(vec, 34);
    for(auto x : res){
        cout << x << " ";
    }
    putchar('\n');
    return 0;
}