#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int col = image.size(); // 纯模拟，其实可以用双指针模拟优化
        for (int i = 0; i < col; ++i){
            for_each(image[i].begin(), image[i].end(), [](int& para){
                para = para ? 0 : 1;
            });
            reverse(image[i].begin(), image[i].end());
        }
        return image;
    }
};