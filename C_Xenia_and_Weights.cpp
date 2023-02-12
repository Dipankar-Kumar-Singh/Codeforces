#include <bits/stdc++.h>
using namespace std;

#define t_case   int ttt{}; cin >> ttt;  while (ttt--)
#define FAST  ios_base::sync_with_stdio(0);     cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()

int dfs(vector<int> &weights, vector<int> v, int m, int dif)
{
    if (v.size() == m)
    {
        cout << "YES\n";

        for (auto &x : v)
            cout << x << " ";

        exit(0);
    }

    if (v.empty())
    {
        for(int w : weights)
        {
            vector<int> t {v};
            t.push_back(w);
            dfs(weights, t , m, dif + w);
        }

        return 0;
    }

    for (auto w : weights)
    {

        if (dif >= 10)    return 0;

        if (dif > 0)
        {
            if (w - dif > 0 and v.back() != w)
            {
                vector<int> t = v;
                t.push_back(w);
                dfs(weights, t, m, dif - w);
            }
        }

        else if (dif < 0)
        {
            if (w > abs(dif) and v.back() != w)
            {
                vector<int> t = v;
                t.push_back(w);
                dfs(weights, t, m, w - abs(dif));
            }
        }
    }

    return 0;
}

signed main()
{
    FAST

    string s;
    int m;
    cin >> s >> m;

    vector<int> v;
    vector<int> weights ;
    for(int i = 0 ; i < s.size() ; i++) s[i]== '1' ? weights.push_back(i+1) : void() ;
    dfs(weights, v, m, 0);

    cout << "NO";
}
