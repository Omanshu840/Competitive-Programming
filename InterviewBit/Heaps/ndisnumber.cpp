#include <bits/stdc++.h>

using namespace std;

vector<int> dNums(vector<int> &A, int B)
{

    int i;
    int n = A.size();

    map<int, int> m;

    for (i = 0; i < n && i < B; i++)
    {
        if (m.find(A[i]) == m.end())
        {
            m[A[i]] = 1;
        }
        else
        {
            m[A[i]]++;
        }
    }

    vector<int> ans;
    ans.push_back(m.size());

    i = 0;
    int j = B;
    while (j < n)
    {
        if (m[A[i]] == 1)
        {
            m.erase(A[i]);
        }
        else
        {
            m[A[i]]--;
        }

        if (m.find(A[j]) == m.end())
        {
            m[A[j]] = 1;
        }
        else
        {
            m[A[j]]++;
        }

        ans.push_back(m.size());

        j++;
        i++;
    }

    return ans;
}

int main()
{
    int n, i;
    cin >> n;
    vector<int> A(n);
    int B;

    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cin >> B;

    vector<int> ans;

    ans = dNums(A, B);
}