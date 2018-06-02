### 思路
1. 我的方法
*  先排序，取奇数索引累加即可。nlogn的复杂度。
缺点是：第一改变了数组，第二太慢，不过好像也没o(n)的算法
2. 哈希表，用了之后超过了96%的时间
*  f(i) = max(f(i-1),cur+1)  nums[i]=1;
```C++
int arrayPairSum(vector<int>& nums) {
        vector<int> hashtable(20001,0);
        int sum=0;
        bool flag=true;
        for(int i=0;i<nums.size();i++){
            hashtable[nums[i]+10000]++;
        }
        for(int i=0;i<hashtable.size();i++){
            if(hashtable[i]==0)
                continue;
            do{
            if(flag==true){
                flag=false;
                sum +=i-10000;
            }  
            else
                flag=true;
            }
            while(--hashtable[i]!=0);  
        }
        return sum;
    }
```
