class Solution
{
public:
    int arrangeCoins(int n)
    {

        long long x = n;

        long long i = 1;

        while (i * (i + 1) <= 2 * x)
        {
            i++;
        }

        return i - 1;
    }
};