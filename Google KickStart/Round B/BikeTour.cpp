#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int c = 0;
    while (t--)
    {
        c++;
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int ans = 0;

        for (int i = 1; i < n - 1; i++)
        {
            if (a[i - 1] < a[i] && a[i + 1] < a[i])
            {
                ans++;
            }
        }

        cout << "Case #" << c << ": " << ans << endl;
    }
}