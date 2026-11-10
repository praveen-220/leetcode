class Solution {
public:
    struct Compare {
        bool operator()(pair<string, int>& a, pair<string, int>& b) {
            if (a.second == b.second)
                return a.first > b.first;

            return a.second < b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        for (string word : words) {
            mp[word]++;
        }

        priority_queue<pair<string, int>,
                       vector<pair<string, int>>,
                       Compare> pq;

        for (auto it : mp) {
            pq.push({it.first, it.second});
        }

        vector<string> ans;

        while (k--) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};