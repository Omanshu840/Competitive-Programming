class Solution {
public:
    bool isValid(int i, int j, int n, int m)
    {
        if(i<0 || i>=n)
            return false;
        
        if(j<0 || j>=m)
            return false;
        
        return true;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<pair<int, int>> delta = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1},
            {1, 1},
            {-1, -1},
            {1, -1},
            {-1, 1}
        };
        
        int n = board.size();
        
        if(n==0)
            return;
        
        int m = board[0].size();
        
        vector<pair<int, int>> toggle;
        
        int x,y;
        int c1;
        
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                c1 = 0;
                
                for(auto del : delta)
                {
                    x = i + del.first;
                    y = j + del.second;
                    
                    if(isValid(x, y, n, m))
                    {
                        if(board[x][y]==1)
                            c1++;
                    }
                }
                
                if(board[i][j]==1)
                {
                    if(c1<2 || c1>3)
                        toggle.push_back({i, j});
                }
                else
                {
                    if(c1==3)
                        toggle.push_back({i, j});
                }
            }
        }
        
        for(auto tog : toggle)
        {
            board[tog.first][tog.second] = board[tog.first][tog.second]^1;
        }
        
        
    }
};
