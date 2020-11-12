#include <bits/stdc++.h>
using namespace std;

// 经典topK

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {  // 快速选择
        srand(unsigned(time(nullptr)));
        unordered_multimap<int, vector<int>> distanceToPoint;   // 其实直接把坐标带进去算最好，就不需要这个map了
        vector<int> arr(points.size());
        for (size_t i = 0; i < points.size(); i++){
            arr[i] = points[i][0]*points[i][0] + points[i][1]*points[i][1]; 
            //distanceToPoint[arr[i]] = std::move(points[i]);
            distanceToPoint.insert(make_pair(arr[i], std::move(points[i])));
        }
        dfs(0, arr.size() - 1,  arr, K);
        
        vector<vector<int>>  result(K);

        int i = 0;
        int index = 0;
        while(index < K){
                auto MpRange = distanceToPoint.equal_range(arr[i]);
            	for (auto it = MpRange.first; it != MpRange.second; ++it) {
                    result[index++] = std::move(it->second);
                    if(index >= K) break;
	            }
                i++;
        }
        return result;
    }

    void dfs(int lhs, int rhs, vector<int>& arr, int k){
        if (lhs >= rhs){
            return;
        }

        int pos = random_partition(lhs, rhs, arr);
        int num = pos - lhs + 1;    // 此轮ok的数量

        if(num == k){
            return;
        } else if(num > k){
            dfs(lhs, pos - 1, arr, k);
        } else {
            dfs(pos+1, rhs, arr, k  - num);
        }
    }

    int random_partition(int lhs, int rhs, vector<int>& arr){
        int index = rand()%(rhs - lhs + 1) + lhs;
        swap(arr[index], arr[rhs]);
        return  partition(lhs, rhs, arr); // 返回的是中间值的下标
    }

    int partition(int lhs, int rhs, vector<int>& arr){
        int pivot = arr[rhs];
        int i = lhs - 1;
        for(int j = lhs; j <= rhs -1; ++j){
            if(arr[j] <= pivot){
                i+=1;
                swap(arr[i], arr[j]);
            }
        }
        // 此时从lhs开始有i个小于pivot的值
        swap(arr[i + 1], arr[rhs]);
        return i+1;
    }
};