class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 0)
            return 0;

        int dp[n];

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (i > 2)
                dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]);

            else if (i == 2)
                dp[i] = nums[i] + dp[i - 2];

            else
                dp[i] = nums[i];

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};