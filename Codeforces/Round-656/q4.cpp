#include <bits/stdc++.h>

using namespace std;

int makeGood(string s, char c)
{
    int n = s.size();

    if (n == 1)
    {
        if (s[0] == c)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    string s1 = s.substr(0, n / 2);
    string s2 = s.substr(n / 2, n / 2);

    int c1 = 0;

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != c)
        {
            c1++;
        }
    }

    int c2 = 0;

    for (int i = n / 2; i < n; i++)
    {
        if (s[i] != c)
        {
            c2++;
        }
    }

    // cout << c1 << " " << s2 << " " << makeGood(s2, c + 1) << endl;

    // cout << c2 << " " << s1 << " " << makeGood(s1, c + 1) << endl;

    return min(c1 + makeGood(s2, c + 1), c2 + makeGood(s1, c + 1));
}

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

        int ans = makeGood(s, 'a');

        cout << ans << endl;
    }
}