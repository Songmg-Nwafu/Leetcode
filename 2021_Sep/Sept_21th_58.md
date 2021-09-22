# Sept_21th_58 最后一个单词长度
## 题目

给你一个字符串 `s`，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中最后一个单词的长度。

**单词** 是指仅由字母组成、不包含任何空格字符的最大子字符串。

## 输出示例

```bash
输入：s = "Hello World"
输出：5
```

## 解答

反向遍历

```cpp
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
```
[code](https://github.com/Songmg-Nwafu/Leetcode/blob/main/2021_Sep/Sep_21th_58.cpp)