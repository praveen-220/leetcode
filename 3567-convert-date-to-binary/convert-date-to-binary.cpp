class Solution {
public:
    string binary(int n) {
        string ans = "";

        while (n > 0) {
            ans = to_string(n % 2) + ans;
            n /= 2;
        }

        return ans;
    }

    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        return binary(year) + "-" +
               binary(month) + "-" +
               binary(day);
    }
};