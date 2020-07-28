class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==0)
            return 0;
        
        int i = 0;
        int j = 0;
        
        int ans = INT_MAX;
        int cursum = 0;
        
        while(j<n)
        {   
            cursum += nums[j];
            
            if(cursum>=s)
            {
                while(i<n && cursum>=s)
                {
                    ans = min(ans, j-i+1);
                    cursum-=nums[i];
                    i++;
                }
            }
            
            j++;
        }
        
        if(ans==INT_MAX)
            return 0;
        
        return ans;
        
    }
};