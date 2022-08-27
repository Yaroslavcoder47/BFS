#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> v(100000);
bool used[100000];
int d[100000];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 0; i < m; ++i)
        d[i] = 100000;

    int start = 0;
    used[start] = true;
    d[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int r = q.front();
        q.pop();
        for(int i = 0; i < (int)v[r].size(); ++i)
        {
            int to = v[r][i];
            if(used[to])
                continue;
            q.push(to);
            used[to] = true;
            d[to] = d[r] + 1;
        }
    }

    for(int i = 0; i < n; ++i)
        cout << d[i] << " ";
    return 0;
}
