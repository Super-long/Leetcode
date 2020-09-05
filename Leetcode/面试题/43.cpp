// 字符串相乘
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<string> res;
public:
    string multiply(string num1, string num2) {
        if( num1[0] == '0' || num2[0] == '0') return "0";
        for(int i = num2.size() - 1; i >= 0; --i){
            string temp(num1.size(), '0');
            int carry = 0;
            int base = num2[i] - '0';
            for(int j = num1.size()-1; j >= 0; --j){
                int bit = num1[j] - '0';
                temp[j] = (base*bit + carry)%10 + '0';
                carry = (base*bit + carry)/10;
            }
            if(carry != 0){
                temp.insert(0, 1, carry + '0');
            }
            for(int k = 0; k < num2.size() - 1 - i; ++k){
                temp.push_back('0');
            }
            cout << temp << endl;
            res.push_back(temp);
        }
        return merge(0, res.size()-1);
    }

    string merge(int lhs, int rhs){
        if(lhs == rhs){
            return res[lhs];
        }
        int mid = lhs + (rhs - lhs) / 2;
        return stringPlus(merge(lhs, mid), merge(mid + 1, rhs));
    }

    string stringPlus(string num1, string num2){
        int size1 = num1.size();
        int size2 = num2.size();
        if( size1 < size2 ){
            num1.insert(0,size2-size1,'0');
        } else {
            num2.insert(0,size1-size2,'0');
        }
        string res(num1.size(),'0');
        int jw = 0;
        for(int i = num1.size() -1;i >-1;i--)
        {
            int v1 = num1[i] - '0';
            int v2 = num2[i] - '0';
            res[i] = (v1+v2+jw) %10 +'0';
            jw = (v1+v2+jw) / 10 ;
        }
        if( jw != 0)
        {
            res.insert(0,1,jw+'0');
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.multiply("123456789", "987654321") << endl;
    return 0;
}