// 二进制求和
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res(max(a.size(), b.size())+1, '0');
        for(int i = 0; i < res.size(); i++){
            int Temp = 0;
            if(a[i] == '1') Temp++;
            if(b[i] == '1') Temp++;
            if(res[i] == '1') Temp++;
            if(Temp == 1){
                res[i] = '1';
            }else if(Temp == 2){
                res[i+1] = '1';
                res[i] = '0';
            }else if(Temp == 3){
                res[i] = '1';
                res[i+1] = '1';
            }
        }
        reverse(res.begin(), res.end());
        if(res[0] == '0'){
            res.erase(res.begin(), res.begin()+1);
        }
        return res;
    }
};

// "1010", b = "1011"
//  "11", b = "1"
int main(){
    Solution sol;
    cout << sol.addBinary("10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101",
"110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011");
    return 0;
}