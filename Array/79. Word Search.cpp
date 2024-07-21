class Solution {
public:
    vector<pair<int, int>> dir{{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    bool dfs(vector<vector<char>>& board, string& word, int idx, int m, int n) {
        if (idx == word.length()) return true;

        char temp = board[m][n];
        board[m][n] = '#'; // Mark as visited

        for (int i = 0; i < 4; i++) {
            int x = m + dir[i].first;
            int y = n + dir[i].second;

            if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size() &&
                board[x][y] == word[idx]) {
                if (dfs(board, word, idx + 1, x, y)) {
                    return true;
                }
            }
        }

        board[m][n] = temp; // Unmark visited cell
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, 1, i, j)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
