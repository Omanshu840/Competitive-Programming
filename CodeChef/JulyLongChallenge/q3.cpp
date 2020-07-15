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

        vector<vector<char>> ans(8, vector<char>(8, 'X'));

        ans[0][0] = 'O';

        int count = 0;

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                count++;

                if (i == 0 && j == 0)
                {
                    cout << ans[i][j];
                    continue;
                }

                if (count <= n)
                {
                    ans[i][j] = '.';
                }

                cout << ans[i][j];
            }
            cout << endl;
        }
    }
}