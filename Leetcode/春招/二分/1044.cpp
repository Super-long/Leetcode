#include <bits/stdc++.h>
using namespace std;

// 二分+旋转哈希(robin-karp，可以在常数时间内切片，187也这么做)
class Solution {    // 没过掉；不过基本知道这题的做法了
private:
    int check(long len, const vector<long>& str, long modulus){
        long hashValue = 0;
        for (size_t i = 0; i < len; i++){
            hashValue = (hashValue * 26 + str[i]) % modulus;
        }
        unordered_set<long> se;
        se.insert(hashValue);

        long aL = 1;
        for (int i = 1; i <= len; ++i) aL = (aL * 26) % modulus; // 26的len次方

        for (int start = 1; start < str.size() - len + 1; ++start) {
            hashValue = (hashValue * 26 - str[start - 1] * aL % modulus + modulus) % modulus;
            hashValue = (hashValue + str[start + len - 1]) % modulus;
            if (se.find(hashValue) != se.end()) return start;
            se.insert(hashValue);
        }
        cout << len << " : 返回-1\n";
        return -1;
    }
public:
    string longestDupSubstring(string s) {
        long lhs = 1;
        long rhs = s.size() - 1;
        long ans = s.size();
        vector<long> array;
        for(auto x : s){
            array.push_back(x - 'A');
        }

        long res_lhs = 0;
        long res = 0;
        long modulus = (long)pow(2, 32);
        while(lhs <= rhs){
            long mid = lhs + (rhs - lhs) / 2;
            res_lhs = check(mid, array, modulus);
            cout << "asdasdasd : " << res_lhs << endl;
            if(res_lhs == -1){
                rhs = mid - 1;
                ans = mid;
                cout << mid << "nihao\n";
            } else {
                cout << mid << "world\n";
                res = res_lhs;
                cout << "res : " << res_lhs << endl;
                lhs = mid + 1;
            }
        }
        cout << res << " " << ans << endl;
        return ans == s.size() ? "" : s.substr(res, ans - 1);
    }
};

int main(){
    Solution sol;
    cout << sol.longestDupSubstring("aa") << endl;
    return 0;
}