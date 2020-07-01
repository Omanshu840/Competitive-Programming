class Solution
{
public:
    bool isPathCrossing(string path)
    {

        int x = 0;
        int y = 0;

        map<pair<int, int>, bool> mp;

        mp[make_pair(0, 0)] = true;

        int n = path.length();
        int i;

        for (i = 0; i < n; i++)
        {
            if (path[i] == 'N')
            {
                y++;
            }
            else if (path[i] == 'S')
            {
                y--;
            }
            else if (path[i] == 'E')
            {
                x++;
            }
            else
            {
                x--;
            }

            if (mp.find(make_pair(x, y)) != mp.end())
            {
                return true;
            }
            else
            {
                mp[make_pair(x, y)] = true;
            }
        }

        return false;
    }
};