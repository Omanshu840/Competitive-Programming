bool inRange(int i, int j, int n, int m)
{
    if (!(i >= 0 && i < n))
    {
        return false;
    }

    if (!(j >= 0 && j < m))
    {
        return false;
    }

    return true;
}

void dfs(int i, int j, vector<string> A, vector<vector<bool>> &visited, int n, int m)
{
    if (!visited[i][j])
    {
        visited[i][j] = true;

        vector<pair<int, int>> delta = {
            make_pair(1, 0),
            make_pair(0, 1),
            make_pair(-1, 0),
            make_pair(0, -1)};

        for (auto it : delta)
        {
            if (inRange(i + it.first, j + it.second, n, m))
            {

                if (A[i + it.first][j + it.second] == 'X')
                {
                    // cout<<i + it.first<<" "<<j + it.second<<endl;
                    dfs(i + it.first, j + it.second, A, visited, n, m);
                }
            }
        }
    }
}

int Solution::black(vector<string> &A)
{

    int c = 0;
    int n = A.size();
    int m = A[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int i;
    int j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (A[i][j] == 'X' && visited[i][j] == false)
            {
                c++;
                // cout<<c<<" "<<i<<" "<<j<<endl;
                dfs(i, j, A, visited, n, m);
            }
        }
    }

    return c;
}
