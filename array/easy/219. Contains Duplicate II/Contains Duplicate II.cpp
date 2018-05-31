class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0 || nums.size()<=1)
            return false;
        unordered_map<int,int> counts;
        //counts[nums[0]]=0;
        for(int i=0;i<nums.size();++i){
            if(counts[nums[i]]==0){
                counts[nums[i]]=i+1;
                continue;
            }
            if(i+1-counts[nums[i]]<=k){
                return true;
            }
            else
                counts[nums[i]]=i+1;
        }
        return false;  

    }
};
