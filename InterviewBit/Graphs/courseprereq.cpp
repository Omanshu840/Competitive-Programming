bool cycle(vector<int> graph[], vector<bool> visited, vector<bool> recStack, int i)
{
    if (!visited[i])
    {
        visited[i] = true;
        recStack[i] = true;

        int j;

        for (j = 0; j < graph[i].size(); j++)
        {
            if (cycle(graph, visited, recStack, graph[i][j]))
            {
                return true;
            }

            if (recStack[graph[i][j]])
            {
                return true;
            }
        }
    }
    recStack[i] = false;
    return false;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C)
{

    vector<int> graph[A + 1];

    int n = B.size();

    int i;

    for (i = 0; i < n; i++)
    {
        graph[B[i]].push_back(C[i]);
    }

    vector<bool> visited(A + 1, false);
    vector<bool> recStack(A + 1, false);

    for (i = 1; i <= A; i++)
    {
        if (cycle(graph, visited, recStack, i))
        {
            return 0;
        }
    }

    return 1;
}
