class Solution {
public:
    int minElement(vector<int>& nums) {
        vector<int>ans;
        int n=0;
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]){
                int digit=nums[i]%10;
                n=n+digit;
                nums[i]/=10;
            }
            ans.push_back(n);
            n=0;
        }
        int mini=INT_MAX;
        for(int i=0;i<ans.size();i++)
        {
            mini=min(mini,ans[i]);
        }
        return mini;
    }
};