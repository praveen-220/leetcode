class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }

        auto& v = mp[key];

        int left = 0;
        int right = v.size() - 1;
        int ans = -1;

        // Find the largest timestamp <= given timestamp
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (v[mid].first <= timestamp) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return (ans == -1) ? "" : v[ans].second;
    }
};