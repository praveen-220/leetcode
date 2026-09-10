class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        int n = s.size();

        if (n == 1)
            return false;

        for (int i = 1; i <= n / 2; i++)
        {
            if (n % i != 0)
                continue;

            bool val = true;

            for (int j = 0; j < n; j++)
            {
                if (s[j] != s[j % i])
                {
                    val = false;
                    break;
                }
            }

            if (val)
                return true;
        }

        return false;
    }
};