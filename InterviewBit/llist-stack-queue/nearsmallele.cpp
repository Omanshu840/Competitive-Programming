vector<int> Solution::prevSmaller(vector<int> &A)
{

    stack<int> s;
    stack<int> si;

    int i;
    int n = A.size();

    vector<int> ans(n);

    s.push(A[n - 1]);
    si.push(n - 1);

    for (i = n - 2; i >= 0; i--)
    {
        if (s.top() > A[i])
        {
            while (!s.empty() && s.top() > A[i])
            {
                ans[si.top()] = A[i];
                s.pop();
                si.pop();
            }

            s.push(A[i]);
            si.push(i);
        }
        else
        {
            s.push(A[i]);
            si.push(i);
        }
    }

    while (!si.empty())
    {
        ans[si.top()] = -1;
        si.pop();
    }

    return ans;
}
