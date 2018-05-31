class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0;
        int currlen=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                max = currlen>max?currlen:max;
                currlen=0;
            }
            else
                currlen++;
        }
        return currlen>max?currlen:max;
    }
};
