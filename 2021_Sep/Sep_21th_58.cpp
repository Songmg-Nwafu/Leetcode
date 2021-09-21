//
// Created by smg_nwafu on 2021/9/21.
//
#include <iostream>

using namespace std;

class Solution{
public:
    int lengthOfLastWord(string s) {
        int index = s.size() - 1;
        while (s[index] != ' '){
            index--;
        }

        int wordLength = 0;
        while (index >=0 && s[index] != ' '){
            wordLength++;
            index--;
        }
        return wordLength;
    }
};
