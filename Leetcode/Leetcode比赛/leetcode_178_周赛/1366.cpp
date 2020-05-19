//通过投票对团队排名
#include <bits/stdc++.h>
using namespace std;

class Solution { // 这样写思路大体对 但是忽略了一些情况,就是可能2个1剩下都是倒数第一 也大于 1个1剩下都是2
public:
    string rankTeams(vector<string>& votes) {
        map<char, int> mp;
        for(const auto& item : votes){
            for(size_t i = 0; i < item.size(); i++){
                mp[item[i]] += i+1;
            }
        }
        vector<std::pair<int,char>> vec;
        for(auto x : mp){
            vec.push_back(std::make_pair(x.second, x.first));
        }

        sort(vec.begin(), vec.end());
        string res;
        for(auto x : vec){
            cout << x.second << " " << x.first << endl;
            res += x.second;
        }
        return res;
    }
};

/* class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        // 初始化哈希映射
        unordered_map<char, vector<int>> ranking;
        for (char vid: votes[0]) {
            ranking[vid].resize(votes[0].size());
        }
        // 遍历统计
        for (const string& vote: votes) {
            for (int i = 0; i < vote.size(); ++i) {
                ++ranking[vote[i]][i]; //代表着每一个排名其得到的次数
            }
        }
        
        // 取出所有的键值对
        using PCV = pair<char, vector<int>>;
        vector<PCV> result(ranking.begin(), ranking.end());
        // 排序
        sort(result.begin(), result.end(), [](const PCV& l, const PCV& r) {
            //当排名相同的时候比较字典序
            return l.second > r.second || (l.second == r.second && l.first < r.first);
        });
        string ans;
        for (auto& [vid, rank]: result) {
            cout << "vid : " <<  vid  ;
            for(auto x : rank){
                cout << x << " ";
            }
            putchar('\n');
            ans += vid;
        }
        return ans;
    }
}; */

int main(){
    Solution sol;
    vector<string> vec = {"FVSHJIEMNGYPTQOURLWCZKAX","AITFQORCEHPVJMXGKSLNZWUY","OTERVXFZUMHNIYSCQAWGPKJL","VMSERIJYLZNWCPQTOKFUHAXG","VNHOZWKQCEFYPSGLAMXJIUTR","ANPHQIJMXCWOSKTYGULFVERZ","RFYUXJEWCKQOMGATHZVILNSP","SCPYUMQJTVEXKRNLIOWGHAFZ","VIKTSJCEYQGLOMPZWAHFXURN","SVJICLXKHQZTFWNPYRGMEUAO","JRCTHYKIGSXPOZLUQAVNEWFM","NGMSWJITREHFZVQCUKXYAPOL","WUXJOQKGNSYLHEZAFIPMRCVT","PKYQIOLXFCRGHZNAMJVUTWES","FERSGNMJVZXWAYLIKCPUQHTO","HPLRIUQMTSGYJVAXWNOCZEKF","JUVWPTEGCOFYSKXNRMHQALIZ","MWPIAZCNSLEYRTHFKQXUOVGJ","EZXLUNFVCMORSIWKTYHJAQPG","HRQNLTKJFIEGMCSXAZPYOVUW","LOHXVYGWRIJMCPSQENUAKTZF","XKUTWPRGHOAQFLVYMJSNEIZC","WTCRQMVKPHOSLGAXZUEFYNJI"};
    cout << sol.rankTeams(vec) << endl;
    return 0;
}