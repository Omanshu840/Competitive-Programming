class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {

        int n = nums.size();

        if (n == 0)
        {
            return {};
        }

        int maxe = INT_MIN;

        int maxi;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > maxe)
            {
                maxe = nums[i];
                maxi = i;
            }
        }

        vector<int> ans(n, -1);

        stack<int> s;
        s.push(nums[maxi]);

        int i = maxi - 1;

        if (i < 0)
        {
            i = n - 1;
        }

        while (i != maxi)
        {

            cout << i << " " << s.top() << " " << nums[i] << endl;

            while (!s.empty() && s.top() <= nums[i])
            {
                s.pop();
            }

            if (!s.empty())
            {
                ans[i] = s.top();
            }

            s.push(nums[i]);

            i--;

            if (i < 0)
            {
                i = n - 1;
            }
        }

        return ans;
    }
};