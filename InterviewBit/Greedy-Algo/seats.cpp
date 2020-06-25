#include <bits/stdc++.h>

using namespace std;

int seats(string A)
{

    long long n = A.length();
    vector<long long> v;

    long long i;

    for (i = 0; i < n; i++)
    {
        if (A[i] == 'x')
        {
            v.push_back(i);
        }
    }

    long long m = v.size();

    long long j = m / 2;

    long long ans = 0;

    long long mod = 10000003;

    for (i = 0; i < m; i++)
    {
        ans += (abs(v[i] - v[j]) - abs(i - j)) % mod;
    }

    return ans % mod;
}

int main()
{
    string A;

    cin >> A;

    int ans;

    ans = seats(A);
}