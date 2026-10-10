class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& current,
               vector<bool>& used) {

        // Base case: permutation is complete
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;

            // Choose
            used[i] = true;
            current.push_back(nums[i]);

            // Recurse
            solve(nums, current, used);

            // Backtrack
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        vector<bool> used(nums.size(), false);

        solve(nums, current, used);

        return ans;
    }
};