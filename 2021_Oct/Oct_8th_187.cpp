//
// Created by smg_nwafu on 2021/10/8.
//
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution{
    const int L = 10;
    unordered_map<char, int> bin = {{'A', 0}, {'T', 1}, {'C', 2}, {'G', 3}};
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int n = s.length();
        if(n <= L)
            return ans;

        //初始化第一个滑窗的值
        int x = 0;
        for (int i = 0; i < L - 1; ++i) {
            x = (x << 2) | bin[s[i]];
        }

        //将每个滑窗的值存储到cnt中
        unordered_map<int, int> cnt;
        for (int i = 0; i <= n - L; ++i) {
            x = ((x << 2) | bin[s[i + L - 1]]) & ((1 << L * 2) - 1);
            ++cnt[x];
            if (cnt[x] == 2 )
                ans.push_back(s.substr(i, L));
        }

        return ans;
    }
};