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

        int i;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int f;

        if (a[0] < 0)
        {
            f = 1;
        }
        else
        {
            f = 0;
        }

        i = 1;

        int max = a[0];

        long long sum = 0;

        while (i < n)
        {
            if (f)
            {
                if (a[i] < 0)
                {
                    if (a[i] > max)
                    {
                        max = a[i];
                    }
                }
                else
                {
                    sum += max;
                    max = a[i];
                    f = 0;
                }
            }
            else
            {
                if (a[i] > 0)
                {
                    if (a[i] > max)
                    {
                        max = a[i];
                    }
                }
                else
                {
                    sum += max;
                    max = a[i];
                    f = 1;
                }
            }

            i++;
        }

        sum += max;

        cout << sum << endl;
    }
}