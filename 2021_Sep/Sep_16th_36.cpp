//
// Created by smg_nwafu on 2021/9/17.
//
#include <vector>

using namespace std;
/**
 * 36. 有效的数独
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9];
        int cols[9][9];
        int boxs[3][3][9];

        memset(rows, 0,sizeof(rows));
        memset(cols, 0,sizeof(cols));
        memset(boxs, 0,sizeof(boxs));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.'){
                    int index = c - '0' - 1;
                    rows[i][index]++;
                    cols[j][index]++;
                    boxs[i / 3][j / 3][index]++;
                    if (rows[i][index] > 1 || cols[j][index] > 1 || boxs[i / 3][j / 3][index] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};