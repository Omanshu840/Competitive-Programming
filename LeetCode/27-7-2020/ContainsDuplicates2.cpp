class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<pair<int, int>> a;
    
        for(int i = 0; i<n; i++)
        {
            a.push_back({nums[i], i});
        }
        
        sort(a.begin(), a.end());
        
        for(int i = 1; i<n; i++)
        {
            if(a[i].first==a[i-1].first && a[i].second-a[i-1].second<=k)
                return true;
                
        }
        
        return false;
        
    }
};