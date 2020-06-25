#include <bits/stdc++.h>

using namespace std;

int candy(vector<int> &A)
{
    int n = A.size();

    int i;

    int ans = 0;

    vector<int> v1(n, 1);
    vector<int> v2(n, 1);

    for (i = 1; i < n; i++)
    {
        if (A[i] > A[i - 1])
        {
            v1[i] = v1[i - 1] + 1;
        }
    }

    for (i = n - 2; i >= 0; i--)
    {
        if (A[i] > A[i + 1])
        {
            v2[i] = v2[i + 1] + 1;
        }
    }

    for (i = 0; i < n; i++)
    {
        ans += max(v1[i], v2[i]);
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

    int ans = candy(A);

    cout << ans << endl;
}