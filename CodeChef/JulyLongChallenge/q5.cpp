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

        vector<int> A(n);
        vector<int> B(n);

        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> B[i];
        }

        vector<int> MisA;
        vector<int> MisB;
        int lowCommon = INT_MAX;
        vector<int> Mising;

        int i = 0;
        int j = 0;

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int f = 1;

        while (i < n && j < n)
        {
            if (A[i] == B[j])
            {
                lowCommon = min(lowCommon, A[i]);
                i++;
                j++;
                continue;
            }

            if (A[i] < B[j])
            {
                if (i + 1 < n && A[i + 1] == A[i])
                {
                    MisB.push_back(A[i]);
                    Mising.push_back(A[i]);
                    i += 2;
                }
                else
                {
                    f = 0;
                    break;
                }
            }
            else
            {
                if (j + 1 < n && B[j + 1] == B[j])
                {
                    MisA.push_back(B[j]);
                    Mising.push_back(B[j]);
                    j += 2;
                }
                else
                {
                    f = 0;
                    break;
                }
            }
        }

        if (f == 0)
        {
            cout << "-1\n";
            continue;
        }

        while (i < n)
        {
            if (i + 1 < n && A[i + 1] == A[i])
            {
                Mising.push_back(A[i]);
                MisB.push_back(A[i]);
                i += 2;
            }
            else
            {
                f = 0;
                break;
            }
        }

        while (j < n)
        {
            if (j + 1 < n && B[j + 1] == B[j])
            {
                Mising.push_back(B[j]);
                MisA.push_back(B[j]);
                j += 2;
            }
            else
            {
                f = 0;
            }
        }

        if (f == 0)
        {
            cout << "-1\n";
            continue;
        }

        if (MisA.size() != MisB.size())
        {
            cout << "-1\n";
            continue;
        }

        if (MisA.size() == 0)
        {
            cout << "0\n";
            continue;
        }

        int swap = min(lowCommon, Mising[0]);
        // cout << swap << endl;
        long long ans = 0;
        int m = Mising.size() / 2;

        i = 0;

        while (i < m && swap * 2 > Mising[i])
        {
            ans += Mising[i];
            i++;
        }

        while (i < m)
        {
            ans += 2 * swap;
            i++;
        }

        cout << ans << endl;
    }
}