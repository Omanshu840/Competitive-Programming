#include <bits/stdc++.h>

using namespace std;

bool posible(int mid, vector<int> &A, int B)
{
    int numstud = 0;
    int i;
    int n = A.size();
    int sum = 0;
    int cursum = mid;

    for (i = 0; i < n; i++)
    {
        if (A[i] > mid)
        {
            return false;
        }

        if (A[i] + cursum > mid)
        {
            numstud++;
            cursum = A[i];
        }
        else
        {
            cursum = A[i] + cursum;
        }

        if (numstud > B)
        {
            return false;
        }
    }

    return true;
}

int books(vector<int> &A, int B)
{

    int n = A.size();
    int i;

    int high = 0;
    int low = 0;
    int mid;

    if (B > n)
    {
        return -1;
    }

    for (i = 0; i < n; i++)
    {
        high += A[i];
    }

    int ans = INT_MAX;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        // cout << mid << " "<< high << " " << low << " "<< posible(mid, A, B)<< " " << ans<< endl;

        if (posible(mid, A, B))
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (ans == INT_MAX)
    {
        return -1;
    }

    return ans;
}

int main()
{
    int n, i;
    cin >> n;
    vector<int> A(n);
    int B;

    for (i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cin >> B;

    int ans = books(A, B);
}