class Solution {
public:
    vector<string> ans;

    vector<string> letters = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(string& digits, int index, string& current) {
        // Base case
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        int digit = digits[index] - '0';

        for (char ch : letters[digit]) {
            current.push_back(ch);

            solve(digits, index + 1, current);

            current.pop_back();  // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        string current;
        solve(digits, 0, current);

        return ans;
    }
};