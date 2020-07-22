class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int n = nums.size();

        if (n == 0)
            return {};

        vector<int> ans(n);

        ans[0] = 1;

        for (int i = 1; i < n; i++)
        {
            ans[i] = nums[i - 1] * ans[i - 1];
        }

        int pro = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] = pro * ans[i];
            pro = pro * nums[i];
        }

        return ans;
    }
};