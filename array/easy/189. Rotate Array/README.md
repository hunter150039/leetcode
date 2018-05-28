击败85%
题目的操作相当于，将每个数后移k位，为了用o(1)的空间复杂度，需要链式移动，依次吧0,3,6,2,5,1,4,0的值向后移。
需要两个变量来存储两个值，注意用do while。

其他好方法：
1.
https://leetcode.com/problems/rotate-array/discuss/54249/3-line-using-reverse/140853
void rotate(int nums[], int n, int k) {
    reverse(nums,nums+n);
    reverse(nums,nums+k%n);
    reverse(nums+k%n,nums+n);
}


