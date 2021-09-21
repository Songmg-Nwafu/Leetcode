# Sep_14th_524 通过删除字母匹配到字典里最长单词
## 题目
给你一个字符串 s 和一个字符串数组 dictionary 作为字典，找出并返回字典中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。

如果答案不止一个，返回长度最长且字典序最小的字符串。如果答案不存在，则返回空字符串。


## 输出示例
输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
输出："apple"

## 解答
只要判断dictionary[i]是否是s的子字符串就即可，找到最长的子字符串，如果相同比较字典序大小即可。

[code](https://github.com/Songmg-Nwafu/Leetcode/blob/main/2021_Sep/Sep_14th_524.cpp)