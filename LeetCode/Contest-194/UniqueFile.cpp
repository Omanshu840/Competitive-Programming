class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {

        int i;
        int n = arr.size();

        map<int, int> mp;

        int x;

        for (i = 0; i < k; i++)
        {
            mp[i] = 0;
        }

        for (i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                x = k + arr[i] % k;
            }
            else
            {
                x = arr[i] % k;
            }

            // cout<<arr[i]<<" "<<x<<endl;

            mp[x]++;
        }

        if (k % 2 == 0)
        {
            if (mp[k / 2] % 2 != 0)
            {
                return false;
            }
        }

        for (i = 1; i < k / 2; i++)
        {

            // cout<<mp[i]<<" "<<mp[k-i]<<endl;

            if (mp[i] != mp[k - i])
            {
                return false;
            }
        }

        return true;
    }
};