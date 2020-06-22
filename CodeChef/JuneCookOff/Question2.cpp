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

        vector<int> a(n);

        int i;
        int cm = 0;

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == m)
            {
                cm++;
            }
        }

        sort(a.begin(), a.end());

        int mem;

        int c = 1;

        for (i = 0; i < n; i++)
        {
            if (a[i] == c)
            {
                c++;
            }
            else if (a[i] <= c)
            {
                continue;
            }
            else
            {
                break;
            }
        }

        mem = c;

        if (mem < m)
        {
            cout << "-1\n";
        }
        else if (mem == m)
        {
            cout << n << endl;
        }
        else
        {
            cout << n - cm << endl;
        }
    }
}