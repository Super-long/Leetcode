// Z 字形变换
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string res;
        vector<string> rows(min(numRows, int(s.size())));
        int index = 0;
        bool down = false; // 当前行数变化是否为递增 
        for(size_t i = 0; i < s.size(); i++){
            rows[index] += s[i];
            if (index == 0 || index == numRows - 1) down = !down;
            index += down ? 1 : -1;
            /*
            // 显然上面更优雅一点
            if(up) index++;
            else index--;
            if(index >= numRows-1){   // 其实等于就可以
                up = false;
            }else if(index <= 0){
                up = true;
            }
            */
        }
        for(auto x : rows){
            res += x;
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.convert("LEETCODEISHIRING", 3) << endl;
    return  0;
}