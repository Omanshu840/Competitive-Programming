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

        vector<long long> a(n);

        unordered_map<long long, bool> mp;

        int f = 1;

        mp[0] = true;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        long long x = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            x = x | a[i];
            if (mp.find(x) != mp.end())
            {
                f = 0;
                break;
            }
            else
            {
                mp[x] = true;
            }
        }

        if (f)
        {
            cout << "YES\n";
        }
        else
        {
            if (n == 1)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}