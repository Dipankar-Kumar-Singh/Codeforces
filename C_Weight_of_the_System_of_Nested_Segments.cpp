#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  

bool comp(pair<int,int> &p1 , pair<int,int> &p2){
    return p1.second < p2.second ;
}

void solve()
{
    int n ; cin >> n ;
    int m ; cin >> m ;

    vector<pair<int,int>> pt(m);
    map<int,int> loc ;
    int ii = 0 ;

    for(auto &[x,w] : pt )
    {
        cin >> x ; cin >> w ; 
        loc[x] = ++ ii ; 
    }

    sort(all(pt),comp);  // sort by weight 
    pt.assign(pt.begin(),pt.begin()+(int)(2*n)) ;   // only taking first 2n elements 
    sort(all(pt)) ;     // sort by x coordinate 

    int ans = 0 ; 
    for(auto &[x,w] : pt) ans += w ;

    cout << ans << nl ;

    for(int i = 0 ; i < n ; i++)
    {
        int p1 = pt[i].first , p2 = pt[2*n-1-i].first ;
        cout << loc[p1] << " " << loc[p2] << nl ;
    }
}

signed main()
{   FAST  

    TestCases  
    solve() ;  
}

