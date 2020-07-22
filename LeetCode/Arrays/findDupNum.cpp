class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        int n = nums.size();

        if (n == 0)
            return 0;

        for (int i = 0; i < n; i++)
        {
            while (nums[nums[i] - 1] != nums[i])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                ans = nums[i];
                break;
            }
        }

        return ans;
    }
};