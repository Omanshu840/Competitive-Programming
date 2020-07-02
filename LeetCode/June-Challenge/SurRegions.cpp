class Solution
{
public:
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        int n = board.size();
        int m = board[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m)
        {
            return;
        }

        if (board[i][j] == 'X' || board[i][j] == '*')
        {
            return;
        }

        board[i][j] = '*';

        dfs(board, i - 1, j);
        dfs(board, i, j - 1);
        dfs(board, i + 1, j);
        dfs(board, i, j + 1);
    }

    void solve(vector<vector<char>> &board)
    {

        if (board.size() == 0 || board[0].size() == 0)
        {
            return;
        }

        int n = board.size();
        int m = board[0].size();

        int i, j;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                {
                    if (board[i][j] == 'O')
                    {
                        dfs(board, i, j);
                    }
                }
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (board[i][j] == '*')
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};