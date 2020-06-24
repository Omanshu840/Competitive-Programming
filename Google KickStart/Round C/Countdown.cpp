#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int c = 0;
    while (t--)
    {
        c++;
        int n, k, i, j;
        cin >> n >> k;

        vector<int> a(n);

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int ans = 0;

        int f = 0;

        for (i = 0; i < n; i++)
        {
            if (f)
            {
                if (a[i] == k - f)
                {
                    f++;
                    if (a[i] == 1)
                    {
                        ans++;
                        f = 0;
                    }
                }
                else
                {
                    f = 0;
                }
            }

            if (a[i] == k)
            {
                f = 1;
            }
        }

        cout << "Case #" << c << ": " << ans << endl;
    }
}