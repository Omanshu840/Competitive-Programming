#include <bits/stdc++.h>

using namespace std;

int lis(const vector<int> &A)
{
    int n = A.size();

    vector<int> dp(n);

    dp[0] = 1;

    int i;

    int j;

    int ans = 1;

    for (i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (j = 0; j < i; j++)
        {

            if (A[j] < A[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        ans = max(ans, dp[i]);
    }

    return ans;
}

int main()
{
    int n, i;
    cin >> n;

    vector<int> A(n);

    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int ans = lis(A);

    cout << ans << endl;
}