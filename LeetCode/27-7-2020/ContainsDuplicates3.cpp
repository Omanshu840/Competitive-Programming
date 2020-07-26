class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        int n = nums.size();
        
        vector<pair<long long, int>> a;
        
        for(int i = 0; i<n; i++)
        {
            a.push_back({nums[i], i});
        }
        
        sort(a.begin(), a.end());
        
        for(int i = 0; i<n; i++)
        {
            int j = i+1;
            while(j<n && a[j].first-a[i].first<=t)
            {
                if(abs(a[j].second-a[i].second)<=k)
                    return true;
                
                j++;
            }
        }
        
        return false;
        
    }
};