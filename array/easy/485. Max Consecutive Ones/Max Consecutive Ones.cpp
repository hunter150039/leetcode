class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0;
        int currlen=0;
        bool ing1 = false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(currlen>max){
                    max =currlen;
                }   
                currlen=0;
                ing1=false;
                continue;
            }
            if(ing1==false){
                ing1=true;
                currlen=1;
            }
            else{
                currlen++;
            }         
        }
        if(currlen>max){
            max =currlen;
        }
        return max;
    }
};
