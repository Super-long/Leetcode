// 破坏回文串
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size() == 1) return "";
        int length = palindrome.size()/2;
        for(size_t i = 0; i < length; i++){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[palindrome.size()-1] = 'b';
        return palindrome;
    }
};

int main(){
    Solution sol;
    cout << sol.breakPalindrome("a") << endl;
    return 0;
}