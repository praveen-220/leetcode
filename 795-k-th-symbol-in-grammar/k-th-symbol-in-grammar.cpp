class Solution {
public:
    int kthGrammar(int n, int k) {
        // Base case
        if (n == 1)
            return 0;

        // Find parent position
        int parent = kthGrammar(n - 1, (k + 1) / 2);

        // Odd position -> same as parent
        if (k % 2 == 1)
            return parent;

        // Even position -> opposite of parent
        return 1 - parent;
    }
};