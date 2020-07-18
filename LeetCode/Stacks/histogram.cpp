class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {

        int n = heights.size();

        int x, area, r, l, ans = 0;

        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            if (s.empty() || heights[s.top()] <= heights[i])
            {
                s.push(i);
            }
            else
            {
                while (!s.empty() && heights[s.top()] > heights[i])
                {
                    x = s.top();
                    s.pop();

                    r = i - x;
                    l = (s.empty()) ? x : x - s.top() - 1;

                    area = heights[x] * (l + r);

                    ans = max(ans, area);
                }
                s.push(i);
            }
        }

        while (!s.empty())
        {
            x = s.top();
            s.pop();

            r = n - x;
            l = (s.empty()) ? x : x - s.top() - 1;

            area = heights[x] * (l + r);

            ans = max(ans, area);
        }

        return ans;
    }
};