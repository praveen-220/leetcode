class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if (n % groupSize != 0) {
            return false;
        }

        map<int, int> mp;

        // Count frequency of each card
        for (int num : hand) {
            mp[num]++;
        }

        // Process cards from smallest to largest
        while (!mp.empty()) {

            int first = mp.begin()->first;

            // Form a consecutive group
            for (int i = 0; i < groupSize; i++) {

                int card = first + i;

                if (mp.find(card) == mp.end()) {
                    return false;
                }

                mp[card]--;

                if (mp[card] == 0) {
                    mp.erase(card);
                }
            }
        }

        return true;
    }
};