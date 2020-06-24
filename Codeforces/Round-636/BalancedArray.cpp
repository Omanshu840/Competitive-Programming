#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if ((n / 2) % 2 != 0)
        {
            cout << "NO\n";
        }
        else
        {
            long long i;
            long long x = (n / 2);
            cout << "YES\n";
            for (i = 1; i <= x; i++)
            {
                cout << 2 * i << " ";
            }

            for (i = 1; i < x; i++)
            {
                cout << 2 * i - 1 << " ";
            }

            cout << 3 * x - 1 << endl;
        }
    }
}