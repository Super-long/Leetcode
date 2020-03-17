#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressString(string S) {
    static auto speedup = 
        []{ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr;};
        int sum = 1;
        ostringstream ss;
        ss << S[0];
        for(int i=1;i<S.size();++i){
            if(S[i]==S[i-1]){
                ++sum;
                continue;
            }else{
                ss << sum;
                sum = 1;
                ss << S[i];
            }
        }
        ss << sum;
        string str = ss.str();
        return S.size() <=str.size() ? S : str; 
    }
};

int main(){
    Solution sol;
    cout << sol.compressString("aabcccccaaa") << endl;;
    return 0;
}