class Solution
{
public:
    vector<pair<int, int>> delta = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}};

    bool isValid(int i, int j, int n, int m)
    {
        if (i < 0 || i >= n)
        {
            return false;
        }

        if (j < 0 || j >= m)
        {
            return false;
        }

        return true;
    }

    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        grid[i][j] = '0';

        int n = grid.size();
        int m = grid[0].size();

        for (auto del : delta)
        {
            int x = i + del.first;
            int y = j + del.second;

            if (isValid(x, y, n, m) && grid[x][y] == '1')
            {
                dfs(grid, x, y);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {

        int n = grid.size();

        if (n == 0)
            return 0;

        int m = grid[0].size();

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }

        return ans;
    }
};