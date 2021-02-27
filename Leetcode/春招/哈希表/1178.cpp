#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> mp; // k:二进制值； v:个数
        int len = words.size();
        for (int i = 0; i < len; ++i) {
            string& item = words[i];
            int num = 0;
            for(auto x : item){
                num |= (1 << (x - 'a'));
            }
            if (__builtin_popcount(num) <= 7) { // 判断32位整数有多少位1
                ++mp[num];
            }
        }
        len = puzzles.size();
        vector<int> results;
        for (int i = 0; i < len; ++i) { // 第7位不需要枚举，我们只需要枚举六位即可
            int result = 0;

            for(int j = 0; j < (1 << 6); ++j) { // 这种枚举的方法也很巧妙
                int mask = 1 << (puzzles[i][0] - 'a');  // puzzles最长7位
                for(int k = 0; k < 6; ++k){
                    if(j & (1 << k)){
                        mask |= (1 << (puzzles[i][k + 1] - 'a')); 
                    }
                }
                if(mp.find(mask) != mp.end()){
                    result += mp[mask];
                }
            }

            results.emplace_back(std::move(result));
        }
        return results;
    }
};

int main(){
    Solution sol;
    vector<string> vec = {"aaaa","asas","able","ability","actt","actor","access"};
    vector<string> vec1 = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
    auto res = sol.findNumOfValidWords(vec, vec1);
    for(auto x : res){
        cout << x << " ";
    }
    return 0;
}