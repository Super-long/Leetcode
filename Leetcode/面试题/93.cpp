//复原IP地址
#include <bits/stdc++.h>
using namespace std;

class Solution {
    string str;
    vector<string> ResultItem{"","","",""};
    vector<string> res;
private:
    void dfs(int segID, int startID){
        if(segID == 4 && startID == str.size()){
            string temp = ResultItem[0]+ResultItem[1]+ResultItem[2]+ResultItem[3];
            res.push_back(std::move(temp));
            return;
        }
        if(segID == 4 && startID != str.size()){
            return;
        }
        if(str[startID] == '0'){
            if(segID!=3){
                ResultItem[segID] = "0.";
            }else {
                ResultItem[segID] = "0";
            }
            dfs(segID+1, startID+1);
            return;
        }
        int value = 0; // 下面第一个值肯定不是零了
        for(int i = startID; i < min(str.size(),static_cast<size_t>(startID+3)); ++i){
            value *= 10;
            value += str[i]-'0';
            ResultItem[segID] = to_string(value);
            if(segID < 3) ResultItem[segID] += ".";
            if(value <= 255){
                dfs(segID+1, i + 1);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        this->str = s;
        ResultItem.resize(4);
        dfs(0, 0);
        return res;
    }
};

int main(){
    Solution sol;
    string str = "0000";
    auto res = sol.restoreIpAddresses(str);
    for(auto x : res){
        cout << x << endl;
    }
    return 0;
}