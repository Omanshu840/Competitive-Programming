class Solution {
public:
    vector<int> grayCode(int n){
        
        if(n==0)
            return {0};
        
        
        vector<int> list = grayCode(n-1);
        
        int x = list.size();
        
        for(int i = x-1; i>=0; i--)
        {
            list.push_back(pow(2, n-1)+list[i]);
        }
        
        return list;
        
    }
};