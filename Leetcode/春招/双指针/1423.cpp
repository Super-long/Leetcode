#include <bits/stdc++.h>
using namespace std;

/* class Solution {    // 深搜也可以做，但是数组长度太大，会导致递归深度太大，而且不好剪枝
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lhs = 0;
        int intervalLength = cardPoints.size() - k;
        int result = INT_MAX;
        int sum = 0;
        for (int i = 0; i < cardPoints.size(); i++){
            sum += cardPoints[i];
            cout << sum << endl;
            if(i - lhs + 1 == intervalLength) {
                cout << result << " : " << sum << endl;
                result = min(result, sum);
                cout << result << endl;
                sum -= cardPoints[lhs++];
            }
        }
        if(k == cardPoints.size()) result = 0;
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - result;
    }
};
 */

class Solution {    // 这一题想的是把一个顺序的cardPoints拼在一起，然后求连起来的谁最大
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lhs = 0;
        int rhs = 0;
        int len = cardPoints.size();
        for (int i = 0; i < len; i++){
            cardPoints.push_back(cardPoints[i]);
        }

        int result = INT_MIN;
        int sum = 0;
        for (size_t i = 0; i < len*2; i++){
            sum += cardPoints[i];
            cout << " : " << sum << endl;
            while(i - lhs + 1 >= k && ((lhs <= len - 1 && i >= len - 1 || lhs <= len && i >= len))){
                if(i - lhs + 1 == k){
                    result = max(result, sum); cout << sum << endl;
                    cout << lhs << " " << i  << " " << result << endl;
                }
                sum -= cardPoints[lhs++];
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {96,90,41,82,39,74,64,50,30};
    cout << sol.maxScore(vec, 8) << endl;
}