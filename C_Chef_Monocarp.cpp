#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
int test = 0 ;


long long hungarian(const vector<vector<long long>>& cost) {
    const long long INF = numeric_limits<long long>::max();
    int n = cost.size(), m = cost[0].size();
    vector<long long> u(n + 1), v(m + 1), dist(m + 1);
    vector<int> p(m + 1), way(m + 1), used(m + 1);
    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        fill(dist.begin(), dist.end(), INF);
        do {
            used[j0] = i;
            int i0 = p[j0], j1 = -1;
            long long delta = INF;
            for (int j = 1; j <= m; ++j) if (used[j] != i) {
                long long cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                if (cur < dist[j]) dist[j] = cur, way[j] = j0;
                if (dist[j] < delta) delta = dist[j], j1 = j;
            }
            for (int j = 0; j < (m) + 1 ; j++)
            {
                if (used[j] == i) u[p[j]] += delta, v[j] -= delta;
                else dist[j] -= delta;
            }
            j0 = j1;
        } while (p[j0] != 0);
        for (int j1; j0; j0 = j1)
            p[j0] = p[j1 = way[j0]];
    }
    
    return -v[0];
}


void solve()
{
    int ans = 0 ; 
    int n ; cin >> n ;
    vector<int> time(n) ; for(auto &t : time ) cin >> t ; 
    for(auto &t : time) t-- ;

    vector<vector<int>> cost(n, vector<int>(2 * n ));

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < 2*n ; j++)
        {
            cost[i][j] = abs(time[i]-j) ;
        }
    }

    int min_cost = hungarian(cost) ;
    cout << min_cost << nl ;
    
}

signed main(){  FAST    TestCases    solve() ; }