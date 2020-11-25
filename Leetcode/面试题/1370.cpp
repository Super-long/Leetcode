#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int index = 0;
    map<char, size_t> mp;
public:
    string sortString(string s) {
        string res;
        res.resize(s.size());
        for (size_t i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }
        while(mp.size()){
            cout << mp.size() << endl;
            char Temp = 0;
            for(auto& x : mp){
                if(x.first > Temp){
                    res[index++] = x.first;
                    cout << x.first << endl;
                    x.second--;
                    Temp = x.first;
                    if(x.second == 0){
                        mp.erase(x.first);
                    }
                }
            }
            Temp = CHAR_MAX;
            for(auto x : mp){
                cout << x.first << ":" << x.second << endl;
            }
            for(auto x = mp.rbegin(); x != mp.rend(); x++){
                cout << x->first << ":" << x->second << endl;
            }
            for(auto x = mp.rbegin(); x != mp.rend(); x++){
                cout << "-------" <<x->first << endl;
                cout << x->first << ":" << x->second << endl;
                if(x->first < Temp){
                    res[index++] = x->first;
                    cout << x->first << endl;
                    mp[x->first]--;
                    Temp = x->first;
                    if(mp[x->first] == 0){
                        mp.erase(x->first);
                    }
                }
            }
        }
        cout << res << endl;
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.sortString("aaaabbbbcccc") << endl;
    return 0;
}

/* class Solution {
public:
    string sortString(string s) {
        vector<int> num(26);
        for (char &ch : s) {
            num[ch - 'a']++;
        }

        string ret;
        while (ret.length() < s.length()) {
            for (int i = 0; i < 26; i++) {
                if (num[i]) {
                    ret.push_back(i + 'a');
                    num[i]--;
                }
            }
            for (int i = 25; i >= 0; i--) {
                if (num[i]) {
                    ret.push_back(i + 'a');
                    num[i]--;
                }
            }
        }
        return ret;
    }
}; */