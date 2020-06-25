#include <bits/stdc++.h>

using namespace std;

bool isPallindrome(string s)
{
    int i;
    int n = s.length();
    for (i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            return false;
        }
    }

    return true;
}

void findans(string A, vector<vector<string>> &ans, int n, vector<string> temp, int i)
{
    if (i == n)
    {
        ans.push_back(temp);
    }
    else
    {
        int j;
        string s;
        for (j = i + 1; j <= n; j++)
        {
            s = A.substr(i, j - i);
            if (!isPallindrome(s))
            {
                continue;
            }
            else
            {
                temp.push_back(s);
                findans(A, ans, n, temp, j);
                temp.pop_back();
            }
        }
    }
}

vector<vector<string>> partition(string A)
{

    vector<vector<string>> ans;

    int n = A.size();

    vector<string> temp;

    findans(A, ans, n, temp, 0);

    return ans;
}

int main()
{
    string A;

    cin >> A;

    vector<vector<string>> ans;

    ans = partition(A);
}