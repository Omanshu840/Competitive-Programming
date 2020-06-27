#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B)
{

    int n = A.size();

    vector<int> ans;

    if (n == 0)
    {
        return ans;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    priority_queue<pair<int, pair<int, int>>> max_heap;

    set<pair<int, int>> s;

    max_heap.push(make_pair(A[n - 1] + B[n - 1], make_pair(n - 1, n - 1)));

    s.insert(make_pair(n - 1, n - 1));

    int c = n;

    int i, j;

    int sum;

    while (n--)
    {
        pair<int, pair<int, int>> temp = max_heap.top();
        max_heap.pop();
        ans.push_back(temp.first);

        i = temp.second.first;
        j = temp.second.second;

        sum = A[i - 1] + B[j];

        pair<int, int> temp1 = make_pair(i - 1, j);

        if (s.find(temp1) == s.end())
        {
            max_heap.push(make_pair(sum, temp1));
            s.insert(temp1);
        }

        sum = A[i] + B[j - 1];

        temp1 = make_pair(i, j - 1);

        if (s.find(temp1) == s.end())
        {
            max_heap.push(make_pair(sum, temp1));
            s.insert(temp1);
        }
    }

    return ans;
}

int main()
{
    int n, i;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);

    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    for (i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    vector<int> ans;

    ans = solve(A, B);
}