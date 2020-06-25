#include <bits/stdc++.h>

using namespace std;

int findMinXor(vector<int> &A)
{

    int n = A.size();
    int i, j, x;
    int mina = INT_MAX;

    sort(A.begin(), A.end());

    for (i = 0; i < n - 1; i++)
    {
        mina = min(mina, A[i] ^ A[i + 1]);
    }

    return mina;
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

    int ans = findMinXor(A);

    cout << ans << endl;
}