#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);


signed main()
{
    FAST ;
    int n,m ; cin >> n >> m ;
    vector<int> eng(n) ; for(int &i:eng) cin >> i ;
    int ans = 0 ;
    for(int i = 0 ; i < m ; i++){
        int v , u ; 
        cin >> v >> u ;
        ans += min(eng[--u],eng[--v]) ;
    }
    
    cout << ans ;
}

