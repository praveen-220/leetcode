class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int k=0;
        int n=nums.size();
        while(i<n)
        {
            if(nums[i]==0)
            {
                i++;
                continue;
            }
            nums[k++]=nums[i++];
        }
        while(k<n)
        {
            nums[k++]=0;
        }
       
    }
};