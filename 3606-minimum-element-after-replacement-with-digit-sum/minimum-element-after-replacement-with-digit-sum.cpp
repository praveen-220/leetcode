class Solution {
public:
    int minElement(vector<int>& nums) {
        vector<int>ans;
        int n=0;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]){
                int digit=nums[i]%10;
                n=n+digit;
                nums[i]/=10;
            }
            ans.push_back(n);
            mini=min(mini,ans[i]);
            n=0;
        }
        return mini;
    }
};