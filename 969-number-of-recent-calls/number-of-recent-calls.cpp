class RecentCounter {
    queue<int> q;

public:
    RecentCounter() {}

    int ping(int t) {

        // Add current request
        q.push(t);

        // Remove requests older than 3000 ms
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }

        // Number of requests in the current range
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */