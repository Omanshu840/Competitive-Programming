bool sortcol(const vector<int> &v1, const vector<int> &v2)
{
    return v1[2] < v2[2];
}

int find(int x, int link[])
{
    while (x != link[x])
        x = link[x];
    return x;
}

bool same(int a, int b, int link[])
{
    return find(a, link) == find(b, link);
}

void unite(int a, int b, int link[], int size[])
{
    a = find(a, link);
    b = find(b, link);
    if (size[a] < size[b])
        swap(a, b);
    size[a] += size[b];
    link[b] = a;
}

int Solution::solve(int A, vector<vector<int>> &B)
{

    sort(B.begin(), B.end(), sortcol);

    int link[A + 1];
    int size[A + 1];

    int i;

    for (int i = 1; i <= A; i++)
        link[i] = i;
    for (int i = 1; i <= A; i++)
        size[i] = 1;

    int ans = 0;

    for (i = 0; i < B.size(); i++)
    {
        // cout<<ans<<endl;
        if (!(same(B[i][0], B[i][1], link)))
        {
            unite(B[i][0], B[i][1], link, size);
            ans += B[i][2];
        }
    }

    return ans;
}
