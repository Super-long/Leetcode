#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string result;
    int count = 0;
    int target;
    int len;
    void dfs(int index, int depth, string& item){
        if(count == target){
            return;
        } 
        if(len == depth){
            count++;
            if(count == target) result = item;
            cout << item << endl;
            return;
        }

        for (size_t i = 0; i < 3; i++){ // index代表上一次使用的字符
            if(index != i || depth == 0){
                dfs(i, depth + 1, item += ('a' + i));
                item.pop_back();
            }
        }
        return;
    }
public:
    string getHappyString(int n, int k) {
        if(k > pow(2, n - 1) * n) return "";    // 加上以后竟然变慢了，看来需要快速幂
        len = n;
        target = k;
        string res;
        dfs(0, 0, res);
        return result;
    }
};

int main(){
    Solution sol;
    cout << sol.getHappyString(3,9) << endl;
    return 0;
}