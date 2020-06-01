// 竖直打印单词
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> printVertically(string s) {
        stringstream ss(s);
        vector<string> vec;
        string T;
        int MAX = 0;
        while(ss >> T){
            vec.push_back(T);
            MAX = max(static_cast<size_t>(MAX), T.size());
        }
        vector<string> res;
        int index = 0;
        for(size_t i = 0; i < MAX; i++){
            string Temp;
            for(size_t j = 0; j < vec.size(); j++){
                if(index<vec[j].size())
                    Temp.push_back(vec[j][index]);
                else 
                    Temp.push_back(' ');
            }
            // find_last_not_of, 寻找最后一个出现不是第一个参数的字符串
            // find_first_of, 寻找第一个出现的字符串
            Temp.erase(Temp.find_last_not_of(" ") + 1);
            index++;
            res.push_back(Temp);
        }
        
        return res;
    }
};

int main(){
    Solution sol;
    string str = "TO BE OR NOT TO BE";
    auto x = sol.printVertically(str);
    for(auto item : x){
        cout << item << endl;
    }
    return 0;
}