class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int start, int n, int k, vector<int>& current) {
        // Base case
        if (current.size() == k) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i <= n; i++) {
            // Choose
            current.push_back(i);

            // Recurse
            solve(i + 1, n, k, current);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        solve(1, n, k, current);
        return ans;
    }
};