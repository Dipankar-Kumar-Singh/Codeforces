#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;
int INF = numeric_limits<int>::max();

int f(vector<int> &v)
{
    int d = INF ;
    int n = v.size() ;
    for(int i = 1 ; i < n;  i++ )
    {
        d = min(d , abs(v[i] - v[i-1]) ) ;
    }   
    return d ;
}

void solve()
{
    int n;   cin >> n;
    vector<int> v ;

    vector<int> vis(n+1) ;

    if (n == 3)
    {
        cout << "1 2 3" << nl;
        return;
    }

    int adder = n/2 ;
    if(n&1) adder++ ;

    vector<pair<int,int>> vec ;

    for(int i = 1 ; i <= n/2 ; i++)
    {
            int x = i ;
            int y =i + adder ;
            // v.push_back(x) , v.push_back(y) ;
            vis[x] = vis[y] = 1 ;
            vec.push_back({x,y}) ;
    }

    if(n%2==0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                v.push_back(i);
        }

        for (int i = vec.size() -1 ; i >= 0 ; i--)
        {
            auto [x, y] = vec[i];
            v.push_back(x), v.push_back(y);
        }
    }

    else 
    {
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                v.push_back(i);
        }

        for(auto [x, y] : vec) 
        {
            v.push_back(x), v.push_back(y);
        }
    }

    // cout << f(v) << nl ;
    for(auto x : v) cout << x << " " ; cout << nl ;

    // cout << nl ;

}
signed main(){   FAST      TestCases      solve() ;  }



