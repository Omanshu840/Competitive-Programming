#include <bits/stdc++.h>

using namespace std;

int nchoc(int A, vector<int> &B)
{

    priority_queue<long long> max_heap;

    int n = B.size();

    int i = 0;

    for (i = 0; i < n; i++)
    {
        max_heap.push(B[i]);
    }

    long long sum = 0;
    long long m = 1000000007;

    long long x;

    while (A--)
    {
        x = max_heap.top();
        max_heap.pop();

        sum = (sum + x % m) % m;

        max_heap.push(x / 2);
    }

    return sum;
}

int main()
{
    int n, i;
    cin >> n;
    vector<int> B(n);
    int A;

    cin >> A;

    for (i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    
    int ans = nchoc(A, B);

    cout << ans;
}