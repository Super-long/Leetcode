// 模式匹配
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool patternMatching(string pattern, string value) {
        int count_a = 0, count_b = 0;
        for (char ch: pattern) {
            if (ch == 'a') {
                ++count_a;
            } else {
                ++count_b;
            }
        }
        if (count_a < count_b) {
            swap(count_a, count_b);
            for (char& ch: pattern) {
                ch = (ch == 'a' ? 'b' : 'a');
            }
        }
        if (value.empty()) {
            return count_b == 0;
        }
        if (pattern.empty()) {
            return false;
        }
        for (int len_a = 0; count_a * len_a <= value.size(); ++len_a) {
            int rest = value.size() - count_a * len_a;
            if ((count_b == 0 && rest == 0) || (count_b != 0 && rest % count_b == 0)) {
                int len_b = (count_b == 0 ? 0 : rest / count_b);
                int pos = 0;
                bool correct = true;
                string value_a, value_b;
                for (char ch: pattern) {
                    if (ch == 'a') {
                        string sub = value.substr(pos, len_a);
                        if (!value_a.size()) {
                            value_a = move(sub);
                        } else if (value_a != sub) {
                            correct = false;
                            break;
                        }
                        pos += len_a;
                    } else {
                        string sub = value.substr(pos, len_b);
                        if (!value_b.size()) {
                            value_b = move(sub);
                        } else if (value_b != sub) {
                            correct = false;
                            break;
                        }
                        pos += len_b;
                    }
                }
                if (correct && value_a != value_b) {
                    return true;
                }
            }
        }
        return false;
    }
};