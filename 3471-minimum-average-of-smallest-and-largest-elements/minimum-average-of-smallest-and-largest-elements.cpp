class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;

        double ans = INT_MAX;

        while (left < right) {
            double avg = (nums[left] + nums[right]) / 2.0;

            ans = min(ans, avg);

            left++;
            right--;
        }

        return ans;
    }
};