class Solution {
private:
    int m;
    int n;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool find(vector<vector<char>>& board, int i, int j, int idx, string &word)
    {
        if(idx == word.length()) return true;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j] == '$') return false;
        if(board[i][j] != word[idx]) return false;
        char temp = board[i][j];
        board[i][j] = '$';
        //explore all directions
        for (int k = 0; k < 4; k++) {
            if (find(board, i + dx[k], j + dy[k], idx + 1, word)) {
                board[i][j] = temp;
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(); //row
        n = board[0].size(); //column
        if (word.size() > m * n) return false;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == word[0] && find(board, i, j, 0, word))
                {
                    return true;;
                }
            }
        }
        return false;
    }
};