#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,x;
        cin >> n >> x;

        vector<int> population(n);

        for(int i = 0; i<n; i++)
        {
          cin>>population[i];
        }

        sort(population.begin(), population.end());

        int days = 0;
        int completed = 0;
        int i = 0;
        int y;
        int f;

        for(i = 0; i<n; i++)
        {
          while(i<n && population[i]*2<x)
          {
            i++;
          }

          if(i>=n)
          {
            break;
          }

          // cout<<"i = "<<i<<" population[i] = "<<population[i]<<" x = "<<x<<endl;

          days++;
          y = population[i];
          // f = 1;
          while(x<population[i])
          {
            days++;
            // population[i] = min(y, 2*(population[i]-x));
            x = x*2;
            // if(population[i]*2<x)
            // {
            //   f = 1;
            //   days--;
            //   break;
            // }
          }

          // if(f)
          // {
          //   continue;
          // }

          completed++;

          x = 2*population[i];

          // cout<<"days = "<<days<<" completed = "<<completed<<" x = "<<x<<endl;
          // cout<<endl;
        }

        days+=n-completed;

        cout << days << endl;
    }
}
