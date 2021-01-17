#include <bits/stdc++.h>
using namespace std; 

/* class Solution {
private:
    unordered_map<string, int> mapCount;
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        for(auto x : words){
            mapCount[x]++;
        }
        int vaild = 0;
        int index = 0;
        int itemSize = words[0].size();
        while(index < itemSize){
            int resStart = index;
            unordered_map<string, int> mapVaild;
            for (size_t i = index; i < s.size(); i+=itemSize){
                auto temp = s.substr(i, itemSize);
                cout << temp << endl;
                if(mapCount.find(temp) != mapCount.end() && mapVaild[temp] < mapCount[temp]){
                    mapVaild[temp]++;
                    if(mapVaild[temp] == mapCount[temp]){
                        vaild++;
                    }
                } else {
                    bool flag = mapVaild[temp] >= mapCount[temp];
                    resStart = i + itemSize;
                    mapVaild.clear();
                    vaild = 0;
                    if(flag){
                        resStart = i;
                        mapVaild[temp]++;
                        if(mapCount[temp] == mapVaild[temp]){
                            vaild++;
                        }
                    }
                    continue;
                }
                while((i - resStart)/itemSize + 1 >= words.size()){
                    if(vaild == mapCount.size()){
                        res.push_back(resStart);
                        auto temp = s.substr(resStart, itemSize);
                        if(mapVaild[temp] == mapCount[temp]){
                            vaild--;
                        }
                        mapVaild.erase(temp);
                        resStart += itemSize;
                    } else {    // 
                        //cout << vaild << endl;
                    }
                }
            }
            index++;
        }
        return res;
    }
};
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.empty()) return res;
        int n = s.size(), m = words.size(), w = words[0].size();
        unordered_map<string, int> tot;
        for(string& word: words)
            tot[word]++;
        // 枚举余数？
        for(int i = 0; i < w; i++)
        {
            int suc = 0;
            unordered_map<string, int> window;
            for(int j = i; j + w <= n; j += w)
            {
                if(j >= i + m * w)
                {
                    string cur = s.substr(j - m * w, w);
                    window[cur]--;
                    if(window[cur] < tot[cur]) 
                        suc--;
                }
                string cur = s.substr(j, w);
                window[cur] ++;
                if(window[cur] <= tot[cur])
                    suc++;
                if(suc == m)
                    res.push_back(j - (m - 1) * w);
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<string> vec = {"bar","foo"};
    auto temp = sol.findSubstring("barfoothefoobarman", vec);
    for(auto x : temp){
        cout << x << endl;
    }
    return 0;
}