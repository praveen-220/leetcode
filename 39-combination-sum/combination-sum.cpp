class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int index, int target,
               vector<int>& current) {

        // Target reached
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        // Target exceeded
        if (target < 0)
            return;

        for (int i = index; i < candidates.size(); i++) {

            // Choose
            current.push_back(candidates[i]);

            // Same number can be used again
            solve(candidates, i, target - candidates[i], current);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;

        solve(candidates, 0, target, current);

        return ans;
    }
};