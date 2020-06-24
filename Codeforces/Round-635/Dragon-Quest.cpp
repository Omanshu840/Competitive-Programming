#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, n, m;
        cin >> x >> n >> m;

        while (x > 20 && n > 0)
        {
            n--;
            x = (x / 2) + 10;
        }

        while (m > 0)
        {
            m--;
            x = x - 10;
        }

        if (x <= 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}