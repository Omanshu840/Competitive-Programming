#include <bits/stdc++.h>

using namespace std;

void findans(int A, vector<vector<string>> &ans, vector<bool> col, vector<bool> diag1, vector<bool> diag2, vector<int> temp, int i)
{
    if (i == A)
    {
        int j;
        vector<string> s(A);
        for (j = 0; j < A; j++)
        {
            s[i] += ".";
        }
        for (j = 0; j < A; j++)
        {
            s[j][temp[j]] = 'Q';
        }

        ans.push_back(s);
    }
    else
    {
        int j;
        for (j = 0; j < A; j++)
        {
            if (col[j] || diag1[j + i] || diag2[A - 1 + j - i])
            {
                continue;
            }
            else
            {
                col[j] = 1;
                diag1[j + i] = 1;
                diag2[A - 1 + j - i] = 1;

                temp.push_back(j);

                findans(A, ans, col, diag1, diag2, temp, i + 1);

                temp.pop_back();

                col[j] = 0;
                diag1[j + i] = 0;
                diag2[A - 1 + j - i] = 0;
            }
        }
    }
}

vector<vector<string>> solveNQueens(int A)
{

    vector<vector<string>> ans;

    if (A == 2 || A == 3)
    {
        return ans;
    }

    if (A == 1)
    {
        vector<string> s;
        s.push_back("Q");
        ans.push_back(s);

        return ans;
    }

    vector<bool> col(A, false);
    vector<bool> diag1(A, false);
    vector<bool> diag2(A, false);

    vector<int> temp;

    findans(A, ans, col, diag1, diag2, temp, 0);

    return ans;
}

int main()
{
    int A;

    cin >> A;

    vector<vector<string>> ans;

    ans = solveNQueens(A);
}