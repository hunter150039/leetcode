class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length=nums.size();
        k = k%length;
        int n=0,temp_befo,temp_after;
        for(int i=0;i<k;i++){
            if(n==length)
                return;
            int j=i;
            int j_k_after=(j+k)%length;
            temp_befo = nums[j];
            do{
                temp_after = nums[j_k_after];
                nums[j_k_after] = temp_befo;
                temp_befo = temp_after;             
                j=j_k_after;
                j_k_after=((j_k_after+k)%length);            
                n++;
            }while(j!=i);
        }

    }
};
