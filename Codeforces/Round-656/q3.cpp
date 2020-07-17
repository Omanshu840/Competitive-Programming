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

        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int i = n - 1;
        int x = a[n - 1];

        while (i >= 0 && a[i] == x)
        {
            i--;
        }

        if (i < 0)
        {
            cout << "0\n";
            continue;
        }

        while (i >= 0 && a[i] >= a[i + 1])
        {
            i--;
        }

        if (i < 0)
        {
            cout << "0\n";
            continue;
        }

        while (i >= 0 && a[i] <= a[i + 1])
        {
            i--;
        }

        cout << i + 1 << endl;
    }
}