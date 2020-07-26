class Solution {
public:
    int nthUglyNumber(int n) {
        
        int c2 = 1;
        int c3 = 1;
        int c5 = 1;
        
        int ans[n+1];
        int temp;
        ans[1] = 1;
        
        for(int i = 2; i<=n; i++)
        {
            temp = min(ans[c2]*2, min(ans[c3]*3, ans[c5]*5));
            
            if(temp==ans[c2]*2)
                c2++;
            if(temp==ans[c3]*3)
                c3++;
            if(temp==ans[c5]*5)
                c5++;
            
            ans[i] = temp;
        }
        
        return ans[n];
        
    }
};
