#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int d, m, i;
        cin >> d >> m;

        long long ans = 1;

        ans = 1;

        for (i = 0; pow(2, i + 1) <= d; i++)
        {
            ans = (ans * (((long long)(pow(2, i + 1)) - (long long)(pow(2, i)) + 1) % m)) % m;
        }

        ans = (ans * ((d + 1 - (long long)pow(2, i) + 1) % m)) % m;

        ans--;

        if (ans < 0)
        {
            ans += m;
        }

        cout << ans << endl;
    }
}