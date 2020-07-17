#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];

        sort(a, a + 3);

        if (a[0] == a[1] && a[1] == a[2])
        {
            cout << "YES\n";
            cout << a[0] << " " << a[1] << " " << a[2] << endl;
        }
        else if (a[0] == a[1])
        {
            cout << "NO\n";
        }
        else if (a[1] == a[2])
        {
            cout << "YES\n";
            cout << a[0] << " " << a[0] << " " << a[1] << endl;
        }
        else
        {
            cout << "NO\n";
        }
    }
}