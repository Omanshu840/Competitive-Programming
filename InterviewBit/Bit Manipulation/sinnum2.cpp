#include <bits/stdc++.h>

using namespace std;

int singleNumber(const vector<int> &A)
{

    int i, j;
    int cnt = 0;
    int n = A.size();

    int ans = 0;

    for (i = 0; i < 32; i++)
    {
        cnt = 0;
        for (j = 0; j < n; j++)
        {
            if ((A[j] >> i) & 1)
                cnt++;
        }
        if (cnt % 3 != 0)
        {
            ans += pow(2, i);
        }
    }

    return ans;
}

int main()
{
    int n, i;
    cin >> n;

    vector<int> A(n);

    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int ans = singleNumber(A);

    cout << ans << endl;
}