
class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for (int i = index; i < nums.size(); i++) {
            if (used.count(nums[i]))
                continue;

            used.insert(nums[i]);

            swap(nums[index], nums[i]);

            backtrack(nums, index + 1);

            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};
