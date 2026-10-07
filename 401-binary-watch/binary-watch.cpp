class Solution {
public:
    vector<string> ans;

    void solve(int index, int turnedOn, int hour, int minute) {
        // All 10 LEDs processed
        if (index == 10) {
            if (turnedOn == 0 && hour < 12 && minute < 60) {
                ans.push_back(
                    to_string(hour) + ":" +
                    (minute < 10 ? "0" : "") + to_string(minute)
                );
            }
            return;
        }

        // LED OFF
        solve(index + 1, turnedOn, hour, minute);

        // LED ON
        if (index < 4) {
            // Hour LEDs: 1, 2, 4, 8
            int value = 1 << index;

            if (hour + value < 12)
                solve(index + 1, turnedOn - 1, hour + value, minute);
        } else {
            // Minute LEDs: 1, 2, 4, 8, 16, 32
            int value = 1 << (index - 4);

            if (minute + value < 60)
                solve(index + 1, turnedOn - 1, hour, minute + value);
        }
    }

    vector<string> readBinaryWatch(int turnedOn) {
        solve(0, turnedOn, 0, 0);
        return ans;
    }
};