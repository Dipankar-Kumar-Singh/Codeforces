#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

bool isPossible(vector<int> a , int time)
{
    int layer = a.size() ;
    if (time < layer)
        return 0;

    int time_rem = max(time - layer,0LL) ;
    int time_used = layer ;

    for(int i = 0 ; i < layer; i++)
    {
        a[i] -= (layer - i + time_rem) ;
        a[i] = max(a[i],0LL) ; 
    }

    int remaningSum = 0 ;
    for(auto &x : a) remaningSum += x ;
    return (remaningSum <= time_rem) ;
}

void solve()
{

   int n ; cin >> n ;
   map<int,int> m ;

    vector<int> par(n+1) ;

    for(int i = 2 ; i <= n ; i++ ) cin >> par[i] , m[par[i]]++ ;
    m[0]++ ;

    int mx  = 0 ;
    for(auto &[par,sz] : m) mx = max(sz,mx) ;
    vector<int> d ;
    for (auto [__a, fr] : m)  d.push_back(fr) ;
    
    sort(all(d));
    reverse(all(d));

    int l = 0, r = LONG_LONG_MAX;
    while (r - l > 1)
    {
        int mid  = (l+r)/2 ;
        (isPossible(d,mid) ? r : l ) = mid ; 
    }

    cout << r << "\n" ; return ;   
}

signed main()
{   FAST  
    TestCases  
    solve() ;  
}

