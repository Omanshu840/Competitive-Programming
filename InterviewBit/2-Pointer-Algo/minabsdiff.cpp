#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A, vector<int> &B, vector<int> &C)
{

    int na = A.size();
    int nb = B.size();
    int nc = C.size();

    int i, j, k;
    i = 0;
    j = 0;
    k = 0;

    int ans = INT_MAX;

    while (i < na && j < nb && k < nc)
    {
        ans = min(abs(max(A[i], max(B[j], C[k])) - min(A[i], min(B[j], C[k]))), ans);

        if (A[i] <= B[j] && A[i] <= C[k])
        {

            i++;
        }
        else if (B[j] <= A[i] && B[j] <= C[k])
        {

            j++;
        }
        else
        {

            k++;
        }
    }

    return ans;
}

int main()
{
    int na, nb, nc, i;
    cin >> na >> nb >> nc;

    vector<int> A(na);
    vector<int> B(nb);
    vector<int> C(nc);

    for (i = 0; i < na; i++)
    {
        cin >> A[i];
    }

    for (i = 0; i < nb; i++)
    {
        cin >> B[i];
    }

    for (i = 0; i < nc; i++)
    {
        cin >> C[i];
    }

    int ans = solve(A, B, C);

    cout << ans << endl;
}