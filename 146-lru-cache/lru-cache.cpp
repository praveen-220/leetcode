class LRUCache {
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        auto it = mp[key];
        int value = it->second;

        l.erase(it);
        l.push_front({key, value});

        mp[key] = l.begin();

        return value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            l.erase(mp[key]);
        }
        else if (l.size() == capacity) {
            int oldKey = l.back().first;
            l.pop_back();
            mp.erase(oldKey);
        }

        l.push_front({key, value});
        mp[key] = l.begin();
    }
};