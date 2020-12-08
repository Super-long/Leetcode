#include <bits/stdc++.h>
#include <string_view>
using namespace std;

class Solution {
private:
    vector<int> result;
    // sum:前两者的总和，prev是斐波那契上一个值
    bool getResult(const string& str, int index, long long sum, int prev){  // 比较经典的回溯题目
        if(index == str.size()){
            return result.size() >= 3;
        }
        long long curr = 0;
        for (int i = index; i < str.size(); i++){
            if(i > index && str[index] == '0'){ // 特判第一个为零的情况，很巧妙的写法；
                break;
            }

            curr = curr*10 + str[i] - '0';
            if(curr > INT_MAX){
                break;
            }
            if(result.size() >= 2){
                if(curr < sum){
                    continue;
                } else if(curr > sum){
                    break;
                }
            }
            result.push_back(curr);
            //cout << curr << endl;
            if(getResult(str, i + 1, prev + curr, curr)){
                return true;
            }
            result.pop_back();
        }
        return false;
    }
public:
    vector<int> splitIntoFibonacci(string S) {
        getResult(S, 0, 0, 0);
        return result;
    }
};

int main(){
    Solution sol;
    auto vec = sol.splitIntoFibonacci("11235813");
    for (size_t i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
    return 0;
}