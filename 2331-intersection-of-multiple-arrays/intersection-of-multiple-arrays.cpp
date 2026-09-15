class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> count;
        vector<int> ans;

        for (auto& arr : nums) {
            for (int x : arr) {
                count[x]++;
            }
        }

        for (auto& p : count) {
            if (p.second == nums.size()) {
                ans.push_back(p.first);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};