#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, q;
	cin >> n >> q;

	vector<int> heights(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> heights[i];
	}

	 vector<int> tastiness(n+1);

	 for(int i = 1; i<=n; i++)
	 {
		 cin>>tastiness[i];
	 }

	int o,b,c;

		while(q--)
		{
			cin>>o>>b>>c;
			if(o==1)
			{
				tastiness[b] = c;
			}
			else
			{
				int f = (b<=c)? 1 : -1;

				int i = b;
				int ans = tastiness[i];

				if(b==c)
				{
					cout<<ans<<endl;
					continue;
				}

				stack<int> seq;
				seq.push(b);
				int h = b;

				for(int i = b+f; (f==1)? (i<=c): (i>=c); i+=f)
				{
					if(heights[i]<heights[h])
					{
						ans+=tastiness[i];
						seq.push(i);
						h = i;
					}
					else
					{
						cout<<endl;
						while(heights[i]>=heights[h] && !seq.empty())
						{
							ans-=tastiness[h];
							cout<<h<<" ";
							seq.pop();

							if(!seq.empty())
							{
								h = seq.top();
							}
							else
							{
								break;
							}
						}

						cout<<endl;

						if(heights[i]<heights[h])
						{
							ans+=tastiness[i];
							seq.push(i);
							h = i;
						}
						else
						{
							ans = -1;
							break;
						}
					}

					cout<<ans<<" ";
				}

				cout<<ans<<endl;
			}
		}
}
