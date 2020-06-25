#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> subsets(vector<int> &A)
{

    vector<vector<int>> ans;

    int n = A.size();

    sort(A.begin(), A.end());

    int i, j;

    vector<int> x;

    for (i = 0; i < (1 << n); i++)
    {
        x.clear();

        for (j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {

                x.push_back(A[j]);
            }
        }

        ans.push_back(x);
    }

    sort(ans.begin(), ans.end());

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

    vector<vector<int>> ans;
    ans = subsets(A);
}