#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int> &A)
{
    int i, j;

    int n = A.size();

    i = 0;
    j = n - 1;

    int ans = 0;

    while (j > i)
    {
        ans = max(ans, min(A[i], A[j]) * (j - i));

        if (A[i] <= A[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return ans;
}

int main()
{
    int na, nb, nc, i;
    cin >> na;

    vector<int> A(na);

    for (i = 0; i < na; i++)
    {
        cin >> A[i];
    }

    int ans = maxArea(A);

    cout << ans << endl;
}