class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {

        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        if (matrix[0][0] == '1')
            dp[0][0] = 1;

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    if (i && j)
                    {
                        dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                    }
                    else
                    {
                        dp[i][j] = 1;
                    }
                }

                // cout<<dp[i][j]<<" ";

                ans = max(ans, dp[i][j]);
            }
            // cout<<endl;
        }

        return ans * ans;
    }
};