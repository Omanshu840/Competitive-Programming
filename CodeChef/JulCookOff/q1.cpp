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
        string s;
        cin >> s;

        vector<int> map(26, 0);

        for (auto c : s)
        {
            map[c - 'a']++;
        }

        int f = 1;

        for (int i = 0; i < 26; i++)
        {
            if (map[i] % 2 != 0)
            {
                f = 0;
                break;
            }
        }

        if (f)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}