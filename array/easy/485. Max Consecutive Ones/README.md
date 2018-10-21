### 思路
1. 我的方法
*  这个题比较简单，大家时间都差不多，37ms到39ms就已经从97%到50%了，就是把从头到尾遍历一遍，每两个值之间的状态跳变有四种情况：
0->0 与1->0 相同 都是总结前一段，状态清零
0->1 开始计数，长度置一
1->1 长度加一，
但应该涉及到状态的化简。后两种也可以归为一种，所以有了简化版。
2. DP
*  f(i) = max(f(i-1),cur+1)  nums[i]=1;
```C++
        int max_cnt = 0, cnt = 0;
        for (auto n : nums) {
            if (n == 1) max_cnt = max(++cnt, max_cnt);
            else cnt = 0;
        }
        return max_cnt;

```


