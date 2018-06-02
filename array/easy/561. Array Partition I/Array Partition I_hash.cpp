class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> hashtable(20001,0);
        int sum;
        int flag=1;
        for(int i=0;i<nums.size();i++){
            hashtable[nums[i]+10000]++;
        }
        for(int i=0;i<20001;i++){
            if(hashtable[i]==0)
                continue;   
        }
    }
};
