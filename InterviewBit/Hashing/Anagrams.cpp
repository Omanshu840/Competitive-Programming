#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> anagrams(const vector<string> &A)
{

    int n = A.size();

    int i;

    vector<string> B = A;

    for (i = 0; i < n; i++)
    {
        sort(B[i].begin(), B[i].end());
    }

    vector<bool> fin(n, false);

    vector<vector<int>> ans;

    vector<int> temp;

    int j;

    for (i = 0; i < n; i++)
    {
        if (fin[i] == false)
        {
            temp.clear();
            fin[i] = true;
            for (j = 0; j < n; j++)
            {
                if (B[i] == B[j])
                {
                    temp.push_back(j + 1);
                    fin[j] = true;
                }
            }

            ans.push_back(temp);
        }
    }

    return ans;
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

    vector<vector<int>> ans;

    ans = anagrams(A);
}