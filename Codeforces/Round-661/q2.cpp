#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;

        vector<int> a(n);
        vector<int> b(n);

        int lowa = INT_MAX, lowb = INT_MAX;

        for (int i = 0; i<n; i++)
        {
            cin>>a[i];
            lowa = min(lowa, a[i]);
        }

        for (int i = 0; i<n; i++)
        {
            cin>>b[i];
            lowb = min(lowb, b[i]);
        }

        long long ans = 0;

        for (int i = 0; i<n; i++)
        {
            if (a[i]-lowa==b[i]-lowb) {
                ans+=a[i]-lowa;
            }
            else if (a[i]-lowa>b[i]-lowb) {
                ans+=a[i]-lowa;
            }
            else
            {
                ans+=b[i]-lowb;
            }

        }

        cout<<ans<<endl;
    }
}