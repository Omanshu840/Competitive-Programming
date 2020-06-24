#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t;
    cin >> t;

    long long c = 0;

    while (t--)
    {
        c++;
        long long n, d;
        cin >> n >> d;

        vector<long long> a(n);

        long long i;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long ans = d;

        for (i = n - 1; i >= 0; i--)
        {
            ans = (ans / a[i]) * a[i];
        }

        cout << "Case #" << c << ": " << ans << endl;
    }
}