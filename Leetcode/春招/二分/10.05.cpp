#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findString(vector<string>& words, string s) {    // 带空格的二分查找
        int lhs = 0;
        int len = words.size();
        int rhs = len - 1;
        int ans = len;
        while(lhs <= rhs){
            cout << lhs << " " << rhs << endl;
            int mid = lhs + (rhs - lhs) / 2;
            int temp = mid;
            while(mid <= rhs && words[mid] == ""){
                mid++;
            }
            if(mid > rhs){
                rhs = temp - 1;
                continue;
            }   // 表示当前mid位上有一个非空字符串
            cout << mid << " " <<words[mid] << endl;
            if(words[mid] >= s){
                ans = mid;
                rhs = mid - 1;
            } else {
                lhs = mid + 1;
            }
        }
        if(ans == len || words[ans] != s){
            cout << "nihao\n";
            return -1; 
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<string> sum = {"at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""};
    cout << sol.findString(sum, "a") << endl;
    return 0;
}