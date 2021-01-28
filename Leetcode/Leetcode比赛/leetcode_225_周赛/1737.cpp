#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int accumlate_bucket_lower(array<int, 26>& bucket, int target){
        int res = 0;
        for (size_t i = 0; i < target; i++){
            res += bucket[i];
        }
        return res;
    }
    
    int accumlate_bucket_upper(array<int, 26>& bucket, int target){
        int res = 0;
        for (size_t i = target; i < 26; i++){
            res += bucket[i];
        }
        return res;
    }

    int accumlate_bucket_equal(array<int, 26>& bucket, int target){
        int res = 0;
        for (size_t i = 0; i < 26; i++){
            if(i == target) continue;
            res += bucket[i];
        }
        return res;
    }
public:
    int minCharacters(string a, string b) {
        array<int, 26> bucketa;
        array<int, 26> bucketb;
        fill(bucketa.begin(), bucketa.end(), 0);
        fill(bucketb.begin(), bucketb.end(), 0);
        for(auto x : a) bucketa[x-'a']++;
        for(auto x : b) bucketb[x-'a']++;

        int res = INT_MAX;
        // step1: a严格小于b
        for (size_t i = 1; i < 26; i++){    // 基准数不会是a;因为a有一部分没办法再变小，可以看出其他更大的基准数一定更优
            cout << i << " " << accumlate_bucket_upper(bucketa, i) << " " << accumlate_bucket_lower(bucketb, i) << endl;
            res = min(res, accumlate_bucket_upper(bucketa, i) + accumlate_bucket_lower(bucketb, i));
        }
        cout << res << endl;
        // step2: b严格小于a
        for (size_t i = 1; i < 26; i++){    // 基准数不会是a
            res = min(res, accumlate_bucket_upper(bucketb, i) + accumlate_bucket_lower(bucketa, i));
        }
        cout << res << endl;
        // step3: a等于b
        for (size_t i = 0; i < 26; i++){
            res = min(res, accumlate_bucket_equal(bucketa, i) + accumlate_bucket_equal(bucketb, i));
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.minCharacters("dabadd", "cda") << endl;
    return 0;
}