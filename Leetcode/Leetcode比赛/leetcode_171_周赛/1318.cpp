//或运算的最小翻转次数

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string Convert(int a){
        string res;
        while(a){
            if(a%2){
                res += '1';
            }else {
                res += '0';
            }
            a/=2;
        }
        if(res.size()<32){
            res += string(32-res.size(),'0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
public:
    int minFlips(int a, int b, int c) {
        string aa = Convert(a);
        string bb = Convert(b);
        string cc = Convert(c);
        int result = 0;
        for(size_t i = 0; i < 32; i++){
            if(cc[i] == '0'){
                if(aa[i] == '1') ++result;
                if(bb[i] == '1') ++result;
            } else {
                if(aa[i] == '0' && bb[i] == '0') ++result;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    cout << sol.minFlips(1,2,3) << endl;
    return 0;
}