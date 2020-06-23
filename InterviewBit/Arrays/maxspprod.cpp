#include <bits/stdc++.h>

using namespace std;

int Solution(vector<int> A)
{

    int n = A.size();
    int i;

    int m = 1000000007;

    map<int, int> mp;

    for (i = 0; i < n; i++)
    {
        if (mp.find(A[i]) == mp.end())
        {
            mp[A[i]] = 1;
        }
        else
        {
            mp[A[i]]++;
        }
    }

    int j;
    int lsv;
    int rsv;
    int k;

    int ans = INT_MIN;

    for (i = 0; i < n; i++)
    {
        k = -1;
        lsv = 0;
        rsv = 0;
        for (j = 0; j < i; j++)
        {
            if (mp[A[j]] >= 2)
            {
                k = j;
            }
        }
        if (k != -1)
        {
            lsv = j;
        }

        k = -1;

        for (j = i + 1; j < n; j++)
        {
            if (mp[A[j]] >= 2)
            {
                k = j;
            }
        }
        if (k != -1)
        {
            rsv = j;
        }

        ans = max(ans, ((lsv % m) * (rsv % m)) % m);
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

    int ans = Solution(A);

    cout << ans << endl;
}