class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i, j;
        int ans = 0;
        int m = 1000000007;

        int pow2[n];

        pow2[0] = 1;

        for (i = 1; i < n; i++)
        {
            pow2[i] = (2 * pow2[i - 1] % m) % m;
        }

        i = 0;

        for (j = i + 1; j < n && nums[i] + nums[j] <= target; j++)
        {
            continue;
        };

        j--;

        while (i < n && nums[i] * 2 <= target)
        {
            while (j > i && nums[i] + nums[j] > target)
            {
                j--;
            }

            ans = (ans % m + pow2[j - i] % m) % m;
            i++;
        }

        return ans;
    }
};