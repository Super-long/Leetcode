// 山羊拉丁文
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        stringstream ss(S);
        string res;
        string word;
        int number = 1;
        unordered_set<char> se = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while(ss >> word){
            string Temp(number, 'a');
            if(se.find(word[0]) != se.end()){
                res += word + "ma" +  Temp;
            }else {
                string Main(word.begin()+1, word.end());
                res += Main + word[0] + "ma" + Temp; 
            }
            res += " ";
            ++number;
        }
        res.erase(res.end()-1, res.end());
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.toGoatLatin("The quick brown fox jumped over the lazy dog") << endl;
    return 0;
}