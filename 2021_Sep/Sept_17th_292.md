#Sep_17th_292 Nim游戏

# 题目
你和你的朋友，两个人一起玩 Nim 游戏：

- 桌子上有一堆石头。
- 你们轮流进行自己的回合，你作为先手。
- 每一回合，轮到的人拿掉 1 - 3 块石头。
- 拿掉最后一块石头的人就是获胜者。

假设你们每一步都是最优解。请编写一个函数，来判断你是否可以在给定石头数量为 n 的情况下赢得游戏。如果可以赢，返回 true；否则，返回 false 。
# 输出示例
```cpp
输入：n = 4
输出：false 
解释：如果堆中有 4 块石头，那么你永远不会赢得比赛；
     因为无论你拿走 1 块、2 块 还是 3 块石头，最后一块石头总是会被你的朋友拿走。
```
# 解答
可以发现，只要是一个人开始拿石头的时候，石头的数量为4，那么这个人必输。在石头数量为1-3，先手就赢；石头数量为4时候，先手就输；石头数量为5-7的时候，可以拿1-3块石头，使石头数量为4，这样后手拿石头的时候数量为4，必输；石头数量为8的时候，先手无论拿几块，后手都可以将石头数量拿到为4，这样先手必输，可见石头数量为8的时候，先手也比输。可以推断为，石头数量为4的倍数的时候先手必输。
```cpp
class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4 != 0);
    }
};
```