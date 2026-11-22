class Solution {
public:
    bool containsNearbyAlmostDuplicate(
        vector<int>& nums,
        int indexDiff,
        int valueDiff
    ) {
        multiset<long long> ms;

        for (int i = 0; i < nums.size(); i++) {

            // Find first element >= nums[i] - valueDiff
            auto it = ms.lower_bound(
                (long long)nums[i] - valueDiff
            );

            // Check whether a valid element exists
            if (it != ms.end() &&
                *it <= (long long)nums[i] + valueDiff) {
                return true;
            }

            // Insert current element
            ms.insert(nums[i]);

            // Maintain window of size indexDiff
            if (ms.size() > indexDiff) {
                ms.erase(ms.find(nums[i - indexDiff]));
            }
        }

        return false;
    }
};