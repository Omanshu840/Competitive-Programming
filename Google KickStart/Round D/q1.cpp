#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int c = 1;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> A(n);

        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        int curMax = -1;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
            {
                if (curMax < A[i])
                {
                    ans++;
                }
            }
            else
            {
                if (curMax < A[i] && A[i] > A[i + 1])
                {
                    ans++;
                }

                curMax = max(curMax, A[i]);
            }
        }

        cout << "Case #" << c << ": " << ans << endl;
        c++;
    }
}