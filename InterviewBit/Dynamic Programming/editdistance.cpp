#include <bits/stdc++.h>

using namespace std;

int minDistance(string A, string B)
{
    int n = A.length();
    int m = B.length();

    int dp[n + 1][m + 1];

    int i;

    for (i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }

    for (i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }

    int j = 0;

    int s = 0;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            s = (A[i - 1] == B[j - 1]) ? 0 : 1;

            dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + s));
        }
    }

    return dp[n][m];
}

int main()
{
    string A, B;
    cin >> A >> B;

    int ans;

    ans = minDistance(A, B);

    cout << ans << endl;
}