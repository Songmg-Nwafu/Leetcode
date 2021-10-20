//
// Created by smg_nwafu on 2021/10/20.
//
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
public:
    int minMove(vector<int>& nums){
        int minNum = *min_element(nums.begin(), nums.end());
        int res = 0;
        for (auto num: nums){
            res += num - minNum;
        }
        return res;
    }
};
