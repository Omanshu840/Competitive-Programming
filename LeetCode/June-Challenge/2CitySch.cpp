class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {

        vector<pair<int, int>> listA;
        vector<pair<int, int>> listB;

        int n = costs.size();

        int i;

        for (i = 0; i < n; i++)
        {
            if (costs[i][0] <= costs[i][1])
            {
                listA.push_back({costs[i][1] - costs[i][0], i});
            }
            else
            {
                listB.push_back({costs[i][0] - costs[i][1], i});
            }
        }

        if (listA.size() < listB.size())
        {
            sort(listB.begin(), listB.end());

            while (listA.size() != listB.size())
            {
                listA.push_back(*listB.begin());
                listB.erase(listB.begin());
            }
        }
        else
        {
            sort(listA.begin(), listA.end());

            while (listA.size() != listB.size())
            {
                listB.push_back(*listA.begin());
                listA.erase(listA.begin());
            }
        }

        int ans = 0;

        for (auto it : listA)
        {
            ans += costs[it.second][0];
        }

        for (auto it : listB)
        {
            ans += costs[it.second][1];
        }

        return ans;
    }
};