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

        vector<int> a(2 * n);
        vector<pair<int, int>> p;

        unordered_map<int, bool> map;

        for (int i = 0; i < 2 * n; i++)
        {
            cin >> a[i];
            if (map.find(a[i]) == map.end())
            {
                map[a[i]] = true;
                p.push_back({i, a[i]});
            }
        }

        sort(p.begin(), p.end());

        for (auto pr : p)
        {
            cout << pr.second << " ";
        }

        cout << endl;
    }
}