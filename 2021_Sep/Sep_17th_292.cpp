//
// Created by smg_nwafu on 2021/9/18.
//
/*
 * 博弈论  Nim游戏
 */
class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4 != 0);
    }
};

/*
 * 在这里说明一下  n % 4 是与 n & 3 等价的。
 *
 * 当 length = 2^n 时，X % length = X & (length - 1)
 */