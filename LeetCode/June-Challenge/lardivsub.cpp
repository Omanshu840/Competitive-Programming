class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        if (n == 0 || n == 1)
        {
            return nums;
        }

        vector<int> dp(n, 1);
        vector<int> prev(n, -1);

        int i, j, k;
        int temp;

        for (i = 0; i < n; i++)
        {
            temp = INT_MIN;
            k = -1;
            for (j = i - 1; j >= 0; j--)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if (1 + dp[j] > temp)
                    {
                        temp = 1 + dp[j];
                        k = j;
                    }
                }
            }
            if (k != -1)
            {
                dp[i] = temp;
                prev[i] = k;
            }
            // cout<<dp[i]<<" "<<prev[i]<<endl;
        }

        temp = INT_MIN;

        for (i = 0; i < n; i++)
        {
            if (temp < dp[i])
            {
                temp = dp[i];
                j = i;
            }
        }

        vector<int> ans;

        i = j;

        while (i != -1)
        {
            ans.push_back(nums[i]);
            i = prev[i];
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};