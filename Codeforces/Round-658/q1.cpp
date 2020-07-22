#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);

        unordered_map<int, bool> map;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            map[a[i]] = true;
        }

        int f = 0;
        int ans;

        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
            if (map.find(b[i]) != map.end())
            {
                ans = b[i];
                f = 1;
            }
        }

        if (f)
        {
            cout << "YES\n";
            cout << "1 " << ans << endl;
        }
        else
        {
            cout << "NO\n";
        }
    }
}