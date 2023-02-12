#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 


void solve(int& __case__)
{
    multiset<int> points ;

    int n , c ; 
    cin >> n >> c ;

    vector<int> v(n) ;
    for(auto &x : v) cin >> x ;

    for(int i = 0 ; i < n; i++)
    {
        int loc = i + 1;
        int cost = v[i];
        points.insert(loc + cost);
    }

    int ans = 0 ;

    while(points.size() and c )
    {
        auto it = points.begin() ;
        if(it == points.end()) break;

        int cost = *it ;
        if(cost > c) break;
        else 
        {
            c -= cost ;
            ans++ ;
        }

        points.erase(it) ;
    }


    cout << ans << nl ;

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
