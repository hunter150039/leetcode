超过91%
算出本来的总和，算出实际的总和最差。缺点是：当n很大时，大于65536或者2……16，sum会溢出

异或方法是最好的：
原理，A^C^B^A^C=A^A^C^C^B = B，所以把0~n的所有应该的n+1个数，与实际的n个数异或，多余出来的一个数就是少的那个。
https://leetcode.com/problems/missing-number/discuss/69786/3-different-ideas:-XOR-SUM-Binary-Search.-Java-code?page=1


