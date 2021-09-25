# Sept_23th_326. 3的幂

## 题目

给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。

## 输出示例

```
输入：n = 0
输出：false
```

## 解答

我们不断地将 n 除以 3，直到 n=1。如果此过程中 n 无法被 3 整除，就说明 n不是 3 的幂。

本题中的 n 可以为负数或 0，可以直接提前判断该情况并返回 False，也可以进行试除，因为负数或 0 也无法通过多次除以 3 得到 1。

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n && n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};
```

在题目给定的 32 位有符号整数的范围内，最大的 3 的幂为 3^{19} = 1162261467。我们只需要判断 n 是否是 3^{19}的约数即可。
[code](https://github.com/Songmg-Nwafu/Leetcode/blob/main/2021_Sep/Sep_23th_326.cpp)
```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
```

### 2 的幂

- 任何整数乘以2，都相当于向左移动了一位，而2的0次幂为1，所以2的n次幂就是1向左移动n位。这样，2的幂的特征就是二进制表示只有最高位为1，其他位均为0。那么，我们只要判断一个数的二进制表示只有一个1，那么它就是2的幂。

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n&(n - 1) == 0;
    }
};
```

### 4 的幂

- 4的幂首先得得满足是2的幂
- n % 3 == 1

```cpp
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && n&(n - 1) == 0 && n % 3 == 1; 
    }
};
```