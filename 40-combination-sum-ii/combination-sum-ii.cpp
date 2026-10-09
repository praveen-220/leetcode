class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int start, int target,
               vector<int>& current) {

        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicate values at the same level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // No need to continue if the number is too large
            if (candidates[i] > target)
                break;

            current.push_back(candidates[i]);

            // Each element can be used only once
            solve(candidates, i + 1, target - candidates[i], current);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> current;
        solve(candidates, 0, target, current);

        return ans;
    }
};