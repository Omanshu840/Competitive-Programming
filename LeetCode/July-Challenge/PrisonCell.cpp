class Solution
{
public:
    string toString(vector<int> A)
    {
        string s;

        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == 0)
            {
                s.push_back('0');
            }
            else
            {
                s.push_back('1');
            }
        }

        return s;
    }

    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {

        map<string, int> mp;

        for (int i = 1; i <= N; i++)
        {
            string s = toString(cells);

            // cout<<s<<endl;

            if (mp.find(s) != mp.end())
            {
                int cycleLength = i - mp[s];
                int n = (N - i) % cycleLength;

                // cout<<cycleLength<<" "<<n<<endl;

                return prisonAfterNDays(cells, n + 1);
            }
            else
            {
                mp[s] = i;
                vector<int> temp(8);
                temp[0] = 0;
                temp[7] = 0;

                for (int j = 1; j < 7; j++)
                {
                    temp[j] = cells[j - 1] == cells[j + 1];
                }

                cells = temp;
            }
        }

        return cells;
    }
};