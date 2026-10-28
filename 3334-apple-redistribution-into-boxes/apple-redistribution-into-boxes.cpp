class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0;

        for (int x : apple) {
            total += x;
        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        int boxes = 0;

        for (int cap : capacity) {
            total -= cap;
            boxes++;

            if (total <= 0) {
                return boxes;
            }
        }

        return boxes;
    }
};