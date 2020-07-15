#include <bits/stdc++.h>

using namespace std;

int findsum(int x)
{
    int sum = 0;
    while (x != 0)
    {
        sum += x % 10;
        x = x / 10;
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x, y;
        int chef = 0, morty = 0;
        int a, b;

        for (int i = 1; i <= n; i++)
        {
            cin >> x >> y;
            a = findsum(x);
            b = findsum(y);
            if (a > b)
            {
                chef++;
            }
            else if (b > a)
            {
                morty++;
            }
            else
            {
                chef++;
                morty++;
            }
        }

        if (chef > morty)
        {
            cout << "0 " << chef << endl;
        }
        else if (morty > chef)
        {
            cout << "1 " << morty << endl;
        }
        else
        {
            cout << "2 " << chef << endl;
        }
    }
}