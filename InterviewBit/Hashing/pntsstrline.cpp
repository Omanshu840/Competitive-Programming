#include <bits/stdc++.h>

using namespace std;

int maxPoints(vector<int> &A, vector<int> &B)
{

    map<pair<double, double>, int> m;

    int n = A.size();

    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    int i, j;
    double x1, x2, y1, y2;

    double slp, c;

    pair<float, float> p;

    int max = 1;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            x1 = A[i];
            x2 = A[j];
            y1 = B[i];
            y2 = B[j];

            if (x1 == x2)
            {
                slp = INT_MAX;
                c = x1;
            }
            else
            {
                slp = (y2 - y1) / (x2 - x1);
                c = (y2 - (slp * x2));
            }

            p = make_pair(slp, c);

            if (m.find(p) == m.end())
            {
                m[p] = 2;
                if (m[p] > max)
                {
                    max = m[p];
                }
            }
            else
            {
                m[p]++;
                if (m[p] > max)
                {
                    max = m[p];
                }
            }
        }

        m.clear();
    }
    return max;
}

int main()
{
    int n, i;
    cin >> n;

    vector<int> A(n), B(n);

    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    for (i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    int ans = maxPoints(A, B);

    cout << ans << endl;
}