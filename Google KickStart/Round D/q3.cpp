#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int c = 1;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> door(n);

        for (int i = 1; i <= n - 1; i++)
        {
            cin >> door[i];
        }

        map<pair<int, int>, int> ansmap;
        priority_queue<pair<int, int>> que;
        pair<int, int> p;
        set<int> ansset;

        int k, l;

        for (int i = 1; i <= n; i++)
        {

            // cout << "I = " << i << " ";

            ansmap[{i, 1}] = i;

            while (!que.empty())
            {
                que.pop();
            }
            ansset.clear();

            ansset.insert(i);

            if (i >= 1 && i < n)
            {
                que.push({-door[i], i + 1});
                ansset.insert(i + 1);
            }

            if (i > 1)
            {
                que.push({-door[i - 1], i - 1});
                ansset.insert(i - 1);
            }

            for (int j = 2; j <= n; j++)
            {
                p = que.top();
                k = p.second;
                l = -p.first;

                ansmap[{i, j}] = k;
                // cout << k << " ";

                que.pop();

                if (k >= 1 && k < n)
                {
                    if (ansset.find(k + 1) == ansset.end())
                    {
                        que.push({-door[k], k + 1});
                        ansset.insert(k + 1);
                    }
                }

                if (k > 1)
                {
                    if (ansset.find(k - 1) == ansset.end())
                    {
                        que.push({-door[k - 1], k - 1});
                        ansset.insert(k - 1);
                    }
                }
            }
            // cout << endl;
        }

        cout << "Case #" << c << ":";

        int x, y;

        while (q--)
        {
            cin >> x >> y;
            cout << " " << ansmap[{x, y}];
        }

        cout << endl;

        c++;
    }
}