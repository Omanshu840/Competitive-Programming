#include <bits/stdc++.h>

using namespace std;

void findans(string A, vector<string> &ans, string temp, map<char, string> m, int i)
{
    if (i == A.length())
    {
        ans.push_back(temp);
    }
    else
    {
        int j;
        for (int j = 0; j < m[A[i]].length(); j++)
        {
            temp.push_back(m[A[i]][j]);
            findans(A, ans, temp, m, i + 1);
            temp.pop_back();
        }
    }
}

vector<string> letterCombinations(string A)
{

    map<char, string> m;
    m.insert({'0', "0"});
    m.insert({'1', "1"});
    m.insert({'2', "abc"});
    m.insert({'3', "def"});
    m.insert({'4', "ghi"});
    m.insert({'5', "jkl"});
    m.insert({'6', "mno"});
    m.insert({'7', "pqrs"});
    m.insert({'8', "tuv"});
    m.insert({'9', "wxyz"});

    vector<string> ans;

    string temp;

    findans(A, ans, temp, m, 0);

    return ans;
}

int main()
{
    string A;

    cin >> A;

    vector<string> ans;

    ans = letterCombinations(A);
}