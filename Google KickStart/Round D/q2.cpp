#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int c = 1;
    while (t--)
    {
        int k;
        cin >> k;

        vector<int> A(k);

        for (int i = 0; i < k; i++)
        {
            cin >> A[i];
        }

        int ans = 0;

        if (k == 1)
        {
            ans = 0;
            cout << "Case #" << c << ": " << ans << endl;
            c++;
            continue;
        }

        int i = 0;

        while (i < k && A[i] == A[i + 1])
        {
            i++;
        }

        int f = 0;
        int streak = 0;

        for (i = i + 1; i < k; i++)
        {
            if (f == 0)
            {
                if (A[i] > A[i - 1])
                {
                    f = 1;
                    streak = 2;
                }
                else if (A[i] < A[i - 1])
                {
                    f = 2;
                    streak = 2;
                }
            }
            else if (f == 1)
            {
                if (A[i] > A[i - 1])
                {
                    streak++;
                    if (streak > 4)
                    {
                        ans++;
                        f = 0;
                    }
                }
                else if (A[i] < A[i - 1])
                {
                    f = 2;
                    streak = 2;
                }
            }
            else
            {
                if (A[i] < A[i - 1])
                {
                    streak++;
                    if (streak > 4)
                    {
                        ans++;
                        f = 0;
                    }
                }
                else if (A[i] > A[i - 1])
                {
                    f = 1;
                    streak = 2;
                }
            }

            // cout << A[i] << " " << streak << endl;
        }

        cout << "Case #" << c << ": " << ans << endl;
        c++;
    }
}