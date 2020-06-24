#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int c = 0;
    while (t--)
    {
        c++;
        int n, b;
        cin >> n >> b;
        int i;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a + n);

        int cost = 0;
        int x = 0;

        for (i = 0; i < n; i++)
        {
            if (cost + a[i] <= b)
            {
                cost += a[i];
                x++;
            }
            else
            {
                break;
            }
        }

        cout << "Case #" << c << ": " << x << endl;
    }
}