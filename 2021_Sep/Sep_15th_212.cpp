//
// Created by smg_nwafu on 2021/9/16.
//
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;
struct TrieNode {
    string word;
    unordered_map<char, TrieNode *> children;
    TrieNode() {
        this->word = "";
    }
};

void insertTrie(TrieNode * root, const string & word) {
    TrieNode * node = root;
    for (auto c : word) {
        if (!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->word = word;
}

class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(vector<vector<char>>& board, int x, int y, TrieNode * root, set<string> & res) {
        char ch = board[x][y];
        if (!root->children.count(ch)) {
            return false;
        }
        root = root->children[ch];
        if (root->word.size() > 0 ) {
            res.insert(root->word);
            root->word = "";
        }

        board[x][y] = '#';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                if (board[nx][ny] != '#'){
                    dfs(board, nx, ny, root,res);
                }
            }
        }
        board[x][y] = ch;
        return true;
    }

    vector<string> findWords(vector<vector<char>> & board, vector<string> & words) {
        TrieNode * root = new TrieNode();
        set<string> res;
        vector<string> ans;

        for (auto & word: words) {
            insertTrie(root,word);
        }
        for (int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, res);
            }
        }
        for (auto & word: res) {
            ans.emplace_back(word);
        }
        return ans;
    }
};

