#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long sum = 3;

        int i = 2;

        while (n % sum != 0)
        {
            sum = sum + pow(2, i);
            i++;
        }

        long long x = n / sum;

        cout << x << endl;
    }
}