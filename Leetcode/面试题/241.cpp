// 为运算表达式设计优先级
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
int caculate(int num1, char c, int num2) {
    switch (c) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
    }
    return -1;
}

bool isOperation(char c) {
    return c == '+' || c == '-' || c == '*';
}

public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int sum = 0;
        int index = 0;
        while(index < input.size() && !isOperation(input[index])){
            sum = sum*10 + (input[index++] - '0');
        }
        if(index == input.size()){
            res.push_back(sum);
            return res;
        }
        for(size_t i = 0; i < input.size(); i++){
            if(isOperation(input[i])){
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                vector<int> result2 = diffWaysToCompute(input.substr(i+1));
                for (int j = 0; j < result1.size(); j++) {
                    for (int k = 0; k < result2.size(); k++){
                        res.push_back(caculate(result1[j], input[i], result2[k]));
                    }
                }   
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    auto res = sol.diffWaysToCompute("2*3-4*5");
    for(auto x : res){
        cout << x << endl;
    }
    return 0;
}