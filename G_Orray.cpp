#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
int test = 0 ;
void solve()
{
    int n;
    cin >> n;

    int req = 0;
    vector<int> v(n);
    for (auto &x : v)
    {
        cin >> x;
        req |= x ;
    }

    vector<int> vis(n,-1) ;

    int curr = 0 ;
    int itration = 0 ;
    while(curr != req)
    {
        int best = 0  ;
        int ind = 0 ;
        for(int i  = 0 ; i < n ;i++)
        {
            if(vis[i] == -1)
            {
                int now = v[i] | curr ;
                if(now >= best)
                {
                    best = now ;
                    ind = i ;
                }
            }   
        }

        curr = best ;
        vis[ind] = itration ;
        itration++ ;
    }

    vector<pair<int,int>> vec ;

    for(int i = 0 ; i < n ; i++)
    {
        if(vis[i] != -1)
            vec.push_back({vis[i], v[i]});
    }

    sort(all(vec)) ;
    vector<int> result ;
    for(auto [x , y] : vec)
    {
        result.push_back(y) ;
    }

    for(int i =0  ; i < n; i++) if(vis[i] == -1) result.push_back(v[i]) ;
    for(auto x : result) cout << x << " " ;
    cout << nl ;
}

signed main(){  FAST    TestCases    solve() ; }