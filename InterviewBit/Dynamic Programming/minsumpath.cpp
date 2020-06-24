#include <bits/stdc++.h>

using namespace std;

int minPathSum(vector<vector<int>> &A)
{

    int n = A.size();

    int m = A[0].size();

    int dp[n][m];

    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = A[i][j];
            }
            else if (i == 0)
            {
                dp[i][j] = A[i][j] + dp[i][j - 1];
            }
            else if (j == 0)
            {
                dp[i][j] = A[i][j] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = A[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n - 1][m - 1];
}

int main()
{
    int n, m, i, j;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int>(m));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }

    int ans = minPathSum(A);

    cout << ans << endl;
}