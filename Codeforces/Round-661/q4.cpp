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

        string s;
        cin>>s;

        priority_queue<int> zero;
        priority_queue<int> one;

        vector<int> ans(s.size());

        char last = ' ';

        int o = 0;

        for (int i = 0; i<s.size(); i++) {
            if (s[i]=='0') {
                if (zero.empty()) {
                    o++;
                    ans[i] = o;
                    one.push(-o);
                }
                else {
                    ans[i] = -zero.top();
                    one.push(zero.top());
                    zero.pop();
                }

            }
            else {
                if (one.empty()) {
                    o++;
                    ans[i] = o;
                    zero.push(-o);
                }
                else
                {
                    ans[i] = -one.top();
                    zero.push(one.top());
                    one.pop();
                }
            }
        }

        cout<<o<<endl;

        for (auto an : ans) {
            cout<<an<<" ";
        }

        cout<<endl;
    }
}