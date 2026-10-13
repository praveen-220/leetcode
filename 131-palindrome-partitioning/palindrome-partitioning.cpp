class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }
        return true;
    }

    void solve(string& s, int start, vector<string>& path) {
        // Base case: entire string is partitioned
        if (start == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                // Choose
                path.push_back(s.substr(start, i - start + 1));

                // Recurse
                solve(s, i + 1, path);

                // Backtrack
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        solve(s, 0, path);
        return ans;
    }
};