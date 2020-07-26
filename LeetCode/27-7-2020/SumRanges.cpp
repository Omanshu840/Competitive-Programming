class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> ans;
        
        int n = nums.size();
        
        if(n==0)
            return ans;
        
        string x = to_string(nums[0]);
        
        int f = 0;
        
        long long a, b;
        
        for(int i = 1; i<n; i++)
        {
            a = nums[i];
            b = nums[i-1];
            
            if(a-b==1)
            {
                f = 1;   
            }
            else
            {
                if(f)
                {
                    x = x + "->" + to_string(nums[i-1]);
                }
                 
                ans.push_back(x);
                x = to_string(nums[i]);
                f = 0;
            }
        }
        
        if(f)
        {
            x = x + "->" + to_string(nums[n-1]);
        }
        ans.push_back(x);
        
        return ans;
        
    }
};
