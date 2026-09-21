class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word,
             int r, int c, int k) {

        // Word completely found
        if (k == word.size())
            return true;

        // Out of bounds
        if (r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size())
            return false;

        // Character doesn't match
        if (board[r][c] != word[k])
            return false;

        // Mark current cell as visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Try 4 directions
        bool found =
            dfs(board, word, r + 1, c, k + 1) ||  // down
            dfs(board, word, r - 1, c, k + 1) ||  // up
            dfs(board, word, r, c + 1, k + 1) ||  // right
            dfs(board, word, r, c - 1, k + 1);    // left

        // Backtrack
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (board[r][c] == word[0]) {
                    if (dfs(board, word, r, c, 0))
                        return true;
                }
            }
        }

        return false;
    }
};