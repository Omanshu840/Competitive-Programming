#include <bits/stdc++.h>
#include <string>

using namespace std;

int Solution(vector<string> A)
{
    int n = A.size();

    int i;

    double a, b, c;

    a = stod(A[0]);
    b = stod(A[1]);
    c = stod(A[2]);

    double mine;

    for (i = 3; i < n; i++)
    {
        if ((a + b + c) > 1 && (a + b + c) < 2)
        {
            return 1;
        }
        else if ((a + b + c) <= 1)
        {

            if (a <= b && a <= c)
            {
                if (a < stod(A[i]))
                {
                    a = stod(A[i]);
                }
            }
            else if (b <= a && b <= c)
            {
                if (b < stod(A[i]))
                {
                    b = stod(A[i]);
                }
            }
            else
            {
                if (c < stod(A[i]))
                {
                    c = stod(A[i]);
                }
            }
        }
        else
        {

            if (a >= b && a >= c)
            {
                if (a > stod(A[i]))
                {
                    a = stod(A[i]);
                }
            }
            else if (b >= a && b >= c)
            {
                if (b > stod(A[i]))
                {
                    b = stod(A[i]);
                }
            }
            else
            {
                if (c > stod(A[i]))
                {
                    c = stod(A[i]);
                }
            }
        }
    }

    if ((a + b + c) > 1 && (a + b + c) < 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n, i;

    cin >> n;

    vector<string> A(n);

    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int ans = Solution(A);

    cout << ans << endl;
}