vector<int> Solution::slidingMaximum(const vector<int> &A, int B)
{

    deque<int> q1;
    deque<int> q2;

    int n = A.size();

    int i;

    vector<int> ans;

    for (i = 0; i < B; i++)
    {
        if ((!q1.empty()) && A[i] > q1.back())
        {
            while ((!q1.empty()) && A[i] > q1.back())
            {
                q1.pop_back();
                q2.pop_back();
            }

            q1.push_back(A[i]);
            q2.push_back(i);
        }
        else
        {
            q1.push_back(A[i]);
            q2.push_back(i);
        }

        if (i == n - 1)
        {
            ans.push_back(q1.front());
            return ans;
        }
    }

    ans.push_back(q1.front());

    for (i = B; i < n; i++)
    {
        if (i - q2.front() >= B)
        {
            q1.pop_front();
            q2.pop_front();
        }

        if ((!q1.empty()) && A[i] > q1.back())
        {
            while ((!q1.empty()) && A[i] > q1.back())
            {
                q1.pop_back();
                q2.pop_back();
            }

            q1.push_back(A[i]);
            q2.push_back(i);
        }
        else
        {
            q1.push_back(A[i]);
            q2.push_back(i);
        }

        ans.push_back(q1.front());
    }

    return ans;
}
