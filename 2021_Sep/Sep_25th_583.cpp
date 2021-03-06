//
// Created by smg_nwafu on 2021/9/25.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution{
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();

        vector<vector<int>> dp(size1 + 1,vector<int>(size2 + 1));

        for (int i = 1; i <= size1; ++i) {
            char c1 = word1[i - 1];
            for (int j = 1; j <= size2; ++j) {
                char c2 = word2[j - 1];
                if (c1 == c2){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return size1 + size2 - 2 * dp[size1][size2];
    }
};

