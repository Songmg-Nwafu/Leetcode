//
// Created by smg_nwafu on 2021/9/23.
//
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
