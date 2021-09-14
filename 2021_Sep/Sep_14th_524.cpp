//
// Created by smg_nwafu on 2021/9/14.
//
#include <vector>
#include <dbg.h>

using namespace std;

/**
 * 524. 通过删除字母匹配到字典里最长单词
 */
class Solution{
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans;
        for (string cur : dictionary){
            int j = 0;
            for (int i = 0; i < s.size() && j < cur.size(); ++i) {
                if (cur[j] == s[i])
                    j++;
            }

            if (j == cur.size()){
                if (j > ans.size())
                    ans = cur;
                else if (j == ans.size()){
                    ans = cur < ans ? cur : ans;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<string> dictionary = {"ale","apple","monkey","plea"};
    string s = "abpcplea";
    Solution solution;
    dbg(solution.findLongestWord(s, dictionary));
}