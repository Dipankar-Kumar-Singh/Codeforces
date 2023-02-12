#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

int const INF = 1e18 ;

void solve(int& __case__)
{
    int n, m , d ; 
    cin >> n >> m >> d ; 

    map<int,int> loc ; 

    vector<int> v(n) ;
    for(auto &x : v) 
        cin >> x ;

    for(int i = 0 ; i < n; i++)
        loc[v[i]] = i  ;

    vector<int> a(m) ;
    for(auto &x : a) 
        cin >> x ;

    
    int best = INF ;

    for(int i = 0 ; i + 1 < m ; i++)
    {
        int x = a[i];
        int y = a[i + 1];

        int locx = loc[x] ;
        int locy = loc[y] ;

        bool c1 = locx < locy ;
        bool c2 = locy <= locx + d ;

        if(c1 == 0 or c2 == 0) {
            cout << 0 << nl ;
            return ;
        }

        int move1 = locy - locx ;
        int move2 = INF ;

        int reqGap = (d  + 1 ) - (locy - locx) ;

        if(n > d + 1 )
            move2 = reqGap ;

        best = min({best , move1 ,  move2}) ;
    }

    cout << best << nl ;

    
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
