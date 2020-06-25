#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int A, vector<int> &B)
{

    int n = B.size();

    int i;

    vector<int> ans;

    int j = 0;

    int min = INT_MAX;

    for (i = 0; i < n; i++)
    {
        if (B[i] < min)
        {
            j = i;
            min = B[i];
        }
    }

    int pos = B[j] + (A % B[j]);

    for (i = 0; i < j; i++)
    {
        if (A >= B[i] && pos >= B[i])
        {
            A -= B[i];
            ans.push_back(i);
            pos = pos + B[j] - B[i];
            i--;
        }
    }

    while (A >= B[j])
    {
        ans.push_back(j);
        A -= B[j];
    }

    return ans;
}

int main()
{
    int A, i, x;
    vector<int> B;

    cin >> A;

    for (i = 0; i < n; i++)
    {
        cin >> x;
        B.push_back(x);
    }

    vector<int> ans;

    ans = solve(A, B);
}