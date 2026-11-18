class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        multiset<int> ms;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            ms.insert(nums[right]);

            // Shrink window if difference exceeds limit
            while (*ms.rbegin() - *ms.begin() > limit) {

                ms.erase(ms.find(nums[left]));
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};