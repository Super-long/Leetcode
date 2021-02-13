#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bitset<26> vis;
    int res = 0;
    bool check(const string& str){
        bool flag = true;
        for(auto ch : str){
            if(vis.test(ch - 'a')){
                flag = false;   // 没有考虑到一个字符串本身有重复，["yy","bkhwmpbiisbldzknpm"]
            }
        }
        if(flag) for(auto ch: str) vis.set(ch - 'a');
        return flag; //防止更新一半退出
    }

    void dfs(int start, const vector<string>& arr, int len){
        for (size_t i = start; i < arr.size(); i++){   
            if(check(arr[i])){
                res = max<int>(res, len + arr[i].size());
                dfs(i + 1, arr, len + arr[i].size());
                for(auto ch : arr[i]) vis.reset(ch - 'a');
            } else {
                dfs(i + 1, arr , len);
            }
        }
        return;
    }
public:
    int maxLength(vector<string>& arr) {
        dfs(0, arr, 0);
        return res;
    }
};

/*
class Solution {
private:
    bitset<26> vis;
    int res = 0;
    bool check(const string& str){
        bool flag = true;
        for(auto ch : str){
            if(vis.test(ch - 'a')){
                flag = false;
            }
        }
        if(flag) for(auto ch: str) vis.set(ch - 'a');
        return flag; //防止更新一半退出
    }

    void dfs(int start, const vector<string>& arr, int len){
        for (size_t i = start; i < arr.size(); i++){    // 没有考虑到一个字符串本身有重复
            if(check(arr[i])){
                res = max<int>(res, len + arr[i].size());
                dfs(i + 1, arr, len + arr[i].size());
                for(auto ch : arr[i]) vis.reset(ch - 'a');
            } else {
                dfs(i + 1, arr , len);
            }
        }
        return;
    }
public:
    int maxLength(vector<string>& arr) {
        dfs(0, arr, 0);
        return res;
    }
};
*/

int main(){
    Solution sol;
    vector<string> vec = {
        "cha","r","act","ers"
    };
    cout << sol.maxLength(vec) << endl;

    return 0;
}