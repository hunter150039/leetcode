超84%
就是两个指针，一个正常遍历，一个说明当前有几个非零的数，索引值为数减一，最后补0。
// move all the nonzero elements advance

其他方法，使用stl算法
https://leetcode.com/problems/move-zeroes/discuss/72132/One-line-c++-code-20ms
fill(remove(nums.begin(), nums.end(),0), nums.end(), 0);

慢办法，也是两个指针，但是要交换0与后面的数



