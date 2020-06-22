#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, b, m;

        cin >> n >> b >> m;

        int i;
        int x;

        int l, h;

        if (m == 0)
        {
            cout << "0\n";
        }
        else
        {

            cin >> x;

            l = x - x % b;
            h = min(x + b - x % b - 1, n - 1);

            int ans = 1;

            for (i = 1; i < m; i++)
            {
                cin >> x;
                if (x > h || x < l)
                {
                    l = x - x % b;
                    h = min(x + b - x % b - 1, n - 1);
                    ans++;
                }
            }

            cout << ans << endl;
        }
    }
}