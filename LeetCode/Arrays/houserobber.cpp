class Solution {
public:
    int robHelper(vector<int> nums, int l, int h)
    {
        int prev = 0;
        int curr = 0;
        
        int ans = 0;
        
        for(int i = l; i<=h; i++)
        {
            curr = max(prev+nums[i], curr);
            prev = ans;
            ans = curr;
        }
        
        return ans;
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==0)
            return 0;
        
        if(n==1)
            return nums[0];
        
        if(n==2)
            return max(nums[0], nums[1]);
        
        return max(robHelper(nums, 0, n-2), robHelper(nums, 1, n-1));
        
    }
};