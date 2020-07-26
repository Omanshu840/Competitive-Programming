class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        
        int n = input.size();
        
        if(n==0)
            return {0};
        
        vector<int> ans;
        
        char curr;
        
        vector<int> left, right;
        
        for(int i = 0; i<n; i++)
        {
            curr = input[i];
            
            if(curr=='*' || curr=='-' || curr=='+')
            {
                left = diffWaysToCompute(input.substr(0, i));
                right = diffWaysToCompute(input.substr(i+1, n-i-1));
                
                int temp;
                
                for(auto res_left : left)
                {
                    for(auto res_right : right)
                    {
                        switch(curr)
                        {
                            case '-' : temp = res_left-res_right;
                                break;
                            case '*' : temp = res_left*res_right;
                                break;
                            case '+' : temp = res_left+res_right;
                                break;
                        }
                        
                        ans.push_back(temp);
                    }
                }
            }
        }
        
        if(ans.size()==0)
            ans.push_back(stoi(input));
        
        return ans;
        
    }
};
