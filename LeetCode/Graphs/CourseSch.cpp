class Solution
{
public:
    bool isCyclic(vector<int> adj[], vector<bool> &visited, vector<bool> &recStack, int i)
    {
        visited[i] = true;
        recStack[i] = true;

        for (auto v : adj[i])
        {
            if (recStack[v])
                return true;

            if (!visited[v] && isCyclic(adj, visited, recStack, v))
                return true;
        }

        recStack[i] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<int> adj[numCourses];

        for (auto pre : prerequisites)
        {
            adj[pre[0]].push_back(pre[1]);
        }

        vector<bool> visited(numCourses, false);

        vector<bool> recStack(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i] && isCyclic(adj, visited, recStack, i))
                return false;
        }

        return true;
    }
};