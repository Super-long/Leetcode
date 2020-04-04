// 字符串转换整数 (atoi)
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool symbol;
    long long conversion(const string& str){
        cout << str << endl;
        long long sum = 0;
        for(int i = 0 ;i < str.size(); ++i){
            char x = str[i];
            sum *= 10;
            sum += (x-48);
            sum = symbol ? min(sum, (long long)INT_MAX) : min(sum, -(long long)INT_MIN);
        }
        return sum;
    }
public:
    int myAtoi(string str) {
        if(!str.size()) return 0;
        int lhs=-1, rhs=-1;
        bool flag = true;
        symbol = true; //true为+ false为-
        for(auto x : str){
            if(flag){ // 更新lhs
                if(x == ' '){
                    ++lhs;
                }else if(x >=48 && x <=57){
                    flag = false;
                    ++lhs;
                    rhs = lhs;
                }else if(x == '-' || x == '+'){
                    if(x=='-') symbol = false;
                    flag = false;
                    rhs = ++lhs;
                    lhs++;
                }else{ 
                    return 0; 
                }
            } else { // 开始数字部分 lhs为数字的最左边
                if(x >=48 && x <=57){
                    ++rhs; 
                }else{
                    break; // 现在[lhs, rhs]为数据范围
                }
            }
        }
        if(rhs == -1) return 0;
        long long res = conversion(str.substr(lhs, rhs-lhs+1));
        if(symbol) return (int)res;
        return (int)-res;
    }
}; 

int main(){
    Solution sol;
    string str = " -42";
    cout << sol.myAtoi(str) << endl;
    return 0;
}