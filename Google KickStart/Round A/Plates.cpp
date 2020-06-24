#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int c = 0;
    while (t--)
    {
        c++;
        int n, k, p, i, j, y, x;
        cin >> n >> k >> p;

        int dp[n + 1][p + 1];

        for (i = 0; i < p; i++)
        {
            dp[0][i] = 0;
        }

        for (i = 0; i <= n; i++)
        {
            dp[i][p] = 0;
        }

        int sum[n + 1][k + 1];

        for (i = 0; i <= n; i++)
        {
            sum[i][0] = 0;
        }

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= k; j++)
            {
                cin >> y;
                sum[i][j] = sum[i][j - 1] + y;
            }
        }

        for (i = 1; i <= n; i++)
        {
            for (j = 0; j <= p; j++)
            {
                dp[i][j] = 0;
                for (x = 0; x <= min(j, k); x++)
                {
                    dp[i][j] = max(dp[i][j], sum[i][x] + dp[i - 1][j - x]);
                }
            }
        }

        cout << "Case #" << c << ": " << dp[n][p] << endl;
    }
}