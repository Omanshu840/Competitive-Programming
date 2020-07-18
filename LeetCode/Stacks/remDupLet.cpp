class Solution
{
public:
    string removeDuplicateLetters(string s)
    {

        stack<char> seq;

        vector<bool> inStack(26, false);
        vector<int> ocur(26, 0);

        for (auto c : s)
        {
            ocur[c - 'a']++;
        }

        for (auto c : s)
        {
            ocur[c - 'a']--;

            if (inStack[c - 'a'])
            {
                continue;
            }

            while (!seq.empty() && seq.top() > c && ocur[seq.top() - 'a'] > 0)
            {
                inStack[seq.top() - 'a'] = false;
                seq.pop();
            }

            seq.push(c);
            inStack[c - 'a'] = true;
        }

        string ans;

        while (!seq.empty())
        {
            ans.push_back(seq.top());
            seq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};