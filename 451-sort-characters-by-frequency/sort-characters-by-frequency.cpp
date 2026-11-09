class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        // Count frequency
        for (char ch : s) {
            mp[ch]++;
        }

        // Max heap
        priority_queue<pair<int, char>> pq;

        for (auto it : mp) {
            pq.push({it.second, it.first});
        }

        // Build answer
        string ans = "";

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            ans += string(top.first, top.second);
        }

        return ans;
    }
};