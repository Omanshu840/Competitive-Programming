#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n;

        vector<int> px;
        vector<int> py;

        for (int i = 1; i <= 4 * n - 1; i++)
        {
            cin >> x >> y;
            px.push_back(x);
            py.push_back(y);
        }

        sort(px.begin(), px.end());
        sort(py.begin(), py.end());

        int ansx = 0;
        int ansy = 0;

        for (int i = 0; i < 4 * n - 1; i++)
        {
            ansx = ansx ^ px[i];
            ansy = ansy ^ py[i];
        }

        cout << ansx << " " << ansy << endl;
    }
}