#include <bits/stdc++.h>

using namespace std;

void findpermu(vector<vector<int>> &ans, vector<int> temp, vector<bool> chosen, int n, vector<int> A)
{
    if (temp.size() == n)
    {
        ans.push_back(temp);
    }
    else
    {
        int i;
        for (i = 0; i < n; i++)
        {
            if (chosen[i] == false)
            {
                chosen[i] = true;
                temp.push_back(A[i]);
                findpermu(ans, temp, chosen, n, A);
                chosen[i] = false;
                temp.pop_back();
            }
        }
    }
}

vector<vector<int>> permute(vector<int> &A)
{

    vector<vector<int>> ans;

    int n = A.size();

    vector<int> temp;

    vector<bool> chosen(n, false);

    findpermu(ans, temp, chosen, n, A);

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
    ans = permute(A);
}