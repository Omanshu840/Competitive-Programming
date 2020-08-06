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

        int sum = 0;

        for (int i = 0; i<n; i++)
        {
            cin>>a[i];
            sum+=a[i];
        }

        sort(a.begin(), a.end());

        int ans = 0;

        for (int i = 0; i<n; i++)
        {
            for (int l = n-1; l>=0; l--)
            {
                int j = i;
                int k = l;

                int sum = a[j]+a[k];
                int count = 0;

                while (j<k)
                {
                    if (a[j]+a[k]==sum) {
                        count++;
                        j++;
                        k--;
                    }
                    else if (a[j]+a[k]<sum) {
                        j++;
                    }
                    else {
                        k--;
                    }

                }

                ans = max(ans, count);
            }
        }

        cout<<ans<<endl;

    }
}