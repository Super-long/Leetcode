#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
unordered_map<string,int> se;
public:
    vector<vector<int>> palindromePairs(vector<string>& words){
        init(words);
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i++){
            int len = words[i].size();
            for (int j = 0; j < len; j++){
                if(isPalindrome(words[i], j, len-1)){
                    pair<int, bool> re = isExit(words[i].substr(0,j), 1);
                    if(re.second && i != re.first){ // 是回文串
                        vector<int> item{i, re.first};
                        res.push_back(std::move(item));
                    }
                }
                if(isPalindrome(words[i], 0, j)){
                    // 可复用
                    pair<int, bool> re = isExit(words[i].substr(j+1, len-j-1), 1);
                    
                    if(re.second && i != re.first){
                        vector<int> item{re.first, i};
                        res.push_back(std::move(item));
                    }
                } 
            }
           auto temp = isExit(words[i], 1);
            if(temp.second && i != temp.first){ // 第二个条件用于单字母
                vector<int> item{i, temp.first};
                res.push_back(std::move(item));
            }
        }
        return res; // RVO
    }
private:
    bool isPalindrome(const string& str, int lhs, int rhs) const{
        
        int len = rhs - lhs + 1;
        for (int i = 0; i < len/2; i++){
            if(str[lhs+i] != str[rhs-i]){
                return false;
            }
        }
        return true;
    }

    void init(vector<string>& words){
        se.clear();
        for(int i = 0; i < words.size(); ++i){
            auto temp = words[i];
            reverse(temp.begin(), temp.end());
            se[std::move(temp)] = i;
        }
    }

    // 是否存在与所对应下标
    pair<int, bool> isExit(string str, int op){
        // op==1 时用在判断len相同的时候
        if(op == 0) reverse(str.begin(), str.end());
        pair<int, bool> pa;
        if(se.find(str) != se.end()){
            pa.second = true;
            pa.first = se[str];
        }else {
            pa.second = false;
        }
        return pa;
    }
};

int main(){
    Solution sol;
    vector<string> vec = {"ab","ba","abc","cba"};
    auto res = sol.palindromePairs(vec);
    for (size_t i = 0; i < res.size(); i++){
        cout << res[i][0] << " " << res[i][1] << endl;
    }
    return 0;
}