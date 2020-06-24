#include <bits/stdc++.h>

using namespace std;

int climbStairs(int A)
{

    int dp[A + 1];

    int i = 1;

    dp[1] = 1;
    dp[0] = 1;

    for (i = 2; i <= A; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[A];
}

int main()
{
    int A;

    cin >> A;

    int ans = climbStairs(A);

    cout << ans << endl;
}