#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int A, int B, int C, int D)
{

    int dp[D + 1];

    int i;
    int x = 0, y = 0, z = 0;

    dp[0] = 1;

    vector<int> ans;
    int temp;

    for (i = 1; i <= D; i++)
    {
        temp = min(A * dp[x], min(B * dp[y], C * dp[z]));

        dp[i] = temp;

        if (temp == A * dp[x])
        {
            x++;
        }

        if (temp == B * dp[y])
        {
            y++;
        }

        if (temp == C * dp[z])
        {
            z++;
        }
        ans.push_back(temp);
    }
}

int main()
{
    int A, B, C, D;

    cin >> A >> B >> C >> D;

    vector<int> ans;

    ans = solve(A, B, C, D);
}